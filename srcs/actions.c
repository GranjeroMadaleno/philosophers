/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:49:13 by andefern          #+#    #+#             */
/*   Updated: 2024/10/15 11:43:39 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	case_one(t_stats *stats)
{
	printf("0 1 has taken a fork\n");
	ft_usleep(stats->ttd);
	printf("%d 1 died\n", stats->ttd);
	free(stats);
	exit(0);
}

void	thinking(t_philo *philo)
{
	bruce_s_printstring(philo, "is thinking");
}

void	zzz(t_philo *philo)
{
	bruce_s_printstring(philo, "is sleeping");
	ft_usleep(philo->stats->tts);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	bruce_s_printstring(philo, "has taken a fork");
	pthread_mutex_lock(&philo->next->fork);
	bruce_s_printstring(philo, "has taken a fork");
	philo->start_eating = ft_time();
	bruce_s_printstring(philo, "is eating");
	ft_usleep(philo->stats->tte);
	philo->eaten_times++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

bool	eaten_bool(t_philo *philo)
{
	int	p_num;

	p_num = philo->stats->p_num;
	while (p_num--)
	{
		if (philo->stats->just_eat == false)
			return (0);
		if (philo->stats->just_eat == true
			&& (philo->eaten_times < philo->stats->must_eat))
			return (0);
		philo = philo->next;
	}
	return (1);
}
