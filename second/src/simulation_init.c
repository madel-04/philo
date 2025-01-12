/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:52:11 by marvin            #+#    #+#             */
/*   Updated: 2025/01/12 17:52:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*initialize_forks(int num_philosophers)
{
	int				i;
	pthread_mutex_t	*forks;

	i = -1;
	forks = malloc(sizeof(pthread_mutex_t) * num_philosophers);
	if (!forks)
		return (NULL);
	while (++i < num_philosophers)
		pthread_mutex_init(&forks[i], NULL);
	return (forks);
}

static long long initialized_last_meal_time(int num_philosophers)
{
	int			i;
	long long	*last_meal_time;

	i = -1;
	last_meal_time = malloc(sizeof(long long) * num_philosophers);
	if (!last_meal_time)
		return (NULL);
	while (++i < num_philosophers)
		last_meal_time[i] = ft_get_time();
	return (last_meal_time);
}

static void 	initialize_philos_data(t_philo *philos_initialized, t_philo *philo_info, pthread_mutex_t *num_forks, long long *last_meal_time)
{
	int	i;
	int	*meals;

	meals = malloc (sizeof(int) * philo_info->num_philosophers);
	if (!meals)
		return ;
	memset(meals, 0, sizeof(int) * philo_info->num_philosophers);
	i = -1;
	while (++i < philo_info_num_philosophers)
	{
		philos_initialized[i].id = i + 1;
		philos_initialized[i].meals_eaten = meals;
		philos_initialized[i].time_to_die = philo_info->time_to_die;
		philos_initialized[i].time_to_eat = philo_info->time_to_eat;
		philos_initialized[i].time_to_sleep = philo_info->time_to_sleep;
		philos_initialized[i].num_must_eat = philo_info->num_must_eat;
		philos_initialized[i].last_meal_time = last_meal_time;
		philos_initialized[i].num_forks = philo_info->num_philosophers;
		philos_initialized[i].num_philosophers = philo_info->num_philosophers;
		philos_initialized[i].fork_mutex = num_forks;
	}
	free(philo_info);
}

static	t_philo *initialize_philosophers(t_philo *philo_info)
{
	t_philo			*philos_initialized;
	pthread_mutex_t	*forks;
	long long		*last_meal_time;

	philos_initialized = malloc(sizeof(t_philo) * philo_info->num_philosophers);
	if (!philos_initialized)
		return (NULL);
	forks = initialize_forks(philo_info->num_philosophers);
	last_meal_time = initialized_last_meal_time(philo_info->num_philosophers);
	initialize_philos_data(philos_initialized, philo_info, forks, last_meal_time);
	return (philos_initialized);
}

t_philo *initialize_simulation	(int argc, char **argv)
{
	t_philo	*philo_info;
	t_philo	*philosophers_initialized;

	philo_info = malloc(sizeof(t_philo))
	if (!philo_info)
		return (NULL);
	if (!parse_arguments(argc, argv, philo_info))
	{
		free(philo_info);
		return (NULL);
	}
	philosophers_initialized = initialize_philosophers(philo_info);
	if (!philosophers_initialized)
	{
		free (philo_info);
		return (NULL);
	}
	return (philosophers_initialized);
}