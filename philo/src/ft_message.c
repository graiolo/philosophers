/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:52:15 by graiolo           #+#    #+#             */
/*   Updated: 2023/03/30 18:27:30 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_message(char *str, t_philo *philos)
{
	static bool	dead;

	pthread_mutex_lock(&philos->table->print);
	if (dead == false && ft_get_time() - philos->last_meal
		> philos->table->t_die)
	{
		dead = true;
		pthread_mutex_unlock(&philos->table->print);
		ft_message(DIED, philos);
	}
	if (philos->table->dead == false)
	{
		printf("[%u] \e[1;37m%lu\e[0m %s\n", ft_get_time()
			- philos->table->t_start, (philos->id) + 1, str);
		if (ft_strcmp(str, DIED) == 0)
			philos->table->dead = true;
	}
	pthread_mutex_unlock(&philos->table->print);
}

void	ft_message_error(char *str, t_container *container)
{
	printf("%s\n", str);
	ft_destroi(container);
}
