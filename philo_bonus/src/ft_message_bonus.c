/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:52:15 by graiolo           #+#    #+#             */
/*   Updated: 2023/03/30 18:47:54 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_message(char *str, t_philo *philos)
{
	sem_wait(philos->table->print);
	printf("[%u] \e[1;37m%lu\e[0m %s\n", ft_get_time()
		- philos->table->t_start, (philos->id) + 1, str);
	if (ft_strcmp(str, DIED) == 0)
	{
		sem_post(philos->table->end);
		return ;
	}
	sem_post(philos->table->print);
}

void	ft_message_error(char *str, t_container *container)
{
	printf("%s\n", str);
	ft_destroy(container);
}
