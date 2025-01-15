/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:44:18 by marvin            #+#    #+#             */
/*   Updated: 2025/01/12 17:44:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philosophers;
	t_philo	*health_monitor;

	philosophers = initialize_simulation(argc, argv);
	if (!philosophers)
	{
		write(2, RED, ft_strlen(RED));
		ft_putstr_fd("Simulation initialization failed", 1);
		write(2, RESET, ft_strlen(RESET));
		return (1);
	}
	health_monitor = setup_health_monitor(philosophers);
	if (!health_monitor)
	{
		write(2, RED, ft_strlen(RED));
		ft_putstr_fd("Health monitor initialization failed", 1);
		write(2, RESET, ft_strlen(RESET));
		return (1);
	}
	link_philosophers_to_monitor(philosophers, health_monitor);
	start_philosopher_threads(philosophers);
	pthread_create(&health_monitor->philo_thread, NULL,
		check_philosopher_health, health_monitor);
	pthread_join(health_monitor->philo_thread, NULL);
	return (clean_all(philosophers, health_monitor), 0);
}
