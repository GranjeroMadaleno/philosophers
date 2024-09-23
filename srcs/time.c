/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:05:46 by andefern          #+#    #+#             */
/*   Updated: 2024/09/23 11:50:40 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xylophoners.h"

long	updated_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	overclocked_usleep(unsigned int ms)
{
	long	start_time;

	start_time = updated_time();
	while (updated_time() - start_time < ms)
		usleep(100);
}

long int	my_time(int mood)
{
	static long int	first_time;
	long int		now_time;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == 0)
		now_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	else
		return (-1);
	if (mood == SET)
		first_time = now_time;
	if (mood == GET)
	{
		now_time -= first_time;
		return (now_time);
	}
	return (0);
}
