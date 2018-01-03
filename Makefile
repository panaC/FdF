# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 13:59:37 by pierre            #+#    #+#              #
#    Updated: 2018/01/03 17:33:58 by pleroux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC=/usr/include
HT=Linux
DOCP=do_cp
UNAME_S= $(shell uname -s)
INCLIB=$(INC)/../lib

CC=gcc
LIB= libft/libft.a
LIB_PATH = libft/
ifeq ($(UNAME_S), Linux)
	CFLAGS= -I$(INC) -Iminilibx/ -Ilibft/includes -Wall -Werror -Wextra
	LIB_FLAGS= -Lminilibx/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -Llibft/ -lft
else
	CFLAGS= -I$(INC) -Iminilibx_macos/ -Ilibft/includes -Wall -Werror -Wextra
	LIB_FLAGS= -lm -Llibft/ -lft -Lminilibx_macos/ -lmlx -framework OpenGL -framework AppKit
endif
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

$(LIB)	:
	make -C $(LIB_PATH)

$(NAME)	: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB_FLAGS)

clean	:
	rm -f $(OBJ)
	make -C libft/ fclean

fclean	: clean
	rm -f $(NAME)

re		: clean all

.PHONY : all clean re fclean BUILD $(LIB)
