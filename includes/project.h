/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:53:20 by pilespin          #+#    #+#             */
/*   Updated: 2015/10/26 15:54:21 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include "../libft/libft.h"
# include <struct.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <SDL2/SDL.h>

# define NB_PHILOSOPHERS 7
# define MAX_LIFE 10
# define EAT_T 1
# define REST_T 1
# define THINK_T 1
# define TIMEOUT 10

# define EAT 10
# define REST 20
# define THINK 30
# define DEAD 40
# define WAIT 1000000

# define SDL_WINDOW_X 950
# define SDL_WINDOW_Y 600

# define P g_e->philo

t_st	*g_e;

void	*ft_start_philo(void *nb);
void	ft_init_struct(void);

void	ft_draw_img_renderer(SDL_Renderer *renderer, SDL_Surface *img, \
		int x, int y);
void	ft_draw_philo_shell(void);
void	ft_draw_sdl_bis(t_st *g_e);

void	ft_sdl_init_bis(void);
void	ft_draw_shell_bis(int i);
void	ft_draw_shell(void);
void	ft_draw_sdl(void);

void	ft_go_struct(void);
void	ft_go_sdl(void);
void	ft_event(void);
void	ft_sdl_event(void);
void	*ft_sdl_init(void);
void	*ft_gim(int status);

void	ft_create_thread(void);
int		ft_get_n1(int n);
int		ft_if_one_is_dead(void);
void	ft_remove_life(void);

void	ft_algo_philo(int n, int n1);
void	ft_algo_eat(int n, int n1);
void	ft_algo_think(int n);
void	ft_algo_rest(int n);

void	ft_algo_check_eat(int n, int n1);
void	ft_algo_check_think(int n, int n1);

#endif
