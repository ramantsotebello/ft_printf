/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:12:03 by tramants          #+#    #+#             */
/*   Updated: 2018/08/11 16:22:48 by tramants         ###   ########.fr       */
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

struct options_list	ft_check_options(char *str)
{
	struct options_list options;
	int					i;

	i = 0;
	while ((str[i] != '\0') && (ft_is_outputc(str[i]) != 1))
	{
		if (ft_is_outputc(str[i + 1]))
			options.type = str[i + 1];
		else if (ft_is_outputc(str[i]))
			options.type = str[i];

		if (ft_isflag(str[i]))
		{
			//options.flag = str[i];
			i++;
		}
		else if (ft_iswidth(str[i]))
		{
			options.width = str[i];
			i++;
		}
	}
	return (options);
}
