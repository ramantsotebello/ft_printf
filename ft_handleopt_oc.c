/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleopt_oc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:07:40 by tramants          #+#    #+#             */
/*   Updated: 2018/08/15 18:50:15 by tramants         ###   ########.fr       */
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

wchar_t	*ft_getarg_S(va_list args)
{
	return (va_arg(args, wchar_t *));
}

wchar_t	ft_getarg_C(va_list args)
{
	return (va_arg(args, wchar_t));
}

int		ft_putspaces(int spaces)
{
	int		x;

	x = 0;
	while (x < spaces)
	{
		ft_putchar(' ');
		x++;
	}
	return (x);
}

int		ft_handleopt_c(char c, struct ol opt)
{
	int		ret;
	
	ret = 0;
	if (opt.width >= 1)
	{
		if (ft_isin_str(opt.flags, '-'))
		{
			ret += ft_putchar(c); 
			ret += ft_putspaces(opt.width - 1);	
		}
		else
		{
			ret += ft_putspaces(opt.width - 1);
			ret += ft_putchar(c);
		}
	}
	else
		ret += ft_putchar(c);
	return (ret);
}

int		ft_handleopt_p(long pointer, struct ol opt)
{
	int		ret;
	
	ret = 0;
	if (opt.width >= 14)
	{
		if (ft_isin_str(opt.flags, '-'))
		{
			ret += ft_puthex(pointer, 2);
			ret += ft_putspaces(opt.width - 14);	
		}
		else
		{
			ret += ft_putspaces(opt.width - 14);
			ret += ft_puthex(pointer, 2);
		}
	}
	else
		ret += ft_puthex(pointer, 2);
	return (ret);
}

int		ft_handleopt_s(char *s, struct ol opt)
{
	int		ret;
	
	ret = 0;
	if ((opt.width >= ft_strlen(s)) && 
			((opt.precision == -1) || (opt.precision > ft_strlen(s))))
	{
		if (ft_isin_str(opt.flags, '-'))
		{
			ret += ft_putstr(s); 
			ret += ft_putspaces(opt.width - ft_strlen(s));	
		}
		else
		{
			ret += ft_putspaces(opt.width - ft_strlen(s));
			ret += ft_putstr(s);
		}
	}
	else if (opt.precision > -1 && opt.width >= ft_strlen(s))
	{
		if (ft_isin_str(opt.flags, '-'))
		{
			ret += ft_putstr_opt(s, opt.precision); 
			ret += ft_putspaces(opt.width - opt.precision);
		}
		else
		{
			ret += ft_putspaces(opt.width - opt.precision);
			ret += ft_putstr_opt(s, opt.precision);
		}
	}
	else if (opt.precision > -1)
	{
		if (ft_isin_str(opt.flags, '-'))
		{
			ret += ft_putstr_opt(s, opt.precision);
			if (opt.width > opt.precision)
				ret += ft_putspaces(opt.width - opt.precision);	
		}
		else
		{
			if (opt.width > opt.precision)
				ret += ft_putspaces(opt.width - opt.precision);
			ret += ft_putstr_opt(s, opt.precision);
		}	
	}
	else
		ret += ft_putstr(s);
	return (ret);
}

int		ft_handleopt_oc(va_list args, struct ol opt)
{
	int ret;

	ret = 0;
	if (opt.type == 's')
		ret += ft_handleopt_s(va_arg(args, char *), opt);
	else if (opt.type == 'c')
		ret += ft_handleopt_c(va_arg(args, int), opt);
	else if (opt.type == 'p')
		ret += ft_handleopt_p(va_arg(args, long), opt);
	return (ret);
}
/*
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
*/
