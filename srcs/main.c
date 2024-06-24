/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:02:04 by andefern          #+#    #+#             */
/*   Updated: 2024/06/20 16:23:55 by andefern         ###   ########.fr       */
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
	printf("EMPEZAMOH\n");
	printf("VAMOH A COMEH\n");
	sleep(5);
	printf("VAMOH A DOLMIL\n");
	sleep(3);
	printf("ME LO PIENSO\n");
	printf("Final del hilo\n");
	return (NULL);
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
