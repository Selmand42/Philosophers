/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:28:50 by muhademi          #+#    #+#             */
/*   Updated: 2024/09/13 18:24:53 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != 0)
		return (philo_errors(1));
	return (1);
}

long	time_milisecond(t_data	*data)
{
	gettimeofday(&data->time, NULL);
	return ((data->time.tv_usec / 1000
			+ data->time.tv_sec * 1000) - data->start);
}

void	ft_sleep(t_philo *p, long time)
{
	long	end;

	end = time_milisecond(p->data) + time;
	while (time_milisecond(p->data) - end < 0)
		usleep(500);
}

void	announce(t_philo *philo, char	*str)
{
	pthread_mutex_lock(&philo->data->check);
	printf("%ld\t%d %s\n", time_milisecond(philo->data), philo->id, str);
	pthread_mutex_unlock(&philo->data->check);
}
