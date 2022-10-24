/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:57:33 by tfedoren          #+#    #+#             */
/*   Updated: 2022/10/24 17:12:43 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_philo_must_eat = ft_atoi(argv[5]);
	else
		data->number_philo_must_eat = 0;
	data->start_time = get_time_in_ms();
	data->death_flag = 0;
	data->if_someone_died = 0;
	data->time_of_death = 0;
	data->dead_philo = 0;
	data->philo = malloc(sizeof(t_philo) * data->number_of_philosophers);
	if (!data->philo)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * \
				data->number_of_philosophers);
	if (!data->forks)
		return (1);
	while (i < data->number_of_philosophers)
	{
		
		if (pthread_mutex_init(&data->forks[i + 1], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->printing, NULL))
		return (1);
	if (pthread_mutex_init(&data->act_right_order, NULL))
		return (1);
	if (pthread_mutex_init(&data->death_mutex, NULL))
		return (1);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		data->philo[i].data = data;
		data->philo[i].philo_number = i + 1;
		// printf("data->philo[i].philo_number = %d\n", data->philo[i].philo_number );
		data->philo[i].number_has_eaten = 0;
		// data->philo[i].time_last_meal_start = get_time_in_ms();
		data->philo[i].time_last_meal_start = get_time_in_ms();
		if (i == 0)
			data->philo[i].fork_left = &(data->forks[\
						data->number_of_philosophers]);
		else
			data->philo[i].fork_left = &(data->forks[data->philo[i].philo_number - 1]);
		data->philo[i].fork_right = &data->forks[data->philo[i].philo_number];
		i++;
	}
	return (0);
}
