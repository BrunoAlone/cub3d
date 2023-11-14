# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 12:39:46 by brolivei          #+#    #+#              #
#    Updated: 2023/11/14 15:08:20 by brolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g
LIBXFLAGS = -lX11 -lXext

MINILIBX = ../minilibx-linux/libmlx.a
CUB3D = cub3d

SRCS_CUB3D = main.c rayCasting.c ft_events.c mlx_handle.c movement.c initialize.c\
			rayCastingFirst.c rayCastingSecond.c\
			utils/ft_memcpy.c utils/ft_strdup.c utils/ft_strlen.c utils/ft_matrix.c

OBJS_CUB3D = $(SRCS_CUB3D:.c=.o)

all: $(MINILIBX) $(CUB3D)

$(MINILIBX):
				$(MAKE) -C ./minilibx-linux

$(CUB3D):		$(OBJS_CUB3D)
								$(CC) $(CCFLAGS) $(OBJS_CUB3D) ../minilibx-linux/libmlx.a -o $(CUB3D) $(LIBXFLAGS) -lm

%.o: %.c
				$(CC) $(CCFLAGS) -c $< -o $@

clean:
				rm -rf $(OBJS_CUB3D)

fclean: clean
				rm -rf $(CUB3D)
re: fclean all
