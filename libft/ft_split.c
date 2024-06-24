/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:35:31 by andefern          #+#    #+#             */
/*   Updated: 2024/02/26 11:58:41 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (s[i] == '\0')
		return (0);
	if (c == '\0')
		j--;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			j++;
		i++;
	}
	if (s[i - 1] == c)
		j--;
	return (j);
}

static int	locate(char const *s, char c, int a)
{
	int	i;

	i = a;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static int	jump(char const *s, char c, int a)
{
	int	i;

	i = a;
	while (s[i])
	{
		if (s[i] != c)
			return (i);
		i++;
	}
	return (i);
}

static char	**del(int j, char **dst)
{
	while (--j >= 0)
		free(dst[j]);
	free(dst);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		j;
	int		l;
	int		a;
	int		i;

	if (!s)
		return (NULL);
	j = 0;
	l = count(s, c);
	dst = malloc((l + 1) * sizeof(char *));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (l-- > 0 && !(c == '\0' && s[0] == '\0'))
	{
		a = jump(s, c, i);
		i = locate(s, c, a);
		dst[j] = ft_substr(s, a, (i - a));
		if (dst[j++] == NULL)
			return (del(j, dst));
	}
	dst[count(s, c)] = NULL;
	return (dst);
}
