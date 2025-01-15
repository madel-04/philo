/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:39:49 by marvin            #+#    #+#             */
/*   Updated: 2025/01/12 17:39:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <string.h>

# define RESET			"\033[0m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"

typedef struct s_philo
{
	int				id;
	int				*meals_eaten;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	long long		*last_meal_time;
	long long		start_time;
	int				num_forks;
	int				num_philosophers;
	pthread_t		philo_thread;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*protection_mutex;
}	t_philo;

// *** SIMULATION_INIT ***
t_philo			*initialize_simulation(int argc, char **argv);
pthread_mutex_t	*initialize_forks(int num_philosophers);
long long		*initialized_last_meal_time(int num_philosophers);
void			initialize_philos_data(t_philo *philos_initialized,
					t_philo *philo_info, pthread_mutex_t *num_forks,
					long long *last_meal_time);
t_philo			*initialize_philosophers(t_philo *philo_info);

// *** PARSE_ARGS ***
bool			parse_arguments(int argc, char **argv, t_philo *philo_info);

// *** UTILS ***
long long		ft_get_time(void);
void			ft_sleep(long long time);
void			clean_all(t_philo *philosophers, t_philo *health_monitor);

// *** FUNCTIONS ***
size_t			ft_strlen(char *str);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_atoi(const char *str);

// *** HEALTH MONITOR ***
t_philo			*setup_health_monitor(t_philo *philosopher);
void			link_philosophers_to_monitor(t_philo *philosophers,
					t_philo *monitor);
void			*check_philosopher_health(void *philosopher);
bool			check_meals_eaten(t_philo *monitor);

// *** PHILO THREADS ***
void			start_philosopher_threads(t_philo *philosophers);
void			*philo_lifecycle(void *philo);

// *** PHILO ACTIONS ***
void			get_fork(t_philo *philosopher);
void			start_eating(t_philo *philosopher);
void			release_forks(t_philo *philosopher);
void			start_sleeping(t_philo *philosopher);
void			start_thinking(t_philo *philosopher);

// *** VALIDATE X ARGUMENTS ***
int				ft_isdigit(int c);
bool			validate_num_must_eat(const char *arg);
bool			validate_time_argument(const char *arg);
bool			validate_num_philosophers(const char *arg);

// *** PRINT STATUS ***
void			print_status(t_philo *philo, char *action);
void			rest_in_peace(int id, long long time);

#endif
