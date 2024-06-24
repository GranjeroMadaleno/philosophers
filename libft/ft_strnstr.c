/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:29:14 by andefern          #+#    #+#             */
/*   Updated: 2024/02/26 11:59:34 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i] == needle[j] && haystack[i] != '\0' && i < len)
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
		{
			return ((char *)&haystack[i - j]);
		}
		i = (i - j) + 1;
	}
	return (0);
}
