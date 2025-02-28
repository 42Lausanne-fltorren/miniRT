SRC = $(wildcard src/**/*.c) $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -Isrc -lm

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX	= mlx_linux/libmlx_Linux.a

NAME = miniRT

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) bonus

$(MLX):
	cd mlx_linux && ./configure && make

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT)

run: all
	./$(NAME) scenes/minimal.rt

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re