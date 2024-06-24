/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:18:13 by andefern          #+#    #+#             */
/*   Updated: 2024/02/26 11:57:46 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)

{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}
