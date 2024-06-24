/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:31:04 by andefern          #+#    #+#             */
/*   Updated: 2024/02/26 11:57:04 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}
/**
 * @brief el programa convierte los ints a char
 * 
 * @param n el número a convertir
 * @return char* el número ya convertido a caaracter
 */

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	len = ft_nlen(n);
	str = malloc(sizeof(char) * (len + 1));
	nb = n;
	if (str == NULL)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		str[0] = '0';
	str[len] = '\0';
	while (nb > 0)
	{
		str[len - 1] = nb % 10 + '0';
		len--;
		nb = nb / 10;
	}
	return (str);
}
