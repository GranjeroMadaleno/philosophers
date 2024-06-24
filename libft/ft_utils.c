/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:31:41 by andefern          #+#    #+#             */
/*   Updated: 2024/05/20 12:04:50 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	pf_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	pf_retstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	pf_uputnbr(unsigned int n)
{
	long		nb;
	int			printed;

	printed = 0;
	nb = n;
	if (nb > 9)
	{
		printed += pf_uputnbr((nb / 10));
		printed += pf_uputnbr((nb % 10));
	}
	else
	{
		nb = nb + '0';
		printed += write(1, &nb, 1);
	}
	return (printed);
}

void	pf_putchar(char c)
{
	write(1, &c, 1);
}

int	pf_hex(unsigned long n, int up_or_low)
{
	int	i;

	i = 0;
	if (n > 15)
		i += pf_hex (n / 16, up_or_low);
	if (up_or_low == 0)
		i += write (1, &"0123456789abcdef"[(n % 16)], 1);
	if (up_or_low == 1)
		i += write (1, &"0123456789ABCDEF"[(n % 16)], 1);
	return (i);
}
