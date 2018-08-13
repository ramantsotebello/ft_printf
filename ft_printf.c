/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:30:27 by tramants          #+#    #+#             */
/*   Updated: 2018/08/13 18:53:19 by tramants         ###   ########.fr       */
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
			if ((ret += (ft_basic_oc(args, format[i]))) == 0)
			{
				options = ft_check_options((char *)format, i);
				printf("%c\n", options.flags[0]);
				printf("%d\n", options.width);
			}
			while (format[i] && !ft_is_outputc(format[i]))
				i++;
			i++;	
		}
		ft_putchar(format[i]);
		i++;
	}	
	va_end(args);

	return (ret + (i - 4));
}
