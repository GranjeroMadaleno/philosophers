/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:02:04 by andefern          #+#    #+#             */
/*   Updated: 2024/09/20 13:50:24 by andefern         ###   ########.fr       */
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
	t_xylo		*xylo;

	xylo = args;
	if (xylo->num % 2 == 0)
		overclocked_usleep(xylo->stats->ttp);
	while (xylo->stats->vibing != 0)
	{
		if (xylo->stats->played < xylo->stats->num)
			ft_playing(xylo);
		ft_studying(xylo);
		ft_breaktime(xylo);
	}
	return (NULL);
}

int	sewing_kit(t_stats *stats, t_xylo **xylo)
{
	pthread_t	thread_check;
	t_xylo		*temp;
	int			i;

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
	while (stats->num < i)
	{
		if (pthread_join((*xylo)->thread, NULL) != 0)
			return (0);
		*xylo = (*xylo)->next;
		i++;
	}
	pthread_create(&thread_check, NULL, finitto, xylo);
	pthread_detach(thread_check);
	return (0);
}

int	argv_checker(int argc, char **argv, t_stats *stats, t_xylo *xylo)
{
	(void)xylo;
	if (argc == 5 || argc == 6)
		initializer(stats, argv);
	//print_matic(stats, xylo);
	else
		return (1);
	return (0);
}

int	main(int argc, char**argv)
{
	t_stats	stats;
	t_xylo	*xylo;

	xylo = NULL;
	argv_checker(argc, argv, &stats, xylo);
	ft_round_list(&xylo, &stats);
	sewing_kit(&stats, &xylo);
	eraser(&*xylo, &stats);
	return (0);
}
