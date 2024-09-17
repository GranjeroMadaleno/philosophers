/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:05:46 by andefern          #+#    #+#             */
/*   Updated: 2024/09/11 12:15:55 by andefern         ###   ########.fr       */
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
	long	time_start;

	time_start = updated_time();
	while (updated_time() - time_start < ms)
		usleep(10);
}
