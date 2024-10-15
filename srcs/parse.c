/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:06:37 by andefern          #+#    #+#             */
/*   Updated: 2024/10/15 11:42:53 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_stats	*stat_initializer(char **argv)
{
	t_stats	*stats;

	stats = malloc(sizeof(t_stats));
	stats->p_num = ft_atoi(argv[1]);
	stats->ttd = ft_atoi(argv[2]);
	stats->tte = ft_atoi(argv[3]);
	stats->tts = ft_atoi(argv[4]);
	stats->end = false;
	stats->start = 0;
	stats->just_eat = false;
	if (!argv[5])
		stats->must_eat = 0;
	else
	{
		stats->must_eat = ft_atoi(argv[5]);
		stats->just_eat = true;
	}
	pthread_mutex_init(&stats->print, NULL);
	return (stats);
}

t_philo	*philo_initializer(t_stats *stats, int dni)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->dni = dni;
	pthread_mutex_init(&philo->fork, NULL);
	if (&philo->fork == NULL)
		return (NULL);
	philo->start_eating = 0;
	philo->stats = stats;
	philo->next = NULL;
	return (philo);
}

t_philo	*philo_list(t_stats *stats)
{
	int		dni;
	t_philo	*head;
	t_philo	*philo;

	dni = 1;
	head = philo_initializer(stats, dni);
	dni++;
	philo = philo_initializer(stats, dni);
	dni++;
	head->next = philo;
	while (stats->p_num >= dni)
	{
		philo->next = philo_initializer(stats, dni);
		philo = philo->next;
		dni++;
	}
	philo->next = head;
	return (head);
}
