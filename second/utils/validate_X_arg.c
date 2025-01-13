/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_X_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:18:13 by marvin            #+#    #+#             */
/*   Updated: 2025/01/13 16:18:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_numeric(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (flase);
		str++;
	}
	return (true);
}

bool	validate_num_philosophers(const char *arg)
{
	if (!is_numeric(arg) || ft_atoi(arg) <= 0)
	{
		ft_putstr_fd("Error: INvalid Number of Philosophers\n", 2);
		return (false);
	}
	return (true);
}

bool	validate_time_argument(const char *arg)
{
	if (!is_numeric(arg) || ft_atoi(arg) <= 0)
	{
		ft_putstr_fd("Error: Invalid Number of Time\n", 2);
		return (false);
	}
	return (true);
}

bool	validate_num_must_eat(const char *arg)
{
	if (!is_numeric(arg) || ft_atoi(arg) <= 0)
	{
		ft_putstr_fd("Error: Invalid Number of Time\n", 2);
		return (false);
	}
	return (true);	
}