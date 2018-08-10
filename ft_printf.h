/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:57:26 by tramants          #+#    #+#             */
/*   Updated: 2018/08/10 17:24:02 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putnbr(int num);
int		ft_printf(const char *format, ...);
int		ft_atoi(char *str);
struct	options_list	{
	char	flag[6];
	int		width;
	int		precision;
	int		length;
	char	type;
};
#endif
