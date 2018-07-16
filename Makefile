# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tramants <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 15:01:33 by tramants          #+#    #+#              #
#    Updated: 2018/07/16 17:46:03 by tramants         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
OBJ = *.o
DEPS = ft_printf.h ft_printf.c ft_putstr.c ft_putchar.c ft_putnbr.c main.c
NAME = ft_printf

make: 
	gcc $(FLAGS) $(DEPS)

fclean: clean
	rm $(NAME)

clean: 
	rm *.o
