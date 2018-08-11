/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wide_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 14:04:38 by tramants          #+#    #+#             */
/*   Updated: 2018/08/11 14:05:44 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_wide_str(const wchar_t *str)
{
	int		count;

	count = 0;
	while(str[count])
	{
		write(1, &str[count],1);
		count++;
	}
	return (count);
}
