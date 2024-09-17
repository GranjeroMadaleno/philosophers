/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:02:04 by andefern          #+#    #+#             */
/*   Updated: 2024/09/12 11:17:02 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xylophoners.h"

//number_of_philosophers time_to_die time_to_eat time_to_sleep
//[number_of_times_each_philosopher_must_eat]

/* ◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died */

void	*routine(void *args)
{
	(void)args;
	printf("Comienza\n");
	printf("Come\n");
	sleep(5);
	printf("Duerme\n");
	sleep(3);
	printf("Esperando\n");
	printf("Final del hilo\n");
	return (NULL);
/* 
	pthread_t	thread_check;
	t_xylo		*xylo;

	xylo = args;
	xylo->plays = 0;
	xylo->last_play = 0;
	if (xylo->num % 2 == 0)
		overclocked_usleep(xylo->stats->ttp - 20);
	pthread_create(&thread_check, NULL, adagio_check, xylo);
	while(xylo->stats->vibing != 0)
	{
		if(xylo->stats->played < xylo->stats-num)
			
	}
	*/
}

int	sewing_kit(t_stats *data, t_xylo **xylo)
{
	t_xylo	*temp;
	int		i;

	temp = *xylo;
	while (temp->next)
	{
		if (pthread_create(&temp->thread, NULL, routine, temp))
			return (1);
		temp = temp->next;
		if (temp == *xylo)
			break ;
	}
	i = 0;
	while (data->num < i)
	{
		if (pthread_join((*xylo)->thread, NULL) != 0)
			return (0);
		*xylo = (*xylo)->next;
		i++;
	}
	return (0);
}

int	argv_checker(int argc, char **argv, t_stats *data, t_xylo *xylo)
{
	if (argc == 5 || argc == 6)
	{
		initializer(data, argv);
		print_matic(data, xylo);
	}
	else
		return (1);
	return (0);
}

int	main(int argc, char**argv)
{
	t_stats	data;
	t_xylo	*xylo;

	xylo = NULL;
	argv_checker(argc, argv, &data, xylo);
	ft_round_list(&xylo, &data);
	sewing_kit(&data, &xylo);
	return (0);
}
