# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 17:53:28 by ufitzhug          #+#    #+#              #
#    Updated: 2024/07/22 19:56:17 by ufitzhug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ex01

SRC = main.cpp Span.cpp

HEADER = Span.hpp

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