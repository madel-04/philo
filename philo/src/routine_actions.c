/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:23:08 by marvin            #+#    #+#             */
/*   Updated: 2025/01/27 15:04:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Think routine funtion

void	think(t_philo *philo)
{
	print_message("is thinking", philo);
}

// Dream routine funtion

void	dream(t_philo *philo)
{
	print_message("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}

static void	take_forks(t_philo *philo, pthread_mutex_t **first_fork,
		pthread_mutex_t **second_fork)
{
	if (philo->r_fork < philo->l_fork)
	{
		*first_fork = philo->r_fork;
		*second_fork = philo->l_fork;
	}
	else
	{
		*first_fork = philo->l_fork;
		*second_fork = philo->r_fork;
	}
	pthread_mutex_lock(*first_fork);
	print_message("has taken a fork", philo);
}

void	eat(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	take_forks(philo, &first_fork, &second_fork);
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(first_fork);
		return ;
	}
	pthread_mutex_lock(second_fork);
	print_message("has taken a fork", philo);
	philo->eating = 1;
	print_message("is eating", philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
}
