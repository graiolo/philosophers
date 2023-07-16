/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:49:51 by graiolo           #+#    #+#             */
/*   Updated: 2023/07/16 03:00:01 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_fork(t_container *container)
{
	size_t	i;

	i = 0;
	while (i < container->table->n_philo)
	{
		sem_wait(container->table->looc);
		container->philos[i].pid = fork();
		sem_post(container->table->looc);
		if (container->philos[i].pid == -1)
			ft_message_error(FR_ERR, container);
		if (container->philos[i].pid == 0)
		{
			ft_routine(&container->philos[i]);
			ft_destroy(container);
			exit (0);
		}
		i++;
	}
	i = -1;
	while (++i < container->table->n_philo)
		waitpid(container->philos[i].pid, NULL, 0);
}

void	*ft_check_death(void *old_philo)
{
	t_philo	*philo;

	philo = (t_philo *)old_philo;
	while (1)
	{	
		sem_wait(philo->table->looc);
		if (!(true && philo->n_eat != 0))
		{
			sem_post(philo->table->looc);
			return (NULL);
		}
		if (ft_get_time() - philo->last_meal > philo->table->t_die)
		{
			ft_message(DIED, philo);
			sem_post(philo->table->looc);
			return (NULL);
		}
		sem_post(philo->table->looc);
		ft_usleep(1);
	}
	return (NULL);
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->table->fork);
	ft_message(TAKE_FORKS, philo);
	sem_wait(philo->table->fork);
	ft_message(TAKE_FORKS, philo);
	ft_message(EATING, philo);
	sem_wait(philo->table->looc);
	philo->n_eat -= 1;
	philo->last_meal = ft_get_time();
	sem_post(philo->table->looc);
	ft_usleep(philo->table->t_eat);
	sem_post(philo->table->fork);
	sem_post(philo->table->fork);
}

void	ft_routine(t_philo *philo)
{
	pthread_t	death;

	ft_usleep(philo->id % 2 * 2);
	pthread_create(&death, NULL, ft_check_death, (void *)philo);
	while (philo->n_eat != 0)
	{
		ft_eat(philo);
		ft_message(SLEEPING, philo);
		ft_usleep(philo->table->t_sleep);
		ft_message(THINKING, philo);
	}
	pthread_join(death, NULL);
}

void	*ft_kill(void *old_container)
{
	t_container	*container;
	size_t		i;

	i = 0;
	container = (t_container *)old_container;
	sem_wait(container->table->end);
	sem_wait(container->table->looc);
	while (i < container->table->n_philo)
		kill(container->philos[i++].pid, SIGKILL);
	sem_post(container->table->looc);
	sem_post(container->table->end);
	return (NULL);
}
