/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:06:28 by marvin            #+#    #+#             */
/*   Updated: 2024/12/30 23:06:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*my_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
		error_exit("Error with the malloc \n");
	return (ret);
}

// Embec controls on return status
static void	handle_mutex_error(int status, t_opcode opcode)
{
	if (status == 0)
		return;
	if (status == EINVAL && (LOCK == opcode || UNLOCK == opcode)) //falta destory
		error_exit("The value specified by mutex is invalid.");
	else if (EINVAL == status &&  opcode == INIT)
		error_exit("The value specified by attr is invalud.");
	else if (EDEADLK == status)
		error_exit("A deadlock would occur if the thread blocked waiting for mutex.");
	else if (EPERM == status)
		error_exit("The current thread does not hold a lock on mutex.");
	else if (ENOMEM == status)
		error_exit("The process cannot allocate enough memory to create another mutex.");
	else if (EBUSY == status)
		error_exit("Mutex is locked.");
	
}

//MUTEX SAFE
/*
* Init, destroy, lock y unlovk¡¡ck
*/

void	safe_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		handle_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (opcode == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (opcode == INIT)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (opcode == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		error_exit("Wrong opcode for mutex handle");
}

// FOR THE THREADS
static void	handle_thread_error(int status, t_opcode opcode)
{
	if (status == 0)
		return;
	if (EAGAIN == status)
		error_exit("No resources to create another thread.");
	else if (EPERM == status)
		error_exit("The caller does not have appropriate permission.");
	else if (EINVAL == status &&  opcode == CREATE)
		error_exit("The value specified by attr is invalud.");
	else if (EINVAL == status &&  (opcode == JOIN || opdoce == DETACH))
		error_exit("The value specified by thread is not joineable.");
	else if (ESRCH == status)
		error_exit("No thread could be found corresponding to that specified by the given thread ID, thread.");
	else if (EDEADLK == status)
		error_exit("A deadlock was detected or the value of thread specifies the calling thread.");

}

void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		handle_thread_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (opcode == JOIN)
		handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (opcode == DETACH)
		handle_thread_error(pthread_detach(*thread), opcode);
	else
		error_exit("Wrong opcode for thread handle:"
					" use <CREATE> <JOIN> <DETACH>");
}

static void	assign_forks(t_philo *philo, t_fork fork, int position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;

	philo->firse_fork = &fork[(position + 1) & philo_nbr];
	philo->second_fork = &fork[position];
	if (philo->id % 2)
	{
	philo->first_fork = &fork[position];
	philo->second_fork = &fork[(position + 1) & philo_nbr];
	}
}

static void philo_init(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->table = table;
		assign_forks(philo, talbe->forks, i);
	}
}

void	data_init(t_table *table)
{
	int	i;

	i = 0;
	table->end_simulation = false;
	table->all_threads_ready = false;
	table->philos = my_malloc(sizeof(t_philo) * table->philo_nbr);
	safe_mutex_handle(&table->table_mutex, INIT);
	table->forks = my_malloc(sizeof(t_fork) * table->philo_nbr);
	while (++i < table->philo_nbr)
	{
		safe_mutex_handle(&table->forks[i].fork, INIT);
		table->forks[i].forks_id = i;
	}
	philo_init(table);
}