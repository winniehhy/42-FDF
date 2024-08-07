# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 13:32:43 by hheng             #+#    #+#              #
#    Updated: 2024/07/22 13:32:45 by hheng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
SRC_DIR = srcs
OBJ_DIR = objs
INCLUDE_DIR = includes
LIBFT_DIR = ./libft

# Detect the operating system
UNAME_S := $(shell uname -s)

# Conditional settings for macOS and Linux
ifeq ($(UNAME_S), Darwin)
    MLX_INCLUDE_DIR = ./minilibx_macos
    MLX_LIB_FLAGS = -L$(MLX_INCLUDE_DIR) -lmlx -framework OpenGL -framework AppKit
else
    MLX_INCLUDE_DIR = ./minilibx-linux
    MLX_LIB_FLAGS = -L$(MLX_INCLUDE_DIR) -lmlx -lm -lX11 -lXext
endif

# List of source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
# List of object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Main target
fdf: $(LIBFT_DIR)/libft.a $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(MLX_LIB_FLAGS) -L$(LIBFT_DIR) -lft

# Rule to compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_DIR) -I$(MLX_INCLUDE_DIR) -I$(LIBFT_DIR)

# Create the objects directory if it does not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile libft
$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

# Clean target
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Distclean target
distclean: clean
	rm -f fdf

fclean: clean
	rm -f fdf
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Phony targets
.PHONY: clean distclean fclean
