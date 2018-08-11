/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:33:54 by tramants          #+#    #+#             */
/*   Updated: 2018/08/11 16:22:43 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char	*string = "Tebello";
	long 	a;
	int		b;
	//int		x;
	//int		y;	
	wchar_t	w;

	a = (long)string;
	b = -15;
	w = L'z';

	
	//printf("%d\n", b);
	//printf("%d\n", x);
	//printf("0x%lx\n", a);
	printf("sys: % 020d", b);
	//ft_printf("me : %ld\n", a);
	//printf("sys: this function printed %d characters\n", x);
	//ft_printf("me : this function printed %d characters\n", y);
	//ft_printf("Hello World!\n%c\n%s\nNumber boi:%d\n\n%%\n", 'T', string, 23);
//	printf("Hello World!\n%c\n%s\nNumber boi:%d\n\n%%\n", 'T', string, 23);
	// printf("Hello World!\n%c\n%s\n", 'T', string);
	return (1);
}
