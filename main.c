/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:33:54 by tramants          #+#    #+#             */
/*   Updated: 2018/08/14 17:38:28 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
//	wchar_t	*string = L"Tebello";
/*	long 	a;
	long long d;
	short	e;
	int		b;
	char	c;
	//int		x;
	//int		y;	
	wchar_t	w;
	wchar_t	*z;

	a = (long)string;
	b = 15;
	c = 'T';
	w = L'z';
	d = 10;
	z = L"漢字";
	e = 5;*/

	//string[0] = 'R';
	//printf("%s\n", string);	
	printf("%-10.2s\n", "This is the string");
	ft_printf("%-10.2s\n", "This is the string");
	//printf("%d\n", b);
	//printf("%d\n", x);
	//printf("0x%lx\n", a);
	//printf("sys: %-s\n", "This string");
	//ft_printf("me : %-s\n", "This string");
	//printf("%d", ft_printf("%c%c\n", c, c));
	//printf("sys: this function printed %d characters\n", x);
	//ft_printf("me : this function printed %d characters\n", y);
	//ft_printf("Hello World!\n%c\n%s\nNumber boi:%d\n\n%%\n", 'T', string, 23);
//	printf("Hello World!\n%c\n%s\nNumber boi:%d\n\n%%\n", 'T', string, 23);
	// printf("Hello World!\n%c\n%s\n", 'T', string);
	return (1);
}
