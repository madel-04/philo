/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:01:53 by marvin            #+#    #+#             */
/*   Updated: 2025/01/11 12:01:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	write_statis_debug(t_philo_status status, t_philo *philo, long elapsed)
{
	if (TAKE_FIRST_FORK == status && !simulation_finished(philo->table))
		printf("Has taken the 1º fork", elapsed, philo->id, philo->first_fork->fork_id);
	else if (TAKE_SECIND_FORK == status && !simulation_finished(philo->table))
		printf("Has taken the 2º fork", elapsed, philo->id, philo->second_fork->fork_id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf("Is eating", elapsed, philo->id, philo->meals_counter);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf("Is sleeping", elapsed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf("Is thinking", elapsed, philo->id);
	else if (DIED == status && !simulation_finished(philo->table))
		printf("died", elapsed, philo->id);	
}

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elpased;

	elapsed = gettime(MILLISECOND) - philo->table->start_simulation; //START SIMULATION
	if (philo->full)
		return ;
	if (debug)
		write_status_debug(status, philo, elkapsed);
	safe_mutex_handle(&philo->table->write_mutex, LOCK);
	else
	{
		if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK) && !simulation_finished(philo->table))
			printf(W"%-6ld"RST" %d has taken a fork\n", elapsed, philo->id);
		else if (EATING == status && !simulation_finished(philo->table))
			printf(W"%-6ld"RST" %d is eating\n", elapsed, philo->id);
		else if (SLEEPING == status && !simulation_finished(philo->table))
			printf(W"%-6ld"RST" %d is sleeping\n", elapsed, philo->id);
		else if (THINKING == status && !simulation_finished(philo->table))
			printf(W"%-6ld"RST" %d is thinking\n", elapsed, philo->id);
		else if (DIED == status)
			printf(RED"%-6ld"RST" %d died\n", elapsed, philo->id);
	}
	safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}
