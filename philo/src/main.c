/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:24:06 by marvin            #+#    #+#             */
/*   Updated: 2025/01/27 15:02:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg_content(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 0 && n <= 9)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

int	check_valid_args(char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_arg_content(argv[1]) == 1)
		return (ft_putstr_fd("Invalid philosophers number\n", 2), 1);
	if (ft_atoi(argv[2]) <= 0 || check_arg_content(argv[2]) == 1)
	{
		ft_putstr_fd("Invalid time to die\n", 2);
		return (1);
	}
	if (ft_atoi(argv[3]) <= 0 || check_arg_content(argv[3]) == 1)
	{
		ft_putstr_fd("Invalid time to eat\n", 2);
		return (1);
	}
	if (ft_atoi(argv[4]) <= 0 || check_arg_content(argv[4]) == 1)
	{
		ft_putstr_fd("Invalid time to sleep\n", 2);
		return (1);
	}
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_arg_content(argv[5]) == 1))
	{
		ft_putstr_fd("Invalid number of times each philosopher must eat\n", 2);
		return (1);
	}
	return (0);
}
// Main function

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("Wrong argument count\n", 2);
		return (1);
	}
	if (check_valid_args(argv) == 1)
		return (1);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &program, forks, argv);
	ft_thread_create(&program, forks);
	destory_all(NULL, &program, forks);
	return (0);
}
