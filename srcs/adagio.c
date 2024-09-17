/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adagio.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:32:28 by andefern          #+#    #+#             */
/*   Updated: 2024/09/12 10:34:50 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xylophoners.h"

void	adagio(t_xylo *xylo)
{
	if (((updated_time() - xylo->stats->tempo) - xylo->last_play) >= xylo->stats->ttb)
	{
		if (xylo->stats->vibing != 0)
		{
			xylo->stats->broken = 1;
			xylo->stats->vibing = 0;
			pthread_mutex_lock(&xylo->stats->mutex);
			printf("Ms: %ld Xylo [%d] Broken\n", updated_time() - xylo->stats->tempo,
				xylo->num);
			pthread_mutex_unlock(&xylo->stats->mallet[xylo->left]);
			pthread_mutex_unlock(&xylo->stats->mallet[xylo->next->left]);
			pthread_mutex_unlock(&xylo->stats->mutex);
		}
	}
}

void	*adagio_check(void *args)
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
