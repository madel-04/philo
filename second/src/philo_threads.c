/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:05:52 by marvin            #+#    #+#             */
/*   Updated: 2025/01/12 20:05:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_lifecycle(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	if (philosopher->id % 2 == 0)
		ft_sleep(10);
	while (1)
	{
		get_fork(philosopher);
		start_eating(philosopher);
		release_forks(philosopher);
		start_sleeping(philosopher);
		start_thinking(philosopher);
	}
}

void	start_philosopher_threads(t_philo *philosophers)
{
	int	i;

	i = -1;
	while (++i < philosophers->num_philosophers)
	{
		philosophers[i].start_time = ft_get_time();
		pthread_create(&philosophers[i].philo_thread, NULL,
			philo_lifecycle, &philosophers[i]);
		pthread_detach(philosophers[i].philo_thread);
	}
}
