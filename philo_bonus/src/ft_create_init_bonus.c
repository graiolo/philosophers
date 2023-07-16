/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_init_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:49:55 by graiolo           #+#    #+#             */
/*   Updated: 2023/07/16 02:32:02 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_allocate_table(t_container *container)
{
	container->table = (t_table *)malloc(sizeof(t_table));
	if (container->table == NULL)
		ft_message_error(MALL_ERR, container);
	container->table->fork = NULL;
	container->table->print = NULL;
	container->table->stop = NULL;
	container->table->end = NULL;
}

void	ft_allocate_philo(t_container *container)
{
	container->philos = (t_philo *)malloc(sizeof(t_philo)
			* container->table->n_philo);
	if (container->philos == NULL)
		ft_message_error(MALL_ERR, container);
	container->philos->table = NULL;
}

void	ft_init_table(t_container *container, char **argv, int argc)
{
	t_table			*table;
	size_t			id;

	id = 0;
	table = container->table;
	table->t_start = ft_get_time();
	table->n_philo = ft_patoi(argv[1], container);
	table->t_die = ft_patoi(argv[2], container);
	table->t_eat = ft_patoi(argv[3], container);
	table->t_sleep = ft_patoi(argv[4], container);
	table->n_eat = -1;
	if (argc == 6)
		table->n_eat = ft_patoi(argv[5], container);
}

void	ft_init_sem(t_container *container)
{
	sem_unlink("print");
	sem_unlink("forks");
	sem_unlink("stop");
	sem_unlink("looc");
	sem_unlink("end");
	container->table->print = sem_open("print", O_CREAT, 0600, 1);
	container->table->looc = sem_open("looc", O_CREAT, 0600, 1);
	container->table->end = sem_open("end", O_CREAT, 0600, 1);
	container->table->stop = sem_open("stop", O_CREAT, 0600, 1);
	container->table->fork = sem_open("forks", O_CREAT, 0600,
			container->table->n_philo);
}

void	ft_init_philo(t_container *container)
{
	size_t	in;
	t_philo	*philos;
	t_table	*table;

	philos = container->philos;
	table = container->table;
	in = 0;
	while (in < table->n_philo)
	{
		philos[in].table = table;
		philos[in].last_meal = ft_get_time();
		philos[in].id = in;
		philos[in].pid = 0;
		philos[in].n_eat = table->n_eat;
		in++;
	}
}
