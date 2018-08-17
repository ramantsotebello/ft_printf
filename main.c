/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:33:54 by tramants          #+#    #+#             */
/*   Updated: 2018/08/16 11:32:59 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

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
	wchar_t	*z;0000
	a = (long)string;
	b = 15;
	c = 'T';
	w = L'z';
	d = 10;
	z = L"漢字";
	e = 5;*/
	//setlocale(LC_ALL, "en_GB");
	//wchar_t w  = L'漢';
	long int x = 1200003;

	printf("sys: |%-+ld\n%c\n", x, 'T');
	ft_printf("me : |%-+ld\n%c\n", x, 'T');
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
