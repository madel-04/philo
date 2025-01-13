/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:15:32 by marvin            #+#    #+#             */
/*   Updated: 2025/01/12 20:15:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    get_fork(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->fork_mutex[philosopher->id -1]);
	if (philosopher->id == 1)
		pthread_mutex_lock(&philosopher->fork_mutex[philosopher->num_philosophers -1]);
	else
		pthread_mutex_lock(&philosopher->fork_mutex[philosopher->id - 2]);
	pthreaad_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "has taken a fork");
	pthread_mutex_unlock(philosopger->protection_mutex);
}

void	start_eating(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is eating");
	philosopher->last_meal_time[philosopher->id - 1] = ft_get_time();
	philosopher->meals_eaten[philosopher->id - 1]++;
	pthread_mutex_unlock(philosopher->protection_mutex);
	ft_sleep(philosopher->time_to_eat);
}

void	release_forks(t_philo *philosopher)
{
	pthread_mutex_unlock(&philosopher->fork_mutex[philosopher->id - 1]);
	if(philosopher->id == 1)
		pthread_mutex_unlock(&philosopher->fork_mutex[philosopher->num_philosophers - 1]);
	else
		pthread_mutex_unlock(&philosopher->fork_mutex[philosopher->id - 2]);
}

void	start_sleeping(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is sleeping");
	pthread_mutex_unlock(philosopher->protection_mutex);
	ft_sleep(philosopher->time_to_sleep);
}

void	start_thinking(t_philo *philosopher)
{
	pthread_mutex_lock(philosopher->protection_mutex);
	print_status(philosopher, "is thinking");
	pthread_mutex_unlock(philosopher->protection_mutex);
}
