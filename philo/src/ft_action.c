/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:53:07 by graiolo           #+#    #+#             */
/*   Updated: 2023/07/16 01:19:19 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_eat(t_philo *philos)
{
	pthread_mutex_lock(philos->r_fork);
	ft_message(TAKE_FORKS, philos);
	pthread_mutex_lock(philos->l_fork);
	ft_message(TAKE_FORKS, philos);
	ft_message(EATING, philos);
	pthread_mutex_lock(&philos->table->looc);
	philos->n_eat -= 1;
	philos->last_meal = ft_get_time();
	pthread_mutex_unlock(&philos->table->looc);
	ft_usleep(philos->table->t_eat);
	pthread_mutex_unlock(philos->r_fork);
	pthread_mutex_unlock(philos->l_fork);
}

void	*ft_routine(void *elem)
{
	t_philo		*philos;

	philos = (t_philo *)(elem);
	while (1)
	{
		pthread_mutex_lock(&philos->table->looc);
		if (!(philos->table->dead != true && philos->n_eat != 0))
		{
			pthread_mutex_unlock(&philos->table->looc);
			return (NULL);
		}
		pthread_mutex_unlock(&philos->table->looc);
		ft_eat(philos);
		ft_message(SLEEPING, philos);
		ft_usleep(philos->table->t_sleep);
		ft_message(THINKING, philos);
	}
	return (NULL);
}

void	ft_bigbrother(t_container *container)
{
	size_t	i;

	while (1)
	{
		pthread_mutex_lock(&container->table->looc);
		if (!container->philos->n_eat)
		{
			pthread_mutex_unlock(&container->table->looc);
			return ;
		}
		pthread_mutex_unlock(&container->table->looc);
		i = 0;
		while (i < container->table->n_philo)
		{
			ft_check(&container->philos[i]);
			if (container->table->dead == true)
				return ;
			i++;
		}
		ft_usleep(1);
	}
}

void	ft_check(t_philo *philos)
{
	static bool	dead;

	if (dead == false && ft_get_time() - philos->last_meal
		> philos->table->t_die)
	{
		dead = true;
		ft_message(DIED, philos);
	}
}
