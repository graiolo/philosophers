/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_destoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:29:38 by graiolo           #+#    #+#             */
/*   Updated: 2023/03/30 18:27:26 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_allocate_init(t_container **container, char **argv, int argc)
{
	ft_allocate_container(container);
	ft_allocate_table(*container);
	ft_init_table(*container, argv, argc);
	ft_allocate_philo(*container);
	ft_init_philo(*container);
	ft_init_fork(*container);
}

void	ft_allocate_container(t_container **container)
{
	*container = (t_container *)malloc(sizeof(t_container));
	if (*container == NULL)
		ft_message_error(MALL_ERR, *container);
	(*container)->philos = NULL;
	(*container)->table = NULL;
}

void	ft_destroi(t_container *container)
{
	size_t	in;

	in = 0;
	if (container == NULL)
		exit(0);
	if (container->philos != NULL)
	{
		while (in < container->table->n_philo)
			free(container->philos[in++].philo);
	}
	if (container->table->fork != NULL)
		pthread_mutex_destroy(container->table->fork);
	if (container->table->fork != NULL)
		free(container->table->fork);
	if (container->table != NULL)
		free(container->table);
	if (container->philos != NULL)
		free(container->philos);
	free(container);
	exit (0);
}
