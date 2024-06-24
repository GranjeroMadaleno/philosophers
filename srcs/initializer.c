/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:43:31 by andefern          #+#    #+#             */
/*   Updated: 2024/06/20 16:41:27 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xylophoners.h"

void	initializer(t_stats *data, char **argv)
{
	int	i;

	data->num = ft_atoi(argv[1]);
	data->ttb = ft_atoi(argv[2]);
	data->ttp = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	if (!argv[5])
		data->must_play = 0;
	else
		data->must_play = ft_atoi(argv[5]);
	data->played = 0;
	data->mallet = malloc(sizeof(pthread_mutex_t) * data->num);
	if (!data->mallet)
		return ;
	i = 0;
	while (i < data->num)
	{
		pthread_mutex_init(&data->mallet[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->mutex, NULL);
}

void	print_matic(t_stats *data, t_xylo *xylo)
{
	(void)xylo;
	printf("Parametros de entrada\n\n");
	printf("number of xylo: %d\n", data->num);
	printf("time to break: %d\n", data->ttb);
	printf("time to play: %d\n", data->ttp);
	printf("time to study: %d\n", data->tts);
	printf("must play: %d\n", data->must_play);
	printf("\n\n");
/* 	while (xylo->next)
	{
		printf("num: %d\n", xylo->num);
		xylo = xylo->next;
	} */
}
