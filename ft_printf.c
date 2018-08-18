/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:30:27 by tramants          #+#    #+#             */
/*   Updated: 2018/08/18 05:21:19 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list			args;
	int				i;
	int				ret;
	struct	ol		options;

	va_start(args, format);
	i = 0;
	ret = 0;
	while(format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_is_outputc(format[i]) && format[i])
				ret += ft_basic_oc(args, format[i]);
			else if (!ft_is_outputc(format[i]) && format[i])
			{
				options = ft_check_options((char *)format, i);
				i += options.char_span;
				if (options.type == '%')
					ret += ft_handleopt_c('%', options);
				else
					ret += ft_handleopt_oc(args, options);
			}
			(format[i]) ? i++: 0;
		}
		if (format[i] != '%')
		{
			(format[i]) ? ft_putchar(format[i]) : 0;
			(format[i]) ? ret++ : 0;
			(format[i]) ? i++: 0;
		}
	}	
	va_end(args);

	return (ret);
}
