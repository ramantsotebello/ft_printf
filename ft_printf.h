/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ramants <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:57:26 by tramants          #+#    #+#             */
/*   Updated: 2018/08/13 18:53:18 by tramants         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <wchar.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_put_wide_str(const wchar_t *str);
int	ft_put_wide_char(wchar_t c);
int	ft_putnbr(long n);
int	ft_is_outputc(char c);
int	ft_isflag(char c);
int	ft_isprecision(char c);
int	ft_iswidth(char c);
int	ft_putoct(size_t num);
int	ft_printf(const char *format, ...);
int	ft_puthex(size_t num, int cap);
int	ft_basic_oc(va_list args, char c);
size_t	ft_number_len(size_t x, int base);
char	*ft_itoa_base(size_t num, int base, int cap);
struct	ol ft_check_options(char *str, int index);
int	ft_handleopt_oc(va_list args, char *s, struct ol, int i);
struct	ol {
	char	flags[12];
	int	width;
	int	precision;
	char	length[10];
	char	type;
} options_list; 
#endif
