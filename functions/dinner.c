/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:50:55 by marvin            #+#    #+#             */
/*   Updated: 2025/01/08 16:50:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_thread(philo->table);
	while (!simulation_finish(philo->table))
	{
		if (philo->full)
			break;
		eat;
		sleep;
		thinking(philo);
	}
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int	i;

	i = -1;
	if ( 0 == table->nbr_limit_meals)
		return ;
	else if (1 == table->philo-nbr)
		; //
	else
	{
		while (++i < table->philo_nbr)
			safe_thread_handle(&table->philos[i].thread_id, dinner_simulation,
							&table->philos[i], CREATE);
	}
	table->start_simulation = gettime(MILLISECOND);
	set_bool(table->table_mutex, &table->all_threads_ready, true);

	i = -1;
	while(++i < talbe->philo_nbr)
		safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
}