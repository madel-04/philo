/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:42:16 by marvin            #+#    #+#             */
/*   Updated: 2025/01/10 09:42:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->allthreads_ready))
		;
}