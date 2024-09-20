/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:43:31 by andefern          #+#    #+#             */
/*   Updated: 2024/09/20 13:41:48 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xylophoners.h"

void	initializer(t_stats *stats, char **argv)
{
	stats->vibing = 1;
	stats->played = 0;
	stats->broken = 0;
	stats->tempo = 0;
	stats->num = ft_atoi(argv[1]);
	stats->ttb = ft_atoi(argv[2]);
	stats->ttp = ft_atoi(argv[3]);
	stats->tts = ft_atoi(argv[4]);
	if (!argv[5])
		stats->must_play = 0;
	else
		stats->must_play = ft_atoi(argv[5]);
	stats->played = 0;
	pthread_mutex_init(&stats->mutex, NULL);
}

void	print_matic(t_stats *stats, t_xylo *xylo)
{
	(void)xylo;
	printf("Parametros de entrada\n\n");
	printf("number of xylo: %d\n", stats->num);
	printf("time to break: %d\n", stats->ttb);
	printf("time to play: %d\n", stats->ttp);
	printf("time to study: %d\n", stats->tts);
	printf("must play: %d\n", stats->must_play);
	printf("\n\n");
}
