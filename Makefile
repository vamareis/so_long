# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 17:05:27 by vamachad          #+#    #+#              #
#    Updated: 2024/08/06 17:05:29 by vamachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = find_path.c get_map.c hook_and_loop.c initialize.c main.c map_check.c player.c render_map.c utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = so_long

# Library paths
LIBFT_DIR = libft
MLX_DIR = mlx

# Library files
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Include paths
INCLUDES = -I$(LIBFT_DIR) -I$(MLX_DIR)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Build mlx
$(MLX):
	make -C $(MLX_DIR)

# Clean up object files and executable
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(TARGET)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
