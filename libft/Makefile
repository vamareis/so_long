#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vamachad <vamachad@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 14:52:59 by vamachad          #+#    #+#              #
#    Updated: 2024/04/30 19:07:53 by vamachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_calloc.c ft_strdup.c ft_strncmp.c \
    ft_strtrim.c ft_itoa.c ft_putstr_fd.c ft_putendl_fd.c \
    get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
    ft_printf/ft_printf.c ft_printf/print_address.c ft_printf/print_nbr.c \
    ft_printf/print_char.c ft_printf/print_string.c ft_printf/print_unsigned.c \
    get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c
OBJS = ${SRCS:.c=.o}
NAME = libft.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

# Rule to compile everything
all: $(NAME)

# Compiles the library
$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

# Generic rule for compiling .c to .o, with dependency on header files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files
clean:
	$(RM) $(OBJS)

# Rule to fully clean the library and object files
fclean: clean
	$(RM) $(NAME)

# Rule to re-make everything
re: fclean all

.PHONY: all clean fclean re