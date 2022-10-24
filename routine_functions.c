/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:53:52 by tfedoren          #+#    #+#             */
/*   Updated: 2022/10/24 17:53:32 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosophers_are_taking_forks(t_data *data, t_philo *philo)
{	
	long long	time;
	
	pthread_mutex_lock(philo->fork_left);
	if (check_if_philo_died(data) != 0)
	{
		pthread_mutex_unlock(philo->fork_left);
		return (1);
	};
	time = get_time_in_ms() - data->start_time;
	pthread_mutex_lock(&data->printing);
	printf("%lld %i Philosopher has taken left fork\n", time, \
				philo->philo_number);
	pthread_mutex_unlock(&data->printing);
	
	pthread_mutex_lock(philo->fork_right);
	if (check_if_philo_died(data) > 0)
	{
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		return (1);
	};
	time = get_time_in_ms() - data->start_time;

	pthread_mutex_lock(&data->printing);
	printf("%lld %i Philosopher has taken right fork\n", time, \
				philo->philo_number);
	pthread_mutex_unlock(&data->printing);
	return (0);
}

int eating_dying(t_data *data, t_philo *philo)
{
	long long after_meal;
	
	after_meal = philo->time_last_meal_start + data->time_to_eat;
	while (get_time_in_ms() <= after_meal )
	{
		if(check_if_philo_died(data) > 0)
			{
				pthread_mutex_unlock(philo->fork_left);
				pthread_mutex_unlock(philo->fork_right);
				return (1);
			}
	}
	return (0);
}	

int	philosophers_are_eating(t_data *data, t_philo *philo)
{
	long long	time = 0;
	
	if(check_if_philo_died(data) > 0)
	{
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		return (1);
	}
	pthread_mutex_lock(&data->act_right_order);
	// pthread_mutex_lock(&data->act_right_order);
	philo->time_last_meal_start = get_time_in_ms();
	// pthread_mutex_unlock(&data->act_right_order);
	pthread_mutex_unlock(&data->act_right_order);
	time = get_time_in_ms() - data->start_time;
	pthread_mutex_lock(&data->printing);
	printf("%lld %i Philosopher is eating\n", time, philo->philo_number);
	pthread_mutex_unlock(&data->printing);
	pthread_mutex_lock(&data->act_right_order);

	philo->time_last_meal_start = get_time_in_ms();
	pthread_mutex_unlock(&data->act_right_order);
	if (eating_dying(data, philo))
	{
		pthread_mutex_unlock(&data->act_right_order);
		return (1);
	}
		return (0);	
}

int	philosophers_are_putting_forks_down(t_data *data, t_philo *philo)
{
	(void)data;
	// printf("philo->time_last_meal_start = %lld\n", philo->time_last_meal_start - data->start_time);
	pthread_mutex_unlock(philo->fork_right);	
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_lock(&data->act_right_order);
	philo->number_has_eaten++;
	pthread_mutex_unlock(&data->act_right_order);
	return (0);
}

int	philosophers_are_sleeping(t_data *data, t_philo *philo)
{
	long long	time;
	long long time_after_wake_up;

	time = get_time_in_ms() - data->start_time;
	time_after_wake_up = get_time_in_ms() + data->time_to_sleep;

	if(check_if_philo_died(data))
	{
		return (1);
	}
	pthread_mutex_lock(&data->printing);
	printf("%lld %i Philosopher is sleeping\n", time, philo->philo_number);
	pthread_mutex_unlock(&data->printing);

	// printf("%d Philo time = get_time_in_ms() - data->start_time; = %lld\n", philo->philo_number, time = get_time_in_ms() - data->start_time);
	// printf("%d Philo time_after_wake_up = %lld\n", philo->philo_number, time_after_wake_up - data->start_time);
	while(get_time_in_ms() <= time_after_wake_up)
	{	
		if (check_if_philo_died(data))
			return (1);
	}
	if (check_if_philo_died(data))
	{
		
		return (1);
	}

	

	// waiting_function(data->time_to_sleep);
	return (0);

		
}

int	philosophers_are_thinking(t_data *data, t_philo *philo)
{
	long long	time;
	long long time_to_die_thinking;
	
	time = get_time_in_ms() - data->start_time;

	if (check_if_philo_died(data))
	{
		return (1);
	}
	
	pthread_mutex_lock(&data->printing);
	printf("%lld %i Philosopher is thinking\n", time, philo->philo_number);
	pthread_mutex_unlock(&data->printing);
	time_to_die_thinking = data->time_to_die - get_time_in_ms();
	while(get_time_in_ms() <= time_to_die_thinking)
	{
		
		if (get_time_in_ms() - philo->time_last_sleep_start >= data->time_to_die)
			break ;
		usleep(200);
	}
	if (check_if_philo_died(data))
	{
		return (1);
	}
	return(0);
}
