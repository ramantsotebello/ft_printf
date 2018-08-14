/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleopt_oc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:07:40 by tramants          #+#    #+#             */
/*   Updated: 2018/08/14 17:38:18 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isin_str(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}	

void	*ft_getarg(va_list args, struct ol options)
{
	char	*str;
	wchar_t	*strl;

	if (options.type == 's')
	{
		str = ft_strdup(va_arg(args, char *));
		return (str);
	}
	else if (options.type == 'S')
	{
		strl = va_arg(args, wchar_t *);
		return (strl);
	}
	else if (options.type == 'c')
		str[0] = (char)va_arg(args, int);
	else if (options.type == 'C')
		str[0] = (char)va_arg(args, int);
	else if (options.type == 'P')
		str = (char *)va_arg(args, long);
	return (str);	
}

wchar_t	*ft_getarg_wide(va_list args, struct ol options)
{
	wchar_t	*str;

	if (options.type == 'S')
		str = va_arg(args, wchar_t *);
}

int		ft_putspaces(int spaces)
{
	int		x;

	x = 0;
	while (x++ < spaces)
		ft_putchar(' ');
	return (x);
	char	c;
}

int	ft_handleopt_oc(va_list args, struct ol options)
{
	int	ret;
	char	*str;
	int	width;
	int	precision;
	char	type;
	char	*flags;
	char	*length_mod;

	ret = 0;
	width = options.width;
	precision = options.precision;
	type = options.type;
	flags = options.flags;
	length_mod = options.length;	
	str = ft_getarg(args, options);
	
	printf("\n-------------------------------");	
	printf("\nwidth:     %d\n", width);
	printf("precision: %d\n", precision);
	printf("type:      %c\n", type);
	printf("flags:     %s\n", flags);
	printf("length:    %s\n", length_mod);
	printf("-------------------------------\n");	
	
	if ((ft_isin_str(flags, '-')) == 1)
	{
		if (width > 0)
		{
			if (width > ft_strlen(str))
			{
				if (ft_isin_str(length_mod, 'l'))
					ft_putstr_wide_opt(str,((precision != 0) ? precision: 0));
				ft_putstr_opt(str,((precision != 0) ? precision: 0));
				ft_putspaces(width - ft_strlen(str));	
			}
			else
			{
				if (ft_isin_str(length_mod, 'l'))
					ft_putstr_wide_opt(str,((precision != 0) ? precision: 0));
				ft_putstr_opt(str,((precision != 0) ? precision: 0));
			}
		}
	}

	return (ret);
}
