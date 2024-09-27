/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 04:44:25 by muhademi          #+#    #+#             */
/*   Updated: 2024/09/13 18:40:05 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	crowded(t_philo *philo)
{
	while (31)
	{
		pthread_mutex_lock(philo->rf);
		announce(philo, "has taken a fork");
		pthread_mutex_lock(philo->lf);
		announce(philo, "has taken a fork");
		announce(philo, "is eating");
		pthread_mutex_lock(&philo->data->check);
		philo->last_meal = time_milisecond(philo->data);
		philo->counter++;
		pthread_mutex_unlock(&philo->data->check);
		ft_sleep(philo, philo->data->eat_time);
		pthread_mutex_unlock(philo->lf);
		pthread_mutex_unlock(philo->rf);
		announce(philo, "is sleeping");
		ft_sleep(philo, philo->data->sleep_time);
		announce(philo, "is thinking");
	}
}

void	*f(void	*phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	if (philo->data->philo_num == 1)
	{
		announce(philo, "has taken a fork");
		ft_sleep(philo, philo->data->die_time);
		have_you_eaten(philo);
		usleep(2000);
	}
	if (philo->id % 2 == 0)
		usleep(250);
	crowded(philo);
	return (0);
}

void	fill_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i].id = i + 1;
		data->philos[i].status = 1;
		data->philos[i].counter = 0;
		data->philos[i].data = data;
		data->philos[i].last_meal = time_milisecond(data);
		i++;
	}
}

int	check_status(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		have_you_eaten(&data->philos[i]);
		pthread_mutex_lock(&data->check);
		if (data->philos[i].status == 0)
		{
			printf("%ld\t%d died\n", time_milisecond(data),
				data->philos[i].id);
			return (EXIT_FAILURE);
		}
		pthread_mutex_unlock(&data->check);
	}
	i = -1;
	pthread_mutex_lock(&data->check);
	while (++i < data->philo_num)
		if (!(data->eat_repeat != -1
				&& data->philos[i].counter >= data->eat_repeat))
			break ;
	if (i == data->philo_num)
		return (EXIT_FAILURE);
	pthread_mutex_unlock(&data->check);
	return (0);
}

void	have_you_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->check);
	if (((time_milisecond(philo->data) - philo->last_meal))
		> philo->data->die_time)
		philo->status = 0;
	pthread_mutex_unlock(&philo->data->check);
}
