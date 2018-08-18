# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tramants <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 15:01:33 by tramants          #+#    #+#              #
#    Updated: 2018/08/17 23:55:05 by tramants         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
OBJ = *.o
DEPS = ft_printf.c ft_putstr.c ft_putchar.c ft_putnbr.c \
	   ft_itoa_base.c ft_puthex.c ft_put_wide_str.c ft_nlen.c \
	   ft_put_wide_char.c ft_basic_oc.c ft_check_options.c ft_putoct.c \
	   ft_handleopt_oc.c ft_itoa.c ft_putstr_opt.c
NAME = libftprintf.a
HEADER = ft_printf.h

all: $(NAME)

$(NAME):
	gcc -c $(DEPS) -I $(HEADER)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean: clean 
	rm -f *.a

re: fclean clean all

local: 
	gcc $(FLAGS) $(DEPS) main.c

clocal: 
	rm -f a.out
	rm -f ft_print.h.gch
