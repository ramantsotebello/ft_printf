/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleopt_oc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:07:40 by tramants          #+#    #+#             */
/*   Updated: 2018/08/17 23:38:58 by tramants         ###   ########.fr       */
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

int		ft_putcustom(int num, char custom)
{
	int	i;

	i = 0;
	while (i < num)
	{
		ft_putchar(custom);
		i++;
	}
	return (i);
}

int		ft_handleopt_C(wchar_t c, struct ol opt)
{
	int		ret;
	
	ret = 0;
	if (opt.width >= 1)
	{
		if (ft_isin_str(opt.flags, '-'))
		{
			ret += ft_put_wide_char(c); 
			ret += ft_putspaces(opt.width - 1);	
		}
		else
		{
			ret += ft_putspaces(opt.width - 1);
			ret += ft_put_wide_char(c);
		}
	}
	else
		ret += ft_put_wide_char(c);
	return (ret);
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

int		ft_handleopt_o(unsigned int oct, struct ol opt)
{
	int		ret;
	
	ret = 0;
	if (opt.width > (int)ft_nlen(oct, 8))
	{
		if (ft_isin_str(opt.flags, '-'))
		{
			(ft_isin_str(opt.flags, '#') == 1) ? ft_putchar('0'): 0;
			ret += ft_putoct(oct);
			if (ft_isin_str(opt.flags, '0') && !ft_isin_str(opt.flags, '#'))
				ret += ft_putcustom(opt.width - ft_nlen(oct, 8), '0');
			else if (ft_isin_str(opt.flags, '0') && ft_isin_str(opt.flags, '#'))
				ret += ft_putcustom(opt.width - ft_nlen(oct, 8) - 1, '0');
			else if (ft_isin_str(opt.flags, '#'))
				ret += ft_putspaces(opt.width - ft_nlen(oct, 8) - 1);
			else
				ret += ft_putspaces(opt.width - ft_nlen(oct, 8));	
		}
		else
		{
			if (ft_isin_str(opt.flags, '0') && !ft_isin_str(opt.flags, '#'))
				ret += ft_putcustom(opt.width - ft_nlen(oct, 8), '0');
			else if (ft_isin_str(opt.flags, '0') && ft_isin_str(opt.flags, '#'))
				ret += ft_putcustom(opt.width - ft_nlen(oct, 8) - 1, '0');
			else if (ft_isin_str(opt.flags, '#'))
				ret += ft_putspaces(opt.width - ft_nlen(oct, 8) - 1);
			else
				ret += ft_putspaces(opt.width - ft_nlen(oct, 8));
			(ft_isin_str(opt.flags, '#') == 1) ? ft_putchar('0'): 0;
			ret += ft_putoct(oct);
		}
	}
	else
		ret += ft_putoct(oct);
	return (ret);
}

int		ft_handleopt_x(unsigned int hex, struct ol opt, int cap)
{
	int		ret;
	
	ret = 0;
	if (opt.width >= (int)ft_nlen(hex, 16))
	{
		if (ft_isin_str(opt.flags, '-'))
		{
			(ft_isin_str(opt.flags, '#') == 1) ? (ret += ft_putstr("0x")): 0;
			ret += (cap == 1) ? ft_puthex(hex, 1) : ft_puthex(hex, 0);
			if (ft_isin_str(opt.flags, '0') && !ft_isin_str(opt.flags, '#'))
				ret += ft_putcustom(opt.width - ft_nlen(hex, 16), '0');
			else if (ft_isin_str(opt.flags, '0') && ft_isin_str(opt.flags, '#'))
				ret += ft_putcustom(opt.width - ft_nlen(hex, 16) - 2, '0');
			else if (ft_isin_str(opt.flags, '#'))
				ret += ft_putspaces(opt.width - ft_nlen(hex, 16) - 2);
			else
				ret += ft_putspaces(opt.width - ft_nlen(hex, 16));	
		}
		else
		{
			(ft_isin_str(opt.flags, '#') == 1) ? (ret += ft_putstr("0x")): 0;
			if (ft_isin_str(opt.flags, '0') && !ft_isin_str(opt.flags, '#'))
				ret += ft_putcustom(opt.width - ft_nlen(hex, 16), '0');
			else if (ft_isin_str(opt.flags, '0') && ft_isin_str(opt.flags, '#'))
				ret += ft_putcustom(opt.width - ft_nlen(hex, 16) - 2, '0');
			else if (ft_isin_str(opt.flags, '#'))
				ret += ft_putspaces(opt.width - ft_nlen(hex, 16) - 2);
			else
				ret += ft_putspaces(opt.width - ft_nlen(hex, 16));
			ret += (cap == 1) ? ft_puthex(hex, 1) : ft_puthex(hex, 0);
		}
	}
	else
	{
			(ft_isin_str(opt.flags, '#') == 1) ? (ret += ft_putstr("0x")) : 0;
			ret += (cap == 1) ? ft_puthex(hex, 1) : ft_puthex(hex, 0);
	}
	return (ret);
}

int		ft_handleopt_u(unsigned int num, struct ol opt)
{
	int		ret;
	
	ret = 0;
	if (opt.width > (int)ft_nlen(num, 10))
	{
		if (ft_isin_str(opt.flags, '-'))
		{
			ft_putnbr(num);
			ret += ft_nlen(num, 10);
			if (ft_isin_str(opt.flags, '0'))
				ret += ft_putcustom(opt.width - ft_nlen(num, 10), '0');
			else
				ret += ft_putspaces(opt.width - ft_nlen(num, 10));	
		}
		else
		{
			if (ft_isin_str(opt.flags, '0'))
				ret += ft_putcustom(opt.width - ft_nlen(num, 10), '0');
			else
				ret += ft_putspaces(opt.width - ft_nlen(num, 10));
			ft_putnbr(num);
			ret +=  ft_nlen(num, 10);
		}
	}
	else
	{
		ft_putnbr(num);
		ret += ft_nlen(num, 10); 
	}
	return (ret);
}

int		ft_handleopt_d(int num, struct ol opt)
{
	int		ret;
	int		sign;
	
	ret = 0;
	if (num < 0)
	{
		num = num * -1;
		sign = 1;
	}
	else 
		sign = 0;
	if (ft_isin_str(opt.flags, '-'))
	{
		if (ft_isin_str(opt.flags, ' '))
			ret += (sign == 1) ? 0 : ft_putchar(' ');
		else if (ft_isin_str(opt.flags, '+'))
			ret += (sign != 1) ? ft_putchar('+') : 0;
		if (opt.precision > (int)ft_nlen(num, 10))
			ret += ft_putcustom((opt.precision - ft_nlen(num, 10)),'0'); 
		(sign == 1) ? ft_putnbr(-num) : ft_putnbr(num);
		ret += ft_nlen(num, 10);
		if ((ft_isin_str(opt.flags, ' ') || ft_isin_str(opt.flags, '+'))
				&& (opt.precision  < 1))
			ret += ft_putspaces(opt.width - ft_nlen(num, 10) - 1);
		else if ((ft_isin_str(opt.flags, ' ') || ft_isin_str(opt.flags, '+')) 
				&& (opt.precision > (int)ft_nlen(num, 10)))
			ret += ft_putspaces((opt.width > opt.precision) ? 
					(opt.width - opt.precision) - 1 : 0);
		else
			ret += ft_putspaces((opt.precision > (int)ft_nlen(num, 10)) ?
					((opt.precision > opt.width ? 0 : opt.width - opt.precision))
					:(opt.width - ft_nlen(num, 10)));	
	}
	else
	{
		if (ft_isin_str(opt.flags, '+') && ft_isin_str(opt.flags, '0'))
			ret += (sign != 1) ? ft_putchar('+') : 0;
		if (ft_isin_str(opt.flags, '0') && !ft_isin_str(opt.flags, '+') &&
				!(opt.precision > (int)ft_nlen(num, 10)))
			ret += ft_putcustom(opt.width - ft_nlen(num, 10), '0');
		else if (ft_isin_str(opt.flags, '+') && !ft_isin_str(opt.flags, '0')
				&& !(opt.precision > (int)ft_nlen(num, 10)))
			ret += ft_putspaces(opt.width - ft_nlen(num, 10) - 1);
		else if (ft_isin_str(opt.flags, '0') && ft_isin_str(opt.flags, '+')
				&& !(opt.precision > (int)ft_nlen(num, 10)))
			ret += ft_putcustom(opt.width - ft_nlen(num, 10) - 1, '0');
		else if ((ft_isin_str(opt.flags, '0') || ft_isin_str(opt.flags, '+'))
				&& (opt.precision > (int)ft_nlen(num, 10)))
			ret += ft_putspaces((opt.width - opt.precision) - 1);
		else if (opt.precision >= opt.width)
			ret += ft_putspaces(0);
		else
			ret += ft_putspaces(opt.width - ft_nlen(num, 10));
		if (ft_isin_str(opt.flags, '+') && !ft_isin_str(opt.flags, '0'))
			ret += (sign != 1) ? ft_putchar('+') : ft_putchar('-');
		if (opt.precision > (int)ft_nlen(num, 10))
			ret += ft_putcustom((opt.precision - ft_nlen(num, 10)),'0'); 
		ft_putnbr(num);
		ret += ft_nlen(num, 10);
	}
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
	else if (opt.type == 'o')
		ret += ft_handleopt_o((unsigned int)va_arg(args, unsigned int), opt);
	else if (opt.type == 'u')
		ret += ft_handleopt_u((unsigned int)va_arg(args, unsigned int), opt);
	else if (opt.type == 'x')
	{
		if (ft_isin_str(opt.length, 'l'))
			ret += ft_handleopt_x((unsigned int)va_arg(args, unsigned int), opt, 0);
		else
			ret += ft_handleopt_x((unsigned int)va_arg(args, unsigned int), opt, 0);
	}
	else if (opt.type == 'X')
		ret += ft_handleopt_x((unsigned int)va_arg(args, unsigned int), opt, 1);
	else if (opt.type == 'd')
		ret += ft_handleopt_d(va_arg(args, int), opt);
	else if (opt.type == 'D')
		ret += ft_handleopt_d((unsigned int)va_arg(args, int), opt);
	else if (opt.type == 'i')
		ret += ft_handleopt_d(va_arg(args, int), opt);
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
