/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:48:02 by marvin            #+#    #+#             */
/*   Updated: 2024/12/30 22:48:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
./philo nbr_philo time1 time2 time3

*/

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <='9');
}

static inline bool	is_space(char c)
{
	return((c >= 9 && c <= 13) || (c == 32));
}

static const char   *valid_input(const char *str)
{
    int         len;
    const char  *n;

    len = 0;
    while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		error_exit("Enter only positive values\n");
	if (!is_digit(*str))
		error_exit("The input have a not correct digit \n");
	n = str;
	while (is_digit(*str++))
		++len;
	if (len > 10)
		error_exit("The input is too big, the limit is iNT_MAX \n");
	return (n);

}

static long    ft_atol(const char *str)
{
    long n;

    n = 0;
    str = valid_input(str);
	while (is_digit(*str))
	{
		n = (n * 10) + (*str++ - '0');
	}
	if (n > INT_MAX)
		error_exit ("The value is to big, INT_MEX is the limit")
	return (n);
}

void	parse_input(t_table *table, char **av)
{
    table->philo_nbr = ft_atol(av[1]);
    table->time_to_die = ft_atol(av[2]) * 1e3;
    table->time_to_eat = ft_atol(av[3]) * 1e3;
    table->time_to_sleep = ft_atol(av[4]) * 1e3;
	if (table->time_to_die < 6e4
		|| table->time_to_eat < 6e4
		|| table->time_to_sleep < 6e4)
		error_exit("Use timestamps major than 60ms \n");
	if (av[5])
		table->nbr_limit_meals = ft_atol(av[5]);
	else
		table->nbr_limit_meals = -1;
}