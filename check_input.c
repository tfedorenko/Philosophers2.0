/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:23:48 by tfedoren          #+#    #+#             */
/*   Updated: 2022/10/22 21:09:49 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(int nbr_arg, char **arg)
{
	int	i;
	int	j;

	if (nbr_arg != 5 && nbr_arg != 6)
	{
		write(1, "Wrong number of arguments\n", 26);
		return (1);
	}
	i = 1;
	while(arg[i])
	{
		// printf("here\n");

		if(ft_atol(arg[i]) < INT32_MIN || ft_atol(arg[i]) > INT32_MAX)
		{
			printf("One or more arguments is bigger or smaller than int\n");
			return (1);
		}
		if (ft_atol(arg[i]) < 0)
		{
			printf("One or more arguments is negative\n");
			return (1);
		}

		i++;
	}
	// if(ft_atoi(arg[1]) <= 1)
	// {
	// 	printf("Wrong number of philosophers, we need at least 2 philosophers\n");
	// 	return (1);
	// }
	if (nbr_arg == 6)
	{
		if(ft_atoi(arg[5]) < 1)
		{
			printf("Number of times each philosopher must eat must be at least 1\n");
			return (1);
		}
	}
	i = 1;
	j = 0;
	while (arg[i])
	{
		
		j = 0;
		while (arg[i][j])
		{
			if (ft_isdigit(arg[i][j]) < 1 || ft_isdigit(arg[i][j]) > 9)
			{
				write(1, "There are not only digits in input\n", 35);
				return (1);
			}
			j++;
		}
		i++;
	}
	i = 0;
	// while (arg[i])
	// {
	// 	if (ft_strlen(arg[i]) >= 10)
	// }
	return (0);
}