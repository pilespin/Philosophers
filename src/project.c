/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 14:47:59 by pilespin          #+#    #+#             */
/*   Updated: 2015/10/26 12:01:46 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

int				main(void)
{
	double		time_start;

	ft_go_struct();
	time_start = ft_utime();
	while (1)
	{
		if (NB_PHILOSOPHERS == 7)
			ft_go_sdl();
		ft_draw_shell();
		if (ft_utime() > (time_start + TIMEOUT) && !g_e->go_to_dead)
		{
			g_e->go_to_dance = 1;
			ft_putstrc(6, 0, "Now, it is time... To DAAAAAAAANCE !!!\n");
			ft_event();
		}
		if (ft_if_one_is_dead())
		{
			g_e->go_to_dead = 1;
			ft_putstrc(1, 0, "Now, it is time... To DIIIIIIIIIIE !!!\n");
			ft_event();
		}
		usleep(100000);
		ft_remove_life();
	}
	return (0);
}

void			ft_remove_life(void)
{
	int			i;

	if (g_e->go_to_dead)
		return ;
	if (g_e->time_start == 0)
		g_e->time_start = ft_utime();
	if (g_e->time_start + (WAIT / 1000000) < ft_utime())
	{
		g_e->iter++;
		g_e->time_start = ft_utime();
		i = -1;
		while (++i < NB_PHILOSOPHERS)
		{
			if (P[i]->life > 0)
				P[i]->life--;
		}
	}
}

int				ft_if_one_is_dead(void)
{
	int			i;

	i = -1;
	while (++i < NB_PHILOSOPHERS)
	{
		if (P[i]->life <= 0)
		{
			P[i]->status = DEAD;
			return (1);
		}
	}
	return (0);
}

int				ft_get_n1(int n)
{
	int			n1;

	n1 = n + 1;
	if (!P[n1])
		n1 = 0;
	return (n1);
}
