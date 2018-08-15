/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_opt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 07:16:21 by tramants          #+#    #+#             */
/*   Updated: 2018/08/15 18:50:14 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_opt(char *str, int precision)
{
	int		x;

	x = 0;
	if (precision == -1)
		ft_putstr(str);
	else if (precision > -1 && precision < ft_strlen(str))
	{
		while (x < precision)
			ft_putchar(str[x++]);
	}
	else if (precision > -1 && precision > ft_strlen(str))
	{
		while (str[x] != '\0')
			ft_putchar(str[x++]);
	}
	return (x);
}

int		ft_putstr_wide_opt(wchar_t *str, int precision)
{
	int		x;

	x = 0;
	if (precision == 0)
		ft_put_wide_str(str);
	else if (precision > 0)
	{
		while (x < precision && str[x] != '\0')
			ft_put_wide_char(str[x++]);
		while (str[x++] != '\0')
			ft_put_wide_char(' ');
	}
	return (x);
}
