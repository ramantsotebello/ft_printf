/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_oc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 15:21:13 by tramants          #+#    #+#             */
/*   Updated: 2018/08/13 18:53:14 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_basic_oc(va_list args, char c)
{
	int ret;

	ret = 0;
	if (c == '%')
		ret = ft_putchar('%');
	else if (c == 'c')
		ret = ft_putchar(va_arg(args, int));
	else if (c == 'C')
		ret = ft_put_wide_char(va_arg(args, int));
	else if (c == 's')
		ret = ft_putstr(va_arg(args, char *));
	else if (c == 'S')
		ret = ft_put_wide_str(va_arg(args, wchar_t *));
	else if (c == 'd')
		ft_putnbr(va_arg(args, int));
	else if (c == 'D')
		ft_putnbr((unsigned int)va_arg(args, int));
	else if (c == 'i')
		ft_putnbr(va_arg(args, int));
	else if (c == 'x')
		ret = ft_puthex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		ret = ft_puthex(va_arg(args, unsigned int), 1);
	else if (c == 'u')
		ft_putnbr((unsigned int)va_arg(args,int));
	else if (c == 'U')
		ft_putnbr((unsigned int)va_arg(args, int));
	else if (c == 'o')
		ft_putoct((unsigned int)va_arg(args, int));
	else if (c == 'O')
		ft_putoct((unsigned int)va_arg(args, int));
	else if (c == 'p')
		ft_puthex(va_arg(args, long), 2);
	return (ret);
}
