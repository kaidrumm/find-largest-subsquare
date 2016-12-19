# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asosnov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/01 23:18:50 by asosnov           #+#    #+#              #
#    Updated: 2016/08/01 23:18:56 by asosnov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = bsq
SRC = main.c stack.c libfiles.c search.c extra.c
CFLAGS += -Wall -Wextra -Werror
HEADER = bsq.h

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(CFLAGS) $(SRC)

clean:
	/bin/rm -f $(SRC:.c=.o)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
