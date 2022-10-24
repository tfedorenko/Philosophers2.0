/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:24:41 by tfedoren          #+#    #+#             */
/*   Updated: 2022/10/24 17:46:43 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void exception_function(t_data *data)
{
	
	printf("%lld [1]Philosopher has taken left fork\n", get_time_in_ms() - data->start_time);
	
	printf("%lld [1]Philosopher died!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n", get_time_in_ms() + data->time_to_die - data->start_time);
	return ;
}

