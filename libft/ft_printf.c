/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:37:14 by andefern          #+#    #+#             */
/*   Updated: 2024/06/10 13:10:15 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_support(va_list things, char c)
{
	if (c == 'c')
	{
		pf_putchar(va_arg(things, unsigned int));
		return (1);
	}
	else if (c == 's')
		return (pf_retstr(va_arg(things, char *)));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return (pf_hex(va_arg(things, unsigned long), 0) + 2);
	}
	else if (c == 'd')
		return (pf_putnbr(va_arg(things, int)));
	else if (c == 'i')
		return (pf_putnbr(va_arg(things, int)));
	else if (c == 'u')
		return (pf_uputnbr(va_arg(things, unsigned int)));
	else if (c == 'x')
		return (pf_hex(va_arg(things, unsigned int), 0));
	else if (c == 'X')
		return (pf_hex(va_arg(things, unsigned int), 1));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *print, ...)
{
	va_list	things;
	int		i;
	int		p;

	va_start(things, print);
	i = 0;
	p = 0;
	if (pf_strlen(print) == 1 && print[i] == '%')
		return (p);
	while (print[i])
	{
		if (print[i] == '%' && print[i + 1])
		{
			p += pf_support(things, print[i + 1]);
			i++;
		}
		else
		{
			pf_putchar((unsigned int)print[i]);
			p++;
		}
		i++;
	}
	va_end(things);
	return (p);
}
