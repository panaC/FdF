# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 13:59:37 by pierre            #+#    #+#              #
#    Updated: 2018/01/11 09:53:27 by pleroux          ###   ########.fr        #
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
	LIB_MLX= minilibx/libmlx.a
	LIB_MLX_PATH = minilibx/
	CFLAGS= -I$(INC) -I$(LIB_MLX_PATH) -Ilibft/includes -Wall -Werror -Wextra
	LIB_FLAGS= -L$(LIB_MLX_PATH) -lmlx -L$(INCLIB) -lXext -lX11 -lm -L$(LIB_PATH) -lft
else
	LIB_MLX= minilibx_macos/libmlx.a
	LIB_MLX_PATH = minilibx_macos/
	CFLAGS= -I$(INC) -I$(LIB_MLX_PATH) -Ilibft/includes -Wall -Werror -Wextra
	LIB_FLAGS= -lm -L$(LIB_PATH) -lft -L$(LIB_MLX_PATH) -lmlx -framework OpenGL -framework AppKit
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
		   calc_size.c \
		   color.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ = $(SRC:.c=.o)

all		: $(LIB) $(LIB_MLX) $(NAME)

$(LIB)	:
	make -C $(LIB_PATH)

$(LIB_MLX) :
	make -C $(LIB_MLX_PATH)

$(NAME)	: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB_FLAGS)

clean	:
	rm -f $(OBJ)
	make -C libft/ fclean

fclean	: clean
	rm -f $(NAME)

re		: clean all

.PHONY : all clean re fclean BUILD $(LIB)
