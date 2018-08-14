/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:19:14 by tramants          #+#    #+#             */
/*   Updated: 2018/08/14 07:06:34 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = ft_number_len(n, 10);
	if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	str[j] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i = i + 1;
	}
	while (i < j--)
	{
		str[j] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
