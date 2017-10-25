/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 22:51:58 by pilespin          #+#    #+#             */
/*   Updated: 2015/10/26 14:04:17 by abou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_philo
{
	int				nb;
	int				life;
	int				status;
	int				old_status;
	pthread_mutex_t	mrod;
}					t_philo;

typedef struct		s_st
{
	pthread_mutex_t	mutex;
	t_philo			**philo;
	pthread_t		*thread;
	int				current;
	int				iter;
	int				go_to_dance;
	int				go_to_dead;
	double			time_start;
	void			*rend;
	void			*dead;
	void			*eat;
	void			*sleep;
	void			*think;
	void			*dance;
	void			*dance2;
	void			*dance3;
	void			*text;
	void			*textv;
	void			*textr;
	void			*think_m;
	void			*sleep_m;
	void			*eat_m;
	void			*dead_m;
	void			*eat_t;
	void			*sleep_t;
	void			*think_t;
	void			*dead_t;
}					t_st;

#endif
