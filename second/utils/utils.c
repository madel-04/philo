/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:38:10 by marvin            #+#    #+#             */
/*   Updated: 2025/01/12 18:38:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1e3) + (time.tv_usec / 1e3));
}

void	ft_sleep(long long time)
{
	long long	start_time;

	start_time = ft_get_time();
	while (ft_get_time() - start_time < time)
		usleep(100);
}

void	clean_all(t_philo *philosophers, t_philo *health_monitor)
{
	int	i;

	i = -1;
	ft_sleep(philosophers->time_to_die + philosophers->time_to_eat
		+ philosophers->time_to_sleep + 100);
	while (++i < philosophers->num_philosophers)
	{
		pthread_mutex_destroy(&philosophers[i].fork_mutex[i]);
		pthread_mutex_destroy(philosophers[i].protection_mutex);
	}
	pthread_mutex_destroy(health_monitor->protection_mutex);
	free(philosophers->fork_mutex);
	free(philosophers->meals_eaten);
	free(philosophers->last_meal_time);
	free(philosophers->protection_mutex);
	free(philosophers);
	philosophers = NULL;
	free(health_monitor);
}
