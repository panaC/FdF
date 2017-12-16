# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 13:59:37 by pierre            #+#    #+#              #
#    Updated: 2017/12/16 10:19:12 by pierre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC=/usr/include
HT=Linux
DOCP=do_cp

INCLIB=$(INC)/../lib

CC=gcc

CFLAGS= -I$(INC) -Iminilibx/ -Ilibft/includes
NAME= mlx-test
SRC = main.c vector.c matrix.c draw.c parser.c it.c init.c calcul.c
OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -Lminilibx/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -Llibft/ -lft

clean	:
	rm -f $(NAME) $(OBJ) *~ core *.core


re	: clean all
