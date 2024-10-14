/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:48:06 by andefern          #+#    #+#             */
/*   Updated: 2024/10/14 12:12:46 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_philo	*janfri;

	janfri = args;
	if (janfri->dni % 2)
		ft_usleep(10);
	while (janfri->stats->end == false)
	{
		if (janfri->stats->end == false)
			eating(janfri);
		if (janfri->stats->end == false)
			zzz(janfri);
		if (janfri->stats->end == false)
			zinkin(janfri);
	}
	return (NULL);
}

void	de_function(t_philo *janfri)
{
	long	time;

	if (janfri->start_eating == 0)
		time = 0;
	else
		time = ft_time();
	if ((time - janfri->start_eating) >= janfri->stats->ttd)
	{
		bruce_s_printstring(janfri, "\033[92mPalma🌴\033[0m");
		janfri->stats->end = true;
		pthread_mutex_unlock(&janfri->fork);
		pthread_mutex_unlock(&janfri->next->fork);
	}
	if (janfri->stats->just_eat == true
		&& (janfri->eaten_times == janfri->stats->must_eat))
		janfri->stats->end = true;
}

void	*cctv(void *args)
{
	t_philo	*janfri;

	janfri = args;
	while (janfri->stats->end == false)
	{
		de_function(janfri);
		janfri = janfri->next;
	}
	return (NULL);
}

int	sewing_kit(t_philo *janfri)
{
	int			p_num;
	pthread_t	kill_bill;

	p_num = janfri->stats->p_num;
	janfri->stats->start = ft_time();
	while (p_num > 0)
	{
		pthread_create(&janfri->thread, NULL, routine, janfri);
		janfri = janfri->next;
		p_num--;
	}
	pthread_create(&kill_bill, NULL, cctv, janfri);
	p_num = janfri->stats->p_num;
	while (p_num > 0)
	{
		pthread_join(janfri->thread, NULL);
		janfri = janfri->next;
		p_num--;
	}
	pthread_detach(kill_bill);
	return (0);
}

void	case_one(t_stats *stats)
{
	printf("0 1 has taken a fork\n");
	ft_usleep(stats->ttd);
	printf("%d 1 has died\n", stats->ttd);
	free(stats);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stats	*stats;
	t_philo	*janfri;

	stats = stat_initializer(argv);
	if (stats->p_num == 1)
		case_one(stats);
	janfri = argv_checker(argc, stats);
	if (janfri == NULL)
		return (1);
	sewing_kit(janfri);
	eraser(janfri, stats);
	return (0);
}
