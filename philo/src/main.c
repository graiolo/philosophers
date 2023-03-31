/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:14:49 by graiolo           #+#    #+#             */
/*   Updated: 2023/03/30 18:27:45 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_container		*container;
	unsigned int	i;

	if (!(argc == 5 || argc == 6))
		return (1);
	i = 0;
	ft_allocate_init(&container, argv, argc);
	ft_solo(container);
	while (i < container->table->n_philo)
	{
		if (pthread_create(container->philos[i].philo, NULL,
				ft_routine, (void *)&(container->philos[i])) != 0)
			ft_message_error(TH_ERR, container);
		i++;
	}
	i = 0;
	ft_bigbrother(container);
	while (i < container->table->n_philo)
		pthread_join(*(container->philos[i++].philo), NULL);
	ft_destroi(container);
	return (0);
}
