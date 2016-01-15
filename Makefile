# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/03 22:11:07 by fjanoty           #+#    #+#              #
#    Updated: 2016/01/15 19:36:33 by fjanoty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all, clean, fclean, re

.SUFFIXES:

NAME = bsq

S = big_sqr_data.c\
	copie_first_line.c\
	first_line.c\
	ft_create_elem.c\
	ft_ft.c\
	ft_list_clear.c\
	ft_list_push_back.c\
	ft_list_size.c\
	get_the_structure.c\
	init_val.c\
	main.c\
	print_file.c\
	print_the_result.c\
	search_the_big_one.c

SRC = $(addprefix srcs/,$(S))

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc $(FLAG) $(SRC) -I includes -o $(NAME)
clean :

fclean :
	rm -f $(NAME)
re : fclean all

