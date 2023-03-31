/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:32:41 by graiolo           #+#    #+#             */
/*   Updated: 2023/03/31 12:36:34 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <fcntl.h>

# define MALL_ERR "\e[1;31mERROR WHILE CREATING MALLOC\e[0m"
# define MTX_ERR "\e[1;31mERROR WHILE CREATING MUTEX\e[0m"
# define TH_ERR "\e[1;31mERROR WHILE CREATING THREAD\e[0m"
# define FR_ERR "\e[1;31mERROR WHILE CREATING FORK\e[0m"
# define INV_ERR "\e[1;31mERROR INVALID PARAM\e[0m"

# define TAKE_FORKS "\e[1;37mhas taken a fork\e[0m"
# define THINKING "\e[1;32mis thinking\e[0m"
# define SLEEPING "\e[1;34mis sleeping\e[0m"
# define EATING "\e[1;35mis eating\e[0m"
# define DIED "\e[1;31mdied\e[0m"

typedef struct s_table	t_table;

typedef struct s_philo
{
	useconds_t	last_meal;
	size_t		id;
	size_t		n_eat;
	pid_t		pid;
	t_table		*table;
}	t_philo;

typedef struct s_table
{
	useconds_t	t_start;
	size_t		n_philo;
	size_t		n_eat;
	size_t		t_die;
	size_t		t_eat;
	size_t		t_sleep;
	sem_t		*fork;
	sem_t		*print;
	sem_t		*stop;
	sem_t		*end;
}	t_table;

typedef struct s_container
{
	t_philo	*philos;
	t_table	*table;
}	t_container;

//-------------------------------------------------------------------//
useconds_t	ft_get_time(void);
void		ft_usleep(useconds_t time);
//-------------------------------------------------------------------//
void		ft_allocate_init(t_container **container,
				char **argv, int argc);
void		ft_allocate_container(t_container **cp_container);
void		ft_destroy_sem(t_container *container);
void		ft_destroy(t_container *conteiner);
//-------------------------------------------------------------------//
void		ft_fork(t_container *container);
void		*ft_check_death(void *old_philo);
void		ft_eat(t_philo *philo);
void		ft_routine(t_philo *philo);
void		*ft_kill(void *old_container);
//-------------------------------------------------------------------//
void		ft_allocate_table(t_container *conteiner);
void		ft_init_table(t_container *conteiner, char **argv, int argc);
void		ft_init_sem(t_container *container);
void		ft_allocate_philo(t_container *conteiner);
void		ft_init_philo(t_container *conteiner);
//-------------------------------------------------------------------//
void		ft_message(char *str, t_philo *philos);
void		ft_message_error(char *str, t_container *conteiner);
//-------------------------------------------------------------------//
void		ft_routine(t_philo *philo);
void		ft_eat(t_philo *philo);
//-------------------------------------------------------------------//
int			ft_patoi(char *arg, t_container *container);
int			ft_atoi(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);

#endif
