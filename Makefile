# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elacombe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/08/18 15:39:46 by elacombe          #+#    #+#              #
#    Updated: 2014/08/18 15:45:03 by elacombe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAG = -Wall -Werror -Wextra -I$(HEADERS)

HEADERS = ./includes

NAME = bsq

SRC = bsq.c fonctions.c put.c

OBJ = bsq.o fonctions.o put.o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) $(HEADERS) -c $(SRC)
	$(CC) $(CFLAG) $(HEADERS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rf -f $(NAME)

re: fclean $(NAME)
