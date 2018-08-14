# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tramants <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 15:01:33 by tramants          #+#    #+#              #
#    Updated: 2018/08/14 10:33:11 by tramants         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
OBJ = *.o
DEPS = ft_printf.h ft_printf.c ft_putstr.c ft_putchar.c ft_putnbr.c \
	   ft_itoa_base.c ft_puthex.c ft_put_wide_str.c ft_number_len.c \
	   ft_put_wide_char.c ft_basic_oc.c ft_check_options.c ft_putoct.c \
	   ft_handleopt_oc.c ft_itoa.c ft_putstr_opt.c ft_strdup.c main.c
NAME = ft_printf


make: 
	gcc $(FLAGS) $(DEPS)

re: fclean
	make

fclean: 
	rm a.out

clean: 
	rm -f *.o

re: fclean all clean 
