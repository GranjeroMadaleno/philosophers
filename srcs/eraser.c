/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eraser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:56:20 by andefern          #+#    #+#             */
/*   Updated: 2024/10/14 11:55:37 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eraser(t_philo *philo, t_stats *stats)
{
	t_philo	*mem;

	while (stats->p_num > 0)
	{
		mem = philo;
		philo = philo->next;
		pthread_mutex_destroy(&mem->fork);
		free(mem);
		stats->p_num--;
	}
	pthread_mutex_destroy(&stats->print);
	free(stats);
}
