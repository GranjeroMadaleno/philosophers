/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adagio.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:32:28 by andefern          #+#    #+#             */
/*   Updated: 2024/09/23 11:53:44 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xylophoners.h"

void	adagio(t_xylo *xylo)
{
	if ((my_time(GET) - xylo->last_play) >= xylo->stats->ttb)
	{
		if (xylo->stats->vibing != 0)
		{
			xylo->stats->broken = 1;
			xylo->stats->vibing = 0;
			pthread_mutex_lock(&xylo->stats->mutex);
			printf("Ms: %ld Xylo [%d] Broken\n", my_time(GET), xylo->num);
			pthread_mutex_unlock(&xylo->stats->mutex);
		}
	}
}

void	*finitto(void *args)
{
	t_xylo	*xylo;

	xylo = args;
	while (xylo->stats->vibing != 0)
	{
		adagio(xylo);
		usleep(100);
	}
	return (NULL);
}
