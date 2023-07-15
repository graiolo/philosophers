/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:15:07 by graiolo           #+#    #+#             */
/*   Updated: 2023/07/16 01:33:53 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
//--------------------------------------------//
# define TH_ERR "\e[1;31mERROR WHILE CREATING THREADS\e[0m"
# define JOIN_ERR "\e[1;31mERROR WHILE JOINING THREADS\e[0m"
# define MALL_ERR "\e[1;31mERROR WHILE CREATING MALLOC\e[0m"
# define MTX_ERR "\e[1;31mERROR WHILE CREATING MUTEX\e[0m"
# define INV_ERR "\e[1;31mERROR INVALID PARAM\e[0m"
//--------------------------------------------//
# define TAKE_FORKS "\e[1;37mhas taken a fork\e[0m"
# define THINKING "\e[1;32mis thinking\e[0m"
# define SLEEPING "\e[1;34mis sleeping\e[0m"
# define EATING "\e[1;35mis eating\e[0m"
# define DIED "\e[1;31mdied\e[0m"

typedef struct s_table	t_table;

typedef struct s_philo
{
	size_t				id;
	size_t				n_eat;
	useconds_t			last_meal;
	pthread_t			*philo;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	t_table				*table;
}	t_philo;

typedef struct s_table
{
	size_t			n_philo;
	size_t			n_eat;
	size_t			t_die;
	size_t			t_eat;
	size_t			t_sleep;
	useconds_t		t_start;
	bool			dead;
	pthread_mutex_t	looc;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
}	t_table;

typedef struct s_container
{
	t_philo		*philos;
	t_table		*table;
}	t_container;

//-------------------------------------------------------------------//
useconds_t		ft_get_time(void);
void			ft_usleep(useconds_t time);
//-------------------------------------------------------------------//
void			ft_allocate_init(t_container **container,
					char **argv, int argc);
void			ft_allocate_container(t_container **cp_container);
void			ft_destroi(t_container *conteiner);
//-------------------------------------------------------------------//
void			ft_allocate_table(t_container *conteiner);
void			ft_init_table(t_container *conteiner, char **argv, int argc);
void			ft_allocate_philo(t_container *conteiner);
void			ft_init_philo(t_container *conteiner);
void			ft_init_fork(t_container *conteiner);
//-------------------------------------------------------------------//
void			ft_message(char *str, t_philo *philos);
void			ft_message_error(char *str, t_container *conteiner);
//-------------------------------------------------------------------//
void			ft_eat(t_philo *philos);
void			*ft_routine(void *elem);
void			ft_check(t_philo *philos);
void			ft_bigbrother(t_container *container);
//-------------------------------------------------------------------//
void			ft_solo(t_container *container);
void			*ft_solo_routine(void *elem);
//-------------------------------------------------------------------//
int				ft_patoi(char *arg, t_container *container);
int				ft_atoi(const char *nptr);
int				ft_strcmp(const char *s1, const char *s2);

#endif