# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 13:59:37 by pierre            #+#    #+#              #
#    Updated: 2017/12/20 18:21:50 by pierre           ###   ########.fr        #
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
SRC_FILE = main.c \
		   draw.c \
		   parser.c \
		   it.c init.c \
		   calcul.c \
		   arg.c \
		   calc_rot.c \
		   calc_tr.c \
		   calc_size.c
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
