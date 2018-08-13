/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:33:54 by tramants          #+#    #+#             */
/*   Updated: 2018/08/13 18:53:19 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char	*string = "Tebello";
	long 	a;
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
	e = 5;

	
	//printf("%d\n", b);
	//printf("%d\n", x);
	//printf("0x%lx\n", a);
	printf("sys: %C\n", L'字');
//	ft_printf("me : %S\n", z);
	//printf("%d", ft_printf("%c%c\n", c, c));
	//printf("sys: this function printed %d characters\n", x);
	//ft_printf("me : this function printed %d characters\n", y);
	//ft_printf("Hello World!\n%c\n%s\nNumber boi:%d\n\n%%\n", 'T', string, 23);
//	printf("Hello World!\n%c\n%s\nNumber boi:%d\n\n%%\n", 'T', string, 23);
	// printf("Hello World!\n%c\n%s\n", 'T', string);
	return (1);
}
