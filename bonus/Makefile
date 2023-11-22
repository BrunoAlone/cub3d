NAME = cub3d

MINILIBX = ../minilibx-linux/libmlx.a

SRC = cub.c checks.c utils.c check_type.c utils2.c\
		game.c rayCasting.c ft_events.c mlx_handle.c movement.c initialize.c\
		rayCastingFirst.c rayCastingSecond.c tex_handle.c rotation.c minimap.c\

CC = cc -g
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBXFLAGS = -lX11 -lXext
AR = ar rcs

OBJ = $(SRC:%.c=%.o)
BONUS_OBJ = $(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
								$(MAKE) -C ../minilibx-linux
								$(MAKE) -C ./Libft
								@$(CC) $(CFLAGS) $(OBJ) ../minilibx-linux/libmlx.a ./Libft/libft.a -o $(NAME) $(LIBXFLAGS) -lm

clean:
		$(MAKE) clean -C ./Libft
		@$(RM) $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./Libft
		@$(RM) $(NAME)

re: fclean all
		$(MAKE) re -C ./Libft
