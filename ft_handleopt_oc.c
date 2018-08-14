/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleopt_oc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:07:40 by tramants          #+#    #+#             */
/*   Updated: 2018/08/13 18:53:23 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isin(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_getarg(va_list args, struct ol options)
{
	char	*str;
	wchar_t	*strl;

	if (options.type == 's')
		str = va_arg(args, char *);
	else if (options.type == 'S')
		strl = va_arg(args, wchar_t *);
	else if (options.type == 'c')
	{
		str[0] = va_arg(args, int);
		str[1] = '\0';
	}
	else if (options.type == 'C')
	{
	       str[0] = va_arg(args, int);
	       str[1] = '\0';
	}
	else if (options.type == 'P')
		str = va_arg(args, long);
	else if (options.type == 'i' || options.type == 'd')
		str = ft_itoa(va_arg(args, int));
	else if (options.type == 'D')
		str = ft_itoa((unsigned int)va_arg(args, int));
	return (str);	
}

int	ft_handleopt_oc(va_list args, char *s, struct ol options, int i)
{
	int	ret;
	char	*str;

	ret = 0;
	str = ft_getarg(args, options);
	if (ft_isin(options.flags, '-'))
	{
		if (options.width != 0)
		{
			if (options.width > ft_strlen(str))
			{
			}
		}
	}

	return (ret);
}
