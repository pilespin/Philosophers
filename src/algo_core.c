/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 17:36:11 by abou              #+#    #+#             */
/*   Updated: 2015/10/26 13:34:56 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

void			ft_algo_check_eat(int n, int n1)
{
	int			left;
	int			right;

	left = 0;
	right = 0;
	if (!pthread_mutex_trylock(&P[n]->mrod))
		left = 1;
	if (!pthread_mutex_trylock(&P[n1]->mrod))
		right = 1;
	if (left && right)
		ft_algo_eat(n, n1);
	if ((right && !left) || (left && !right))
	{
		if (left)
			pthread_mutex_unlock(&P[n]->mrod);
		if (right)
			pthread_mutex_unlock(&P[n1]->mrod);
	}
}

void			ft_algo_check_think(int n, int n1)
{
	if (!pthread_mutex_trylock(&P[n]->mrod))
	{
		pthread_mutex_unlock(&P[n]->mrod);
		ft_algo_think(n);
	}
	else if (!pthread_mutex_trylock(&P[n1]->mrod))
	{
		pthread_mutex_unlock(&P[n1]->mrod);
		ft_algo_think(n);
	}
}

void			*ft_start_philo(void *nb)
{
	int			n;
	int			n1;

	(void)nb;
	n = g_e->current++;
	n1 = ft_get_n1(n);
	pthread_mutex_init(&P[n]->mrod, NULL);
	while (1)
	{
		if (g_e->go_to_dead || g_e->go_to_dance)
		{
			return (NULL);
		}
		if (P[n]->status == THINK)
			ft_algo_check_eat(n, n1);
		else if (P[n]->status == EAT)
			ft_algo_rest(n);
		else if (P[n]->status == REST)
			ft_algo_check_think(n, n1);
	}
	return (NULL);
}

void			ft_create_thread(void)
{
	int			i;

	g_e->thread = (pthread_t *)malloc(sizeof(pthread_t) * NB_PHILOSOPHERS + 1);
	g_e->thread[NB_PHILOSOPHERS] = NULL;
	i = -1;
	while (++i < NB_PHILOSOPHERS)
	{
		pthread_create(&g_e->thread[i], NULL, ft_start_philo, NULL);
	}
}
