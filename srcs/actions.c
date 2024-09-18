/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:18:06 by andefern          #+#    #+#             */
/*   Updated: 2024/09/18 15:19:32 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xylophoners.h"

int	print_status(t_xylo *xylo, char *str)
{
	if (xylo->stats->vibing != 0)
	{
		pthread_mutex_lock(&xylo->stats->mutex);
		if (xylo->stats->vibing != 0)
			printf("Ms: %ld Xylo [%d] %s\n", updated_time() - xylo->stats->tempo, xylo->num, str);
		pthread_mutex_unlock(&xylo->stats->mutex);
	}
	return (0);
}

void	ft_playing(t_xylo *xylo)
{
	pthread_mutex_lock(&xylo->stats->mallet[xylo->left]);
	print_status(xylo, "has taken the left mallet...\n");
	pthread_mutex_lock(&xylo->stats->mallet[xylo->next->left]);
	print_status(xylo, "has taken the right mallet...\n");
	print_status(xylo, "is playing...\n");
	xylo->last_play = updated_time() - xylo->stats->tempo;
	ft_must_play(xylo);
	overclocked_usleep(xylo->stats->ttp);
	pthread_mutex_unlock(&xylo->stats->mallet[xylo->left]);
	pthread_mutex_unlock(&xylo->stats->mallet[xylo->next->left]);
}

void	ft_must_play(t_xylo *xylo)
{
	if (xylo->stats->must_play)
		xylo->plays++;
	if (xylo->plays == xylo->stats->must_play && xylo->stats->must_play)
	{
		pthread_mutex_lock(&xylo->stats->mutex);
		xylo->stats->played++;
		pthread_mutex_unlock(&xylo->stats->mutex);
	}
	if (xylo->stats->played == xylo->stats->num)
	{
		pthread_mutex_lock(&xylo->stats->mutex);
		xylo->stats->vibing = 0;
		pthread_mutex_unlock(&xylo->stats->mutex);
	}
}

void	ft_studying(t_xylo *xylo)
{
	print_status(xylo, "is studying...\n");
	overclocked_usleep(xylo->stats->tts);
}

void	ft_breaktime(t_xylo *xylo)
{
	print_status(xylo, "is taking a break...\n");
}
