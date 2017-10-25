/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 14:47:59 by pilespin          #+#    #+#             */
/*   Updated: 2015/10/24 17:04:36 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

void	ft_algo_eat(int n, int n1)
{
	P[n]->old_status = P[n]->status;
	P[n]->status = EAT;
	usleep(EAT_T * WAIT);
	P[n]->life = MAX_LIFE;
	pthread_mutex_unlock(&P[n]->mrod);
	pthread_mutex_unlock(&P[n1]->mrod);
}

void	ft_algo_think(int n)
{
	P[n]->old_status = P[n]->status;
	P[n]->status = THINK;
	usleep(THINK_T * WAIT);
}

void	ft_algo_rest(int n)
{
	P[n]->old_status = P[n]->status;
	P[n]->status = REST;
	usleep(REST_T * WAIT);
}
