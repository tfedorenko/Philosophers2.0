/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads_and_destroy_mutexes.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:47:18 by tfedoren          #+#    #+#             */
/*   Updated: 2022/10/24 18:11:03 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_data *data)
{
	int	i;

	i = 0;

	while (i < data->number_of_philosophers)
	{
				
		if (pthread_join(data->philo[i].tid, NULL))
			return (111);
		// printf("here\n");
		i++;
	}
	print_someone_died(data);
	return (0);
}
int	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
	// 			printf("%p\n", data->philo[i].fork_left);
	// 			printf("%p\n", data->philo[i].fork_right);
		if (pthread_mutex_destroy(data->philo[i].fork_left))
			return (7777777);
		// if (pthread_mutex_destroy(data->philo[i].fork_right))
		// 	return (2);


		i++;
	}
	if (pthread_mutex_destroy(data->forks))
			return (3);
	if (pthread_mutex_destroy(&data->printing))
			return (4);
	if (pthread_mutex_destroy(&data->act_right_order))
			return (5);
	if (pthread_mutex_destroy(&data->death_mutex))
			return (6);
	return (0);
		// free(data->forks);
	// free(data->philo);
	// free(data);
}
