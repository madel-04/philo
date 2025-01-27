/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:23:56 by marvin            #+#    #+#             */
/*   Updated: 2025/01/27 15:02:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RESET			"\033[0m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"

# define PHILO_MAX 201

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;
typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

// Main functions
int					check_arg_content(char *arg);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					check_valid_args(char **argv);
void				destory_all(char *str, t_program *program,
						pthread_mutex_t *forks);

// Initialization
void				init_program(t_program *program, t_philo *philos);
void				init_forks(pthread_mutex_t *forks, int philo_num);
void				init_philos(t_philo *philos, t_program *program,
						pthread_mutex_t *forks, char **argv);
void				init_input(t_philo *philo, char **argv);

// Threads
int					ft_thread_create(t_program *program,
						pthread_mutex_t *forks);
void				*monitor(void *pointer);
void				*philo_routine(void *pointer);

// Actions
void				eat(t_philo *philo);
void				dream(t_philo *philo);
void				think(t_philo *philo);

// Monitor utils
int					dead_loop(t_philo *philo);
int					check_if_all_ate(t_philo *philos);
int					check_if_dead(t_philo *philos);
int					philosopher_dead(t_philo *philo, size_t time_to_die);

// Utils
int					ft_atoi(char *str);
int					ft_usleep(size_t microseconds);
int					ft_strlen(char *str);
void				print_message(char *str, t_philo *philo);
size_t				get_current_time(void);

#endif
