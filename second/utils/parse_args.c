/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:00:33 by marvin            #+#    #+#             */
/*   Updated: 2025/01/12 18:00:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_error_parse_msg(void)
{
	const char *error_msg = 
		RED "Error: Invalid number of arguments\n" RESET "\n"
		GREEN "Usage: ./philo [number_of_philosophers] [time_to_die] "
		"[time_to_eat] [time_to_sleep] (optional) "
		"[number_of_times_each_philosopher_must_eat]\n" RESET "\n"
		YELLOW "Example: ./philo 5 800 200 200 3\n" RESET "\n";

	write(2, error_msg, ft_strlen(error_msg));
}

static bool	is_valid_input(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (false);
	if (!validate_num_philosophers(argv[1]) //TODO
		|| !validate_time_argument(argv[2]) //TODO
		|| !validate_time_argument(argv[3])
		|| !validate_time_argument(argv[4])
		|| (argc == 6 && !validate_num_must_eat(argv[5]))) //TODO
	{
		return (false);
	}
	return (true);
}

bool	parse_arguments(int argc, char **argv, t_philo *philo_info)
{
	if (!is_valid_input(argc, argv))
	{
		ft_error_parse_msg();
		return (false);
	}
	philo_info->num_philosophers = ft_atoi(argv[1]); //TODO
	philo_info->time_to_die = ft_atoi(argv[2]);
	philo_info->time_to_eat = ft_atoi(argv[3]);
	philo_info->time_to_sleep = ft_atoi(argv[4]);
	philo_info->num_must_eat = (argc == 6) ? ft_atoi(argv[5]) : -1;
	return (true);
}
