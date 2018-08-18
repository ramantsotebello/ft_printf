/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:33:54 by tramants          #+#    #+#             */
/*   Updated: 2018/08/18 05:23:56 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	long unsigned int i;
	size_t  x;
	size_t 	y;

	i = 4294967296;

	x = printf("%s  This is %s  %s%s%s", "1", "2", "3", "4", "5");
	y = ft_printf("%s  This is %s  %s%s%s", "1", "2", "3", "4", "5");
	//printf("%d\n", b);
	//printf("%d\n", x);
	//printf("0x%lx\n", a);
	//printf("sys: %-s\n", "This string");
	//ft_printf("me : %-s\n", "This string");
	//printf("%d", ft_printf("%c%c\n", c, c));
	printf("\nsys: this function printed %ld characters\n", x);
	ft_printf("\nme : this function printed %ld characters\n\n", y);
	//ft_printf("Hello World!\n%c\n%s\nNumber boi:%d\n\n%%\n", 'T', string, 23);
//	printf("Hello World!\n%c\n%s\nNumber boi:%d\n\n%%\n", 'T', string, 23);
	// printf("Hello World!\n%c\n%s\n", 'T', string);
	return (1);
}
