/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:48:06 by andefern          #+#    #+#             */
/*   Updated: 2024/10/15 11:55:24 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_philo	*philo;

	philo = args;
	if (philo->dni % 2)
		ft_usleep(50);
	while (philo->stats->end == false)
	{
		if (philo->stats->end == false)
			eating(philo);
		if (philo->stats->end == false)
			zzz(philo);
		if (philo->stats->end == false)
			thinking(philo);
	}
	return (NULL);
}

void	de_function(t_philo *philo)
{
	long	time;

	if (philo->start_eating == 0)
		time = 0;
	else
		time = ft_time();
	if ((time - philo->start_eating) >= philo->stats->ttd)
	{
		bruce_s_printstring(philo, "died");
		philo->stats->end = true;
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
	}
}

void	*cctv(void *args)
{
	t_philo	*philo;

	philo = args;
	while (philo->stats->end == false)
	{
		de_function(philo);
		if (eaten_bool(philo) == true)
			philo->stats->end = true;
		philo = philo->next;
	}
	return (NULL);
}

int	sewing_kit(t_philo *philo)
{
	int			p_num;
	pthread_t	kill_bill;

	p_num = philo->stats->p_num;
	philo->stats->start = ft_time();
	while (p_num > 0)
	{
		pthread_create(&philo->thread, NULL, routine, philo);
		philo = philo->next;
		p_num--;
	}
	pthread_create(&kill_bill, NULL, cctv, philo);
	p_num = philo->stats->p_num;
	while (p_num > 0)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		p_num--;
	}
	pthread_detach(kill_bill);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stats	*stats;
	t_philo	*philo;

	if (argv_checker(argc, argv))
		return (1);
	stats = stat_initializer(argv);
	if (stats->p_num == 1)
		case_one(stats);
	philo = philo_list(stats);
	if (philo == NULL)
	{
		free(stats);
		return (1);
	}
	sewing_kit(philo);
	eraser(philo, stats);
	return (0);
}
