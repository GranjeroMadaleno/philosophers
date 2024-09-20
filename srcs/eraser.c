/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eraser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:08:34 by andefern          #+#    #+#             */
/*   Updated: 2024/09/20 13:40:49 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xylophoners.h"

void	eraser(t_xylo *xylo, t_stats *stats)
{
	t_xylo	*mem;

	while (stats->num)
	{
		mem = xylo;
		xylo = xylo->next;
		free(mem);
		stats->num--;
	}
}
