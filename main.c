/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:33:54 by tramants          #+#    #+#             */
/*   Updated: 2018/08/10 17:23:59 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char	*string = "Tebello";
	long 	a;

	a = (long)string;
	
	//printf("%p\n", string);
	//printf("0x%lx\n", a);
	printf("% d",-2);
//	ft_printf("Hello World!\n%c\n%s\nNumber boi:%d\n\n%%\n", 'T', string, 23);
//	printf("Hello World!\n%c\n%s\nNumber boi:%d\n\n%%\n", 'T', string, 23);
	// printf("Hello World!\n%c\n%s\n", 'T', string);
	return (1);
}
