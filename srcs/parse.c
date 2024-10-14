/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:06:37 by andefern          #+#    #+#             */
/*   Updated: 2024/10/14 12:19:03 by andefern         ###   ########.fr       */
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
	t_philo	*janfri;
	t_philo	*morris;

	dni = 0;
	janfri = philo_initializer(stats, dni);
	dni++;
	morris = philo_initializer(stats, dni);
	dni++;
	janfri->next = morris;
	while (stats->p_num > dni)
	{
		morris->next = philo_initializer(stats, dni);
		morris->tenedoh = dni;
		morris = morris->next;
		dni++;
	}
	morris->next = janfri;
	return (janfri);
}

t_philo	*argv_checker(int argc, t_stats *stats)
{
	t_philo	*janfri;

	if (argc == 5 || argc == 6)
	{
		janfri = philo_list(stats);
		return (janfri);
	}
	else
		return (NULL);
}
