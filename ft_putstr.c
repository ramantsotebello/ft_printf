/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:37:05 by tramants          #+#    #+#             */
/*   Updated: 2018/07/16 16:38:52 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(char *str)
{
	int		count;

	count = 0;
	while(str[count])
	{
		ft_putchar(str[count]);
		count++;
	}
	return (count);
}
