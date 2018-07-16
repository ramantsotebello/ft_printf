/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:30:27 by tramants          #+#    #+#             */
/*   Updated: 2018/07/16 18:21:59 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;

	va_start(args, format);
	i = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			ft_putstring("Delimeter found!\n\n");
			i++;
		}
			
		ft_putchar(format[i]);
		i++;
	}	
	va_end(args);

	return (1);
}
