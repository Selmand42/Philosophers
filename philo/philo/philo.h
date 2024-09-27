/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhademi <muhademi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:23:27 by muhademi          #+#    #+#             */
/*   Updated: 2024/09/27 16:46:45 by muhademi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef pthread_mutex_t	t_mtx;
typedef struct s_data	t_data;

typedef struct s_philo
{
	int			id;
	int			status;
	int			counter;
	int			last_meal;
	t_mtx		*lf;
	t_mtx		*rf;
	t_data		*data;
	pthread_t	thread;
}	t_philo;

struct s_data
{
	int				die_time;
	int				philo_num;
	int				eat_time;
	int				sleep_time;
	int				eat_repeat;
	long			start;
	long			end;
	struct timeval	time;
	t_philo			*philos;
	t_mtx			*forks;
	t_mtx			check;
};

int		check_and_put(int argc, char **argv, t_data *data);
int		is_numeric(char *str);
int		ft_atoi(char *str);
int		philo_errors(int num);
void	routine(t_philo *philo);
void	*f(void	*phil);
int		fill_data(t_data *data);
void	fill_forks(t_data *data);
void	fill_philos(t_data *data);
int		check_status(t_data *data);
void	have_you_eaten(t_philo *philo);
long	time_milisecond(t_data	*data);
void	crowded(t_philo *philo);
void	announce(t_philo *philo, char	*str);
void	ft_sleep(t_philo *p, long time);

#endif
