/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solo_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:49:54 by graiolo           #+#    #+#             */
/*   Updated: 2023/03/30 18:27:33 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_solo(t_container *container)
{
	if (container->table->n_philo == 1)
	{
		if (pthread_create(container->philos[0].philo, NULL,
				ft_solo_routine, (void *)&(container->philos[0])) != 0)
			ft_message_error(TH_ERR, container);
		pthread_join(*(container->philos[0].philo), NULL);
		ft_destroi(container);
	}
}

void	*ft_solo_routine(void *elem)
{
	t_philo		*philos;

	philos = (t_philo *)(elem);
	ft_message(TAKE_FORKS, philos);
	ft_usleep(philos->table->t_die);
	ft_message(DIED, philos);
	return (NULL);
}
