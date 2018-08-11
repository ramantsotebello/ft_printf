/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 13:21:53 by tramants          #+#    #+#             */
/*   Updated: 2018/08/11 13:49:25 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putoct(size_t num)
{
	char	*oct;
	size_t	num_len;
	char	c;
	int		count;

	num_len = ft_number_len(num, 8);
	oct = (char*)malloc(sizeof(char) * num_len + 1);
	oct[num_len] = '\0';
	num_len--;
	while (num > 0)
	{
		c = num % 8;
		if (c < 8)
			oct[num_len] = c + '0';
		num_len--;
		num /= 8;
	}
	count = ft_putstr(oct);
	return (count);
}
