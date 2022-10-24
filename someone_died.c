/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   someone_died.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:30:46 by tfedoren          #+#    #+#             */
/*   Updated: 2022/10/24 17:47:40 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	someone_died(t_data *data, t_philo *philo)
// {	
// 	long long time;
// 	time = get_time_in_ms() - data->start_time;
// 	pthread_mutex_lock(&data->act_right_order);
	
// 	if (data->death_flag > 0)
// 	{
// 		pthread_mutex_unlock(&data->act_right_order);
// 		return (1);
// 	}
	
// 	if ((((get_time_in_ms() - philo->time_last_meal_start)> philo->data->time_to_die)))
// 	{
		
// 		if (data->death_flag > 0)
// 		{
// 			pthread_mutex_unlock(&data->act_right_order);
// 			return (1);
// 		}
		
// 		// printf("Heeeeeeeeeerreeeeeeeeeeeeeeeeeeeee!\n");
// 		pthread_mutex_lock(&data->printing);
// 		printf("%lld [%i]Philosopher died!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n", time, philo->philo_number);
// 		pthread_mutex_unlock(&data->printing);
// 		data->death_flag++;
// 		pthread_mutex_unlock(&data->act_right_order);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&data->act_right_order);
// 	// dead_loop();
// 	return (0);
// }

int check_if_philo_died(t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	if(data->if_someone_died > 0)
	{

		pthread_mutex_unlock(&data->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->death_mutex);
	return (0);
}

void death_loop(t_data *data)
{
	// long long time;

	// pthread_mutex_lock(&data->act_right_order);
	
	while (1)
	{
		int i;
		i = 0;
		while(i < data->number_of_philosophers)
		{
			// if (data->number_philo_must_eat == data->philo[i].number_has_eaten && data->number_philo_must_eat != 0)
			// 	return ;
			if(all_meals_ate(data) == 1)
				return ;
			pthread_mutex_lock(&data->act_right_order);	
			if (data->philo[i].time_last_meal_start != 0 && (((get_time_in_ms() - data->philo[i].time_last_meal_start )> data->time_to_die)))
			{	
				pthread_mutex_lock(&data->death_mutex);
				data->dead_philo = i + 1;
				data->time_of_death = get_time_in_ms() - data->start_time;
				data->if_someone_died = 1;
				pthread_mutex_unlock(&data->death_mutex);
				pthread_mutex_unlock(&data->act_right_order);
				return ;
			}
			pthread_mutex_unlock(&data->act_right_order);
			i++;
		}
		// pthread_mutex_unlock(&data->act_right_order);
	}

}
void print_someone_died(t_data *data)
{
	if (data->if_someone_died > 0)
		printf("%lld %i Philosopher died!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n", data->time_of_death, data->dead_philo);
}

// int if_someone_died_sleeping(t_data *data, t_philo *philo)
// {
// 	long long time_after_sleeping;
	
	
// 	time_after_sleeping = get_time_in_ms() + data->time_to_sleep;
// 	while(get_time_in_ms() <= time_after_sleeping)
// 	{
// 		if(someone_died(data, philo))
// 		{
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

// int if_someone_died_eating(t_data *data, t_philo *philo)
// {
// 	long long time_after_eating;
// 	pthread_mutex_lock(&data->act_right_order);
// 	// printf("philo->time_last_meal_start**** = %lld\n", p÷hilo->time_last_meal_start - data->start_time);
// 	time_after_eating = data->philo->time_last_meal_start + data->time_to_eat;
// 	pthread_mutex_unlock(&data->act_right_order);
// 	// printf("time_after_eating = %lld\n", time_after_eating - data->start_time);
	
// 		while(get_time_in_ms() <= time_after_eating)
// 		{
// 			// printf("get_time_in_ms() <= time_after_eating = %lld\n", time_after_eating - get_time_in_ms());
// 			if(someone_died(data, philo))
// 			{
// 				// pthread_mutex_unlock(&data->act_right_order);
// 				pthread_mutex_unlock(philo->fork_left);
// 				pthread_mutex_unlock(philo->fork_right);
// 				return (1);
// 			}			
// 			// usleep (100);
// 		}
// 	return (0);
// }

// int if_someone_died_thinking(t_data *data, t_philo *philo)
// {
// 	// long long time_thinking_start;

// 	// time_thinking = 
// 	while (1)
// 	{
// 		if(someone_died(data, philo))
// 		{
// 				// // pthread_mutex_unlock(&data->act_right_order);
// 				// pthread_mutex_unlock(philo->fork_left);
// 				// pthread_mutex_unlock(philo->fork_right);
// 				return (1);
// 		}
			
// 		// return (0);
// 	}

// 	return (0);
// }