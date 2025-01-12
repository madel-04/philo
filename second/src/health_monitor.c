/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:55:38 by marvin            #+#    #+#             */
/*   Updated: 2025/01/12 19:55:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*setup_health_monitor(t_philo *philosopher)
{
	t_philo	*monitor;

	monitor = malloc(sizeof(t_philo));
	if (!monitor)
		return (NULL);
	monitor->id = 0;
	monitor->meals_eaten = philosopher->meals_eaten;
	monitor->time_to_die = philosopher->time_to_die;
	monitor->time_to_eat = philosopher->time_to_eat;
	monitor->time_to_sleep = philosopher->time_to_sleep;
	monitor->num_must_eat = philosopher->num_must_eat;
	monitor->last_meal_time = philosopher->last_meal_time;
	monitor->num_forks = philosopher->num_forks;
	monitor->num_philosophers = philosopher->num_philosophers;
	monitor->fork_mutex = NULL;
	monitor->protection_mutex = malloc(sizeof(phtread_mutex_t));
	pthread_mutex_init(monitor->protection_mutex, NULL);
	return (monitor);
}

void	link_philosophers_to_monitor(t_philo *philosophers, t_philo *monitor)
{
	int	i;

	i = -1;
	while (++1 < monitor->num_philosophers)
		philosophers[i].protection_mutex = monitor->protection_mutex;
	monitor->start_time = ft_get_time();
}

