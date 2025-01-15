/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:41:39 by marvin            #+#    #+#             */
/*   Updated: 2025/01/13 12:41:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *action)
{
	char	*color[6];

	color[0] = RED;
	color[1] = GREEN;
	color[2] = YELLOW;
	color[3] = BLUE;
	color[4] = MAGENTA;
	color[5] = CYAN;
	write(1, color[philo->id % 6], ft_strlen(color[philo->id % 6]));
	ft_putnbr_fd(ft_get_time() - philo->start_time, 1);
	write(1, "\t", 1);
	ft_putnbr_fd(philo->id, 1);
	write(1, "\t", 1);
	write(1, action, ft_strlen(action));
	write(1, RESET, ft_strlen(RESET));
	write(1, "\n", 1);
}

void	rest_in_peace(int id, long long time)
{
	ft_putnbr_fd(time, 1);
	write(1, "\t", 1);
	ft_putnbr_fd(id, 1);
	write(1, "\t", 1);
	write(1, "died", 4);
	write(1, "\n", 1);
}
