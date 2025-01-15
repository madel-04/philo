/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:53:27 by marvin            #+#    #+#             */
/*   Updated: 2025/01/12 19:53:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_atoi(const char *str)
{
	long long	value;
	int			sign;

	sign = 1;
	value = 0;
	while ((*str == ' ') || (*str == '\f') || (*str == '\n') || (*str == '\r')
		|| (*str == '\t') || (*str == '\v'))
		str++;
	if (*str == '-')
		sign *= -1;
	if ((*str == '+') || (*str == '-'))
		str++;
	while (ft_isdigit(*str))
	{
		value = value * 10 + (*str - '0');
		str++;
	}
	value = value * sign;
	return (value);
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
