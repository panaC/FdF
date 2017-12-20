# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 13:59:37 by pierre            #+#    #+#              #
#    Updated: 2017/12/20 12:20:41 by pierre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC=/usr/include
HT=Linux
DOCP=do_cp

INCLIB=$(INC)/../lib

CC=gcc
LIB= libft
CFLAGS= -I$(INC) -Iminilibx/ -Ilibft/includes
NAME= fdf
SRC_DIR = src/
SRC_FILE = main.c draw.c parser.c it.c init.c calcul.c arg.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ = $(SRC:.c=.o)

all		: $(LIB) $(NAME)

$(NAME)	: $(OBJ)
	make -C $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -Lminilibx/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -Llibft/ -lft

clean	:
	rm -f $(NAME) $(OBJ) *~ core *.core
	make -C libft/ fclean

re		: clean all
