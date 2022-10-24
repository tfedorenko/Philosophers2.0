/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:41:57 by tfedoren          #+#    #+#             */
/*   Updated: 2022/10/24 18:13:34 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		
		data->philo[i].time_last_meal_start= data->start_time;
		if (pthread_create(&data->philo[i].tid, NULL, (void *)routine, \
					&data->philo[i]))
			return (1);
		i++;
	}
	printf("Am I here?**************************\n");
	death_loop(data);
	// free(data->forks);
	// // free(data->philo);
	// free(data);
	// free(data->forks);
	// free(data->philo);
	return (0);
}
