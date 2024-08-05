# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 22:47:18 by ufitzhug          #+#    #+#              #
#    Updated: 2024/08/05 22:48:13 by ufitzhug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

SRC = main.cpp

HEADER = MutantStack.hpp

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