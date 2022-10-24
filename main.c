/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:17:38 by tfedoren          #+#    #+#             */
/*   Updated: 2022/10/24 18:11:49 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data ;

	data = malloc(sizeof(t_data));
	if (check_input(argc, argv))
		return (0);
	if (init_data(argc, argv, data))
		return (0);
	if(data->number_of_philosophers == 1)
	{
		exception_function(data);
		return (0);
	}
	if (init_philo(data))
		return (0);
	if (create_threads(data))
		return (0);
	// free(data->forks);
	// free(data->philo);
	// free(data);
	if (join_threads(data))
		return (0);
	return (destroy_mutexes(data));
	// free(data->forks);
	// free(data->philo);
	// free(data);
	if (destroy_mutexes(data))
		return (0);
	free(data->forks);
	free(data->philo);
	free(data);


	return (0);
}

int all_meals_ate(t_data *data)
{
	pthread_mutex_lock(&data->act_right_order);
	if (data->number_philo_must_eat == data->philo->number_has_eaten && data->number_philo_must_eat != 0)
		{
			pthread_mutex_unlock(&data->act_right_order);
			return (1);
		}
	pthread_mutex_unlock(&data->act_right_order);
	return (0);
	
}
void	*routine(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->act_right_order);
	philo->time_last_meal_start = get_time_in_ms();
	pthread_mutex_unlock(&data->act_right_order);
	if (philo->philo_number % 2 == 0)
	{
		if (data->number_of_philosophers > 100)
			usleep(100);
		else
			usleep(1500);
	}
	while (check_if_philo_died(data) == 0)
	{
		if(all_meals_ate(data) == 1)
			break ;
		
		philosophers_are_taking_forks(data, philo);
		philosophers_are_eating(data, philo);
		philosophers_are_putting_forks_down(data, philo);
		philosophers_are_sleeping(data, philo);
		philosophers_are_thinking(data, philo);				
	}
	// free(data->forks);
	// free(data->philo);
	// free(philo);
	return (NULL);
}
