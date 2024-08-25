SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -Isrc -lm

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_PATH = ./mlx
MLX = $(MLX_PATH)/libmlx.a
INCLUDE += -Imlx

NAME = miniRT

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDE) $(MLX_FLAGS) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_PATH) bonus

$(MLX):
	make -C $(MLX_PATH)
	cp $(MLX_PATH)/libmlx.a .

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re