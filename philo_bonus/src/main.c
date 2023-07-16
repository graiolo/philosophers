/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:26:00 by graiolo           #+#    #+#             */
/*   Updated: 2023/07/16 02:56:33 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	main(int argc, char **argv)
{
	t_container		*container;
	unsigned int	i;
	pthread_t		killer;

	if (!(argc == 5 || argc == 6))
		return (1);
	i = 0;
	ft_allocate_init(&container, argv, argc);
	sem_wait(container->table->end);
	if (pthread_create(&killer, NULL, ft_kill, (void *)(container)) != 0)
		ft_message_error(TH_ERR, container);
	ft_fork(container);
	sem_post(container->table->end);
	pthread_join(killer, NULL);
	ft_destroy(container);
	return (0);
}
