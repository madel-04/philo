/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:34:37 by marvin            #+#    #+#             */
/*   Updated: 2024/12/30 22:34:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
INPUT = ./philo 5 600 454 233 [5]
*/

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		//PROGRAM
		parse_input(&table, av); //Check errors and filling thr table
		data_init(&table); //iniciar los datos
		dinner_start(&table); //programa
		clean(&table) //finish everything when every philo is full or one dies
	}
	else
	{
		error_exit("Wrong input, please enter: ./philo X X X X \n")
	}
}