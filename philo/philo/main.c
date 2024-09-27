/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:18:49 by muhademi          #+#    #+#             */
/*   Updated: 2024/09/13 18:32:56 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_things(t_data *data)
{
	free (data->philos);
	free (data->forks);
	pthread_mutex_destroy(&data->check);
	free(data);
	exit (EXIT_FAILURE);
}

void	fill_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_init(&(data->forks[i]), NULL);
	data->philos[0].lf = &(data->forks[0]);
	data->philos[0].rf = &(data->forks[(data->philo_num) - 1]);
	i = 1;
	while (i < data->philo_num)
	{
		data->philos[i].lf = &(data->forks[i - 1]);
		data->philos[i].rf = &(data->forks[i]);
		i++;
	}
}

int	fill_data(t_data *data)
{
	int	i;

	fill_forks(data);
	fill_philos(data);
	i = 0;
	pthread_mutex_init(&data->check, NULL);
	while (i < data->philo_num)
	{
		pthread_create(&(data->philos[i].thread), NULL, f,
			&data->philos[i]);
		i++;
	}
	while (31)
		if (check_status(data) == EXIT_FAILURE)
			free_things(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		return (philo_errors(0));
	data = malloc(sizeof(t_data));
	if (!data)
		return (philo_errors(3));
	if (!check_and_put(argc, argv, data))
		return (0);
	data->start = 0;
	data->start = time_milisecond(data);
	data->forks = malloc(data->philo_num * sizeof(t_mtx));
	if (!(data->forks))
		return (philo_errors(2));
	data->philos = malloc(data->philo_num * sizeof(t_philo));
	if (!(data->philos))
		return (philo_errors(2));
	fill_data(data);
	return (0);
}
