# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 02:19:42 by ufitzhug          #+#    #+#              #
#    Updated: 2024/05/19 03:03:45 by ufitzhug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer_com

SRC = main.cpp Serializer.cpp

HEADER = Serializer.hpp

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