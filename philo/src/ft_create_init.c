/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:49:55 by graiolo           #+#    #+#             */
/*   Updated: 2023/07/16 01:17:30 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_allocate_table(t_container *container)
{
	container->table = (t_table *)malloc(sizeof(t_table));
	if (container->table == NULL)
		ft_message_error(MALL_ERR, container);
	container->table->fork = NULL;
}

void	ft_allocate_philo(t_container *container)
{
	container->philos = (t_philo *)malloc(sizeof(t_philo)
			* container->table->n_philo);
	if (container->philos == NULL)
		ft_message_error(MALL_ERR, container);
	container->philos->philo = NULL;
	container->philos->l_fork = NULL;
	container->philos->r_fork = NULL;
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
	table->dead = false;
	table->n_eat = -1;
	if (argc == 6)
		table->n_eat = ft_patoi(argv[5], container);
	table->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->n_philo);
	if (table->fork == NULL)
		ft_message_error(MALL_ERR, container);
	if (pthread_mutex_init(&table->print, NULL) != 0)
		ft_message_error(MTX_ERR, container);
	if (pthread_mutex_init(&table->looc, NULL) != 0)
		ft_message_error(MTX_ERR, container);
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
		philos[in].philo = (pthread_t *)malloc(sizeof(pthread_t));
		if (philos[in].philo == NULL)
			ft_message_error(MALL_ERR, container);
		philos[in].table = table;
		philos[in].last_meal = ft_get_time();
		philos[in].id = in;
		philos[in].n_eat = table->n_eat;
		in++;
	}
}

void	ft_init_fork(t_container *container)
{
	size_t	id;
	t_philo	*philos;
	t_table	*table;

	id = 0;
	philos = container->philos;
	table = container->table;
	while (id < table->n_philo)
	{
		if (pthread_mutex_init(&table->fork[id], NULL) != 0)
			ft_message_error(MTX_ERR, container);
		if (id % 2 == 0)
		{
			philos[id].r_fork = &table->fork[id];
			philos[id].l_fork = &table->fork[(id + 1) % table->n_philo];
		}
		else
		{
			philos[id].r_fork = &table->fork[(id + 1) % table->n_philo];
			philos[id].l_fork = &table->fork[id];
		}
		id++;
	}
}
