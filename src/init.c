/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 14:47:59 by pilespin          #+#    #+#             */
/*   Updated: 2015/10/26 14:15:10 by abou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

void	ft_go_struct(void)
{
	ft_init_struct();
	ft_create_thread();
	if (NB_PHILOSOPHERS == 7)
		ft_sdl_init();
}

void	ft_go_sdl(void)
{
	ft_sdl_event();
	ft_draw_sdl();
}

void	ft_event(void)
{
	int			i;

	while (1)
	{
		i = -1;
		while (g_e->thread && ++i < NB_PHILOSOPHERS)
		{
			pthread_detach(g_e->thread[i]);
		}
		g_e->thread = NULL;
		if (NB_PHILOSOPHERS == 7)
		{
			ft_go_sdl();
			ft_sdl_event();
		}
		else
			exit(0);
		usleep(100000);
	}
}

void	ft_init_struct(void)
{
	int	i;

	g_e = (t_st *)malloc(sizeof(t_st));
	pthread_mutex_init(&g_e->mutex, NULL);
	P = (t_philo **)malloc(sizeof(t_philo *) * (NB_PHILOSOPHERS + 1));
	g_e->current = 0;
	g_e->time_start = 0;
	g_e->go_to_dance = 0;
	g_e->go_to_dead = 0;
	i = -1;
	while (++i < NB_PHILOSOPHERS)
	{
		P[i] = (t_philo *)malloc(sizeof(t_philo));
		P[i]->nb = i;
		P[i]->life = MAX_LIFE;
		P[i]->status = THINK;
		P[i]->old_status = THINK;
	}
	P[i] = NULL;
}
