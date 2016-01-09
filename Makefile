# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/03 22:11:07 by fjanoty           #+#    #+#              #
#    Updated: 2015/12/28 19:03:52 by fjanoty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all, clean, fclean, re

.SUFFIXES:

NAME = ft_display_file

S = main.c

O = $(S:.c=.o)

#SRC = $(addprefix srcs/,$(S))

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror $(S) -o $(NAME)
clean :
	rm -f nothing
fclean : clean
	rm -f $(NAME)

