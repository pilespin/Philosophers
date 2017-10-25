/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 14:47:59 by pilespin          #+#    #+#             */
/*   Updated: 2015/10/26 14:29:18 by abou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

void	ft_draw_sdl_bis(t_st *g_e)
{
	int	r;

	r = ft_random(1, 3);
	if (r == 1)
		ft_draw_img_renderer(g_e->rend, g_e->dance, 300, 170);
	else if (r == 2)
		ft_draw_img_renderer(g_e->rend, g_e->dance2, 300, 170);
	else if (r == 3)
		ft_draw_img_renderer(g_e->rend, g_e->dance3, 300, 170);
	r = ft_random(1, 3);
	if (r == 1)
		ft_draw_img_renderer(g_e->rend, g_e->text, 175, 535);
	else if (r == 2)
		ft_draw_img_renderer(g_e->rend, g_e->textv, 175, 535);
	else if (r == 3)
		ft_draw_img_renderer(g_e->rend, g_e->textr, 175, 535);
}

void	ft_sdl_event(void)
{
	SDL_Event	user_event;

	if (SDL_PollEvent(&user_event))
	{
		if ((user_event.type == SDL_KEYDOWN && user_event.key.keysym.sym == \
SDLK_ESCAPE) || user_event.type == SDL_QUIT)
		{
			exit(0);
		}
	}
}

void	ft_draw_shell(void)
{
	system("clear");
	pthread_mutex_lock(&g_e->mutex);
	ft_draw_philo_shell();
	pthread_mutex_unlock(&g_e->mutex);
}

void	ft_draw_shell_bis(int i)
{
	if (P[i]->life < 10)
		ft_putstr(" ");
	if (P[i]->status == DEAD)
		ft_putstrc(0, 1, " DEAD  ");
	else if (P[i]->status == REST)
		ft_putstrc(0, 1, " Rest  ");
	else if (P[i]->status == EAT)
		ft_putstrc(0, 3, "  Eat  ");
	else if (P[i]->status == THINK)
		ft_putstrc(0, 2, " Think ");
	ft_putstr(" ");
	ft_printf("\n");
}

void	ft_draw_philo_shell(void)
{
	int		i;

	ft_printf("  Name     Life    Status\n");
	i = -1;
	while (++i < NB_PHILOSOPHERS)
	{
		ft_printf("Philo %d ", P[i]->nb + 1);
		if (P[i]->status == DEAD)
		{
			ft_putstrc(0, 1, " DEAD  ");
			ft_putstrc(0, 1, ft_itoa(P[i]->life));
			ft_putstrc(0, 1, " ");
			ft_putstr(" ");
		}
		else
		{
			ft_putstrc(0, 2, " ALIVE ");
			ft_putstrc(0, 2, ft_itoa(P[i]->life));
			ft_putstrc(0, 2, " ");
			ft_putstr(" ");
		}
		ft_draw_shell_bis(i);
	}
}
