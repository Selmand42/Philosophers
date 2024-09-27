/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:39:44 by muhademi          #+#    #+#             */
/*   Updated: 2024/09/13 18:26:24 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_and_put(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (!is_numeric(argv[i]))
			return (0);
	data->philo_num = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (ft_atoi(argv[4]) < 0)
			return (philo_errors(5));
		data->eat_repeat = ft_atoi(argv[5]);
	}
	else
		data->eat_repeat = -1;
	if (data->philo_num > 200 || data->philo_num < 0)
		return (philo_errors(3));
	if (data->die_time < 0 || data-> eat_time < 0 || data->sleep_time < 0)
		return (philo_errors(4));
	return (1);
}

int	philo_errors(int num)
{
	if (num == 0)
		printf("The number of arguments must equal to 4 or 5!\n");
	if (num == 1)
		printf("Parameters must consist only numbers!\n");
	if (num == 2)
		printf("Memory couldn't allocated.\n");
	if (num == 3)
		printf("Number of philosophers is not in the range 1 - 200.\n");
	if (num == 4)
		printf("Values must be greater then 0.\n");
	return (0);
}
