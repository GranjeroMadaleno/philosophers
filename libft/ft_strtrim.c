/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:17:47 by andefern          #+#    #+#             */
/*   Updated: 2024/02/26 11:59:43 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_compare(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
/**
 * @brief compara desde el principio al final el string con set
 * 
 * @param s1 string principal
 * @param set string recibido
 * @return size_t posición del caracter que coincide
 */

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_compare(s1[i], set) == 0)
			return (i);
		i++;
	}
	return (i);
}
/**
 * @brief compara desde el final al principio el string con set
 * 
 * @param s1 string principal
 * @param set string recibido
 * @return size_t devuelve el caracter encontrado
 */

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	while (len > 0)
	{
		if (ft_compare(s1[len - 1], set) == 0)
			return (len);
		len--;
	}
	return (len);
}
/**
 * @brief el programa elimina los caracteres que coinciden con set,
 * desde ambos lados de string
 * 
 * @param s1 string principal
 * @param set string recibido
 * @return char* el substring sin los caracteres que coinciden
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (set[0] == 0)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (end - start < 0 || s1[0] == '\0')
		return (ft_strdup(""));
	str = ft_substr(s1, start, end - start);
	return (str);
}
