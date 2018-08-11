/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itao_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:32:55 by tramants          #+#    #+#             */
/*   Updated: 2018/08/11 16:22:47 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(size_t num, int base, int cap)
{
	char	*str;
	size_t	num_len;
	char	x;

	num_len = ft_number_len(num, base);
	str = (char*)malloc(sizeof(char) * num_len + 1);
	str[num_len] = '\0';
	num_len--;
	
	while (num > 0)
	{
		x = num % base;
		if (x < 10)
			str[num_len] = x + '0';
		else
			str[num_len] = x + ((cap == 1) ? 'A' : 'a')  - 10;
		num_len--;
		num /= base;
	}
	return (str);
}	
