/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_destroy_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:29:38 by graiolo           #+#    #+#             */
/*   Updated: 2023/03/30 18:47:50 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_allocate_init(t_container **container, char **argv, int argc)
{
	ft_allocate_container(container);
	ft_allocate_table(*container);
	ft_init_table(*container, argv, argc);
	ft_init_sem(*container);
	ft_allocate_philo(*container);
	ft_init_philo(*container);
}

void	ft_allocate_container(t_container **container)
{
	*container = (t_container *)malloc(sizeof(t_container));
	if (*container == NULL)
		ft_message_error(MALL_ERR, *container);
	(*container)->philos = NULL;
	(*container)->table = NULL;
}

void	ft_destroy_sem(t_container *container)
{
	if (container->table->fork != NULL)
	{
		sem_close(container->table->fork);
		sem_unlink("fork");
	}
	if (container->table->print != NULL)
	{
		sem_close(container->table->print);
		sem_unlink("print");
	}
	if (container->table->stop != NULL)
	{
		sem_close(container->table->stop);
		sem_unlink("stop");
	}
	if (container->table->end != NULL)
	{
		sem_close(container->table->end);
		sem_unlink("end");
	}
}

void	ft_destroy(t_container *container)
{
	if (container == NULL)
		exit(0);
	if (container->table != NULL)
	{
		ft_destroy_sem(container);
		free(container->table);
	}
	if (container->philos != NULL)
		free(container->philos);
	free(container);
	exit (0);
}
