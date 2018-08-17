/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:12:03 by tramants          #+#    #+#             */
/*   Updated: 2018/08/16 11:30:44 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_outputc(char c)
{
	if ((c == 'c') || (c == 'C') || (c == 's') || (c == 'S') || (c == 'p') 
		|| (c == 'd') || (c == 'D') || (c == 'o') || (c == 'O') || (c == 'u')
		|| (c == 'U') || (c == 'x') || (c == 'X') || (c == 'i') || (c == 'f'))
		return (1);
	return (0);
}

int		ft_isflag(char c)
{
	if ((c == '-') || (c == '+') || (c == ' ') || (c == '0') || (c == '#'))
		return (1);
	return (0);
}

int		ft_islength_mod(char c)
{
	if ((c == 'h') || (c == 'l') || (c == 'j') || (c == 'z'))
		return (1);
	return (0);
}

int		ft_isprecision(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int		ft_iswidth(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_isin(char *string, char c, int index)
{
	int i;

	i = 0;
	while (i <= index)
	{
		if (string[i] == c)
			return (1);
		i++;
	}
	return (0);
}

struct	ol	ft_check_options(char *str, int index)
{
	struct ol	options;
	int			i;
	int			j;

	i = index;
	while ((str[i] != '\0') && (ft_is_outputc(str[i]) != 1))
	{
		j = 0;
		while ((ft_isflag(str[i])) && (str[i]) && (!ft_is_outputc(str[i])))
		{
			if (str[i] == '0' && ft_isin(options.flags, '0', j))
				i++;
			else
				options.flags[j++] = str[i++];
		}
		options.flags[j] = '\0';
		j = 0;
		while ((ft_isdigit(str[i])) && (str[i]) && (str[i] != '.' ||
			!ft_is_outputc(str[i])))
		{
			j += str[i++] - '0';
			j *= 10;
		}
		if (j != 0)
			options.width = (j / 10);
		else
			options.width = 0;
		j = 0;
		if (ft_isprecision(str[i]) && (str[i + 1]) && (!ft_is_outputc(str[i + 1])))
		{
			i++;
			while (ft_isdigit(str[i]) && (str[i]) && (!ft_is_outputc(str[i])))
			{
				j *= 10;
				j += str[i++] - '0';
			}
		}
		if (j > -1)
			options.precision = (j);
		else
			options.precision = -1;
		j = 0;
		while (ft_islength_mod(str[i]) && (str[i]) && (!ft_is_outputc(str[i])))
			options.length[j++] = str[i++];
		options.length[j] = '\0';
		if (ft_is_outputc(str[i]))
			options.type = str[i];
	}
	i = index;
	while ((str[i] != '\0') && (ft_is_outputc(str[i]) != 1))
		i++;
	options.char_span = (i - index);
	return (options);
}
