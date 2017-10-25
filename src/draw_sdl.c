/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 14:47:59 by pilespin          #+#    #+#             */
/*   Updated: 2015/10/26 14:29:30 by abou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

void	ft_sdl_init_bis(void)
{
	SDL_Window		*screen;

	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_CreateWindow("Philosophers", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOW_X, SDL_WINDOW_Y,
	SDL_WINDOW_SHOWN);
	g_e->rend = SDL_CreateRenderer(screen, -1,
	SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
}

void	*ft_sdl_init(void)
{
	ft_sdl_init_bis();
	g_e->eat = SDL_LoadBMP("img/eat.bmp");
	g_e->dead = SDL_LoadBMP("img/dead.bmp");
	g_e->sleep = SDL_LoadBMP("img/sleep.bmp");
	g_e->think = SDL_LoadBMP("img/think.bmp");
	g_e->dance = SDL_LoadBMP("img/dance.bmp");
	g_e->dance2 = SDL_LoadBMP("img/dance2.bmp");
	g_e->dance3 = SDL_LoadBMP("img/dance3.bmp");
	g_e->text = SDL_LoadBMP("img/text.bmp");
	g_e->textv = SDL_LoadBMP("img/textv.bmp");
	g_e->textr = SDL_LoadBMP("img/textr.bmp");
	g_e->think_m = SDL_LoadBMP("img/think_m.bmp");
	g_e->sleep_m = SDL_LoadBMP("img/sleep_m.bmp");
	g_e->eat_m = SDL_LoadBMP("img/eat_m.bmp");
	g_e->dead_m = SDL_LoadBMP("img/dead_m.bmp");
	g_e->eat_t = SDL_LoadBMP("img/eat_t.bmp");
	g_e->think_t = SDL_LoadBMP("img/think_t.bmp");
	g_e->sleep_t = SDL_LoadBMP("img/sleep_t.bmp");
	g_e->dead_t = SDL_LoadBMP("img/dead_t.bmp");
	SDL_SetRenderDrawColor(g_e->rend, 175, 95, 255, 255);
	return (NULL);
}

void	ft_draw_img_renderer(SDL_Renderer *renderer, SDL_Surface *img,
	int x, int y)
{
	SDL_Texture	*texture;
	SDL_Rect	dest;

	texture = SDL_CreateTextureFromSurface(renderer, img);
	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(renderer, texture, NULL, &dest);
	SDL_DestroyTexture(texture);
}

void	*ft_gim(int status)
{
	if (status == EAT)
		return (g_e->eat);
	if (status == REST)
		return (g_e->sleep);
	if (status == THINK)
		return (g_e->think);
	if (status == DEAD)
		return (g_e->dead);
	else
		return (NULL);
}

void	ft_draw_sdl(void)
{
	SDL_RenderClear(g_e->rend);
	ft_draw_img_renderer(g_e->rend, ft_gim(P[0]->status), 50, 200);
	ft_draw_img_renderer(g_e->rend, ft_gim(P[1]->status), 150, 350);
	ft_draw_img_renderer(g_e->rend, ft_gim(P[2]->status), 350, 400);
	ft_draw_img_renderer(g_e->rend, ft_gim(P[3]->status), 525, 275);
	ft_draw_img_renderer(g_e->rend, ft_gim(P[4]->status), 525, 100);
	ft_draw_img_renderer(g_e->rend, ft_gim(P[5]->status), 350, 25);
	ft_draw_img_renderer(g_e->rend, ft_gim(P[6]->status), 150, 50);
	ft_draw_img_renderer(g_e->rend, g_e->eat_m, 850, 30);
	ft_draw_img_renderer(g_e->rend, g_e->sleep_m, 850, 130);
	ft_draw_img_renderer(g_e->rend, g_e->think_m, 850, 230);
	if (g_e->go_to_dead)
		ft_draw_img_renderer(g_e->rend, g_e->dead_m, 850, 330);
	if (g_e->go_to_dance)
		ft_draw_sdl_bis(g_e);
	if (ft_random(0, 5) || !g_e->go_to_dance)
	{
		ft_draw_img_renderer(g_e->rend, g_e->eat_t, 800, 15);
		ft_draw_img_renderer(g_e->rend, g_e->sleep_t, 800, 115);
		ft_draw_img_renderer(g_e->rend, g_e->think_t, 800, 215);
		if (g_e->go_to_dead)
			ft_draw_img_renderer(g_e->rend, g_e->dead_t, 800, 315);
	}
	SDL_RenderPresent(g_e->rend);
}
