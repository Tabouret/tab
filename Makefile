# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollier <pollier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/08/18 15:39:46 by elacombe          #+#    #+#              #
#    Updated: 2014/08/21 23:00:14 by pollier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAG = -Wall -Werror -Wextra -I$(HEADERS)

HEADERS = ./includes

NAME = bsq

SRC = bsqplusplus.c trucs.c trucs2.c trucs3.c

OBJ = bsqplusplus.o trucs.o trucs2.o trucs3.o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) $(HEADERS) -c $(SRC)
	$(CC) $(CFLAG) $(HEADERS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rf -f $(NAME)

re: fclean $(NAME)
