NAME = FdF

OBJ_DIR = objs

SRCS =	main/binds.c \
	main/bresenham.c \
    main/change_height.c \
    main/ft_diff.c \
    main/get_limit.c \
    main/put_pixel.c \
    main/rotate_axis.c \
    main/rrotate_axis.c \
    main/translate.c \
    main/draw.c \
    main/ft_free.c \
    main/gradient.c \
    main/init.c \
    main/isometric.c \
    main/main.c \
    main/math_functions.c \
    main/read_file.c \
    main/rotate.c \
	main/put_line.c \
    main/scale_offset.c

OBJS = $(SRCS:main/%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iminilibx-linux -march=native -Ofast -g
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

MLX_DIR = minilibx-linux
LIBFT_DIR = Libft

all: $(NAME)

$(MLX_DIR)/libmlx.a: $(MLX_DIR)/Makefile
	cd $(MLX_DIR) && $(MAKE)

$(LIBFT_DIR)/libft.a: 
	cd $(LIBFT_DIR) && $(MAKE)

# Create the objs folder before compiling
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJS) $(MLX_DIR)/libmlx.a $(LIBFT_DIR)/libft.a
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(LIBFT_DIR)/libft.a

$(OBJ_DIR)/%.o: main/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)
	cd $(MLX_DIR) && $(MAKE) clean
	cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd $(MLX_DIR) && $(MAKE) clean
	cd $(LIBFT_DIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re

