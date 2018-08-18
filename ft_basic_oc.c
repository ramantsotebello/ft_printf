/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_oc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 15:21:13 by tramants          #+#    #+#             */
/*   Updated: 2018/08/17 19:48:30 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_basic_oc(va_list args, char c)
{
	int ret;
	int	num;
	unsigned int num2;

	ret = 0;
	num = 0;
	num2 = 0;
	if (c == '%')
		ret += ft_putchar('%');
	else if (c == 'c')
		ret += ft_putchar(va_arg(args, int));
	else if (c == 's')
		ret += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
	{
		num = va_arg(args, int);
		ft_putnbr(num);
		ret += ft_nlen(num, 10);
	}
	else if (c == 'D')
	{
		num2 = (unsigned int)va_arg(args, int);
		ft_putnbr(num2);
		ret += ft_nlen(num, 10);
	}
	else if (c == 'x')
		ret += ft_puthex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		ret += ft_puthex(va_arg(args, unsigned int), 1);
	else if (c == 'u')
	{
		num2 = (unsigned int)va_arg(args,int);
		ft_putnbr(num2);
		ret += ft_nlen(num, 10);
	}
	else if (c == 'o')
		ft_putoct((unsigned int)va_arg(args, int));
	else if (c == 'p')
		ft_puthex(va_arg(args, long), 2);
	return (ret);
}
