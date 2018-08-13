/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 09:47:01 by tramants          #+#    #+#             */
/*   Updated: 2018/08/13 18:53:11 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_puthex(size_t num, int cap)
{
	char	*hex;
	size_t	num_len;
	char	c;
	char	alpha;
	int		count;

	alpha = (cap == 1) ? 'A' : 'a';
	num_len = ft_number_len(num, 16);
	hex = (char*)malloc(sizeof(char) * num_len + 1);
	hex[num_len] = '\0';
	num_len--;
	while (num > 0)
	{
		c = num % 16;
		if (c < 10)
			hex[num_len] = c + '0';
		else
			hex[num_len] = c + alpha - 10;
		num_len--;
		num /= 16;
	}
	if (cap == 2)
		ft_putstr("0x");
	count = ft_putstr(hex);
	return (count);
}
