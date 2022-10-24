/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:16:44 by tfedoren          #+#    #+#             */
/*   Updated: 2022/10/24 17:08:50 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h> 
# include <unistd.h>
# include <stdio.h>

# define NC  "\x1B[0m"
# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA  "\x1B[35m"
# define CYAN	"\x1B[36m"
# define WHITE  "\x1B[37m"

typedef struct s_philo
{
	int				philo_number;
	int				number_has_eaten;
	long long		time_last_meal_start;
	long long		time_last_sleep_start;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	pthread_t		tid;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				number_philo_must_eat;
	long long		start_time;
	int				death_flag;
	int if_someone_died;
	int dead_philo;
	pthread_mutex_t death_mutex;
	long long time_of_death;
	
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printing;
	pthread_mutex_t act_right_order;
}	t_data;

time_t	get_time_in_ms(void);

int		init_data(int argc, char **argv, t_data *data);
int		init_philo(t_data *data);

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
int		ft_isdigit(int c);
void	*ft_memset(void *dst, int c, size_t len);
size_t	ft_strlen(const char *s);
int		check_input(int nbr_arg, char **arg);
int		create_threads(t_data *data);
int		join_threads(t_data *data);
int		destroy_mutexes(t_data *data);
// void	free_function(t_data *data);
void	*routine(t_philo *philo);
void	*check_meals(void *check);


int philosophers_are_taking_forks(t_data *data, t_philo *philo);

int philosophers_are_eating(t_data *data, t_philo *philo);

int philosophers_are_putting_forks_down(t_data *data, t_philo *philo);
int someone_died(t_data *data, t_philo *philo);

int philosophers_are_sleeping(t_data *data, t_philo *philo);

int  philosophers_are_thinking(t_data *data, t_philo *philo);
void waiting_function(int time_ms);
int if_someone_died_sleeping(t_data *data, t_philo *philo);
int if_someone_died_eating(t_data *data, t_philo *philo);
int if_someone_died_thinking(t_data *data, t_philo *philo);
void exception_function(t_data *data);
void print_someone_died(t_data *data);
void death_loop(t_data *data);
int check_if_philo_died(t_data *data);
int all_meals_ate(t_data *data);
// int someone_died_during_sleeping(t_data *data, t_philo *philo);

#endif