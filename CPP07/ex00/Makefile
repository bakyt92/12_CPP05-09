# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 19:09:04 by ufitzhug          #+#    #+#              #
#    Updated: 2024/05/20 19:29:20 by ufitzhug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_template

SRC = main.cpp

HEADER = whatever.hpp

OBJ = $(SRC:%.cpp= %.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) -O2 $(OBJ) -o $(NAME)

%.o	: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -rf $(OBJ)

fclean	:	clean
	@rm -rf $(NAME)

re	:	fclean all

.PHONY : all clean fclean re 