/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:49:13 by andefern          #+#    #+#             */
/*   Updated: 2024/10/14 11:45:44 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	bruce_s_printstring(t_philo *janfri, char *str)
{
	if (janfri->stats->end == false)
	{
		pthread_mutex_lock(&janfri->stats->print);
		printf("[%lu]: Philo id: [%d]: %s\n",
			(ft_time() - janfri->stats->start), janfri->dni, str);
		pthread_mutex_unlock(&janfri->stats->print);
	}
}

void	zinkin(t_philo *janfri)
{
	bruce_s_printstring(janfri, "eeemmmm");
}

void	zzz(t_philo *janfri)
{
	bruce_s_printstring(janfri, "E eepy");
	ft_usleep(janfri->stats->tts);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	bruce_s_printstring(philo, "\033[94mHa pillau mi fork\033[0m");
	pthread_mutex_lock(&philo->next->fork);
	bruce_s_printstring(philo, "\033[94mHa pillau el otro\033[0m");
	philo->start_eating = ft_time();
	bruce_s_printstring(philo, "\033[91mA comeh\033[0m");
	ft_usleep(philo->stats->tte);
	philo->eaten_times++;
	pthread_mutex_unlock(&philo->fork);
	bruce_s_printstring(philo, "\033[95mSuelta mi fork\033[0m");
	pthread_mutex_unlock(&philo->next->fork);
	bruce_s_printstring(philo, "\033[95mSuelta el otro\033[0m");
}
