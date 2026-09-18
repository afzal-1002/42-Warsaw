# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/30 00:00:00 by mafzal            #+#    #+#              #
#    Updated: 2026/01/01 21:45:02 by mafzal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a
MLX = ./minilibx-linux/libmlx.a
MLX_FLAGS = -L./minilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

OBJ_DIR = obj
OBJ_BONUS_DIR = obj/bonus


SRC_FILES = main.c init_game.c parse_map.c validate_map.c \
			check_path.c map_utils.c render.c movement.c \
			exit.c utils.c textures.c

SRC_BONUS_FILES = main_bonus.c init_game_bonus.c parse_map_bonus.c \
				  validate_map_bonus.c check_path_bonus.c map_utils_bonus.c \
				  render_bonus.c movement_bonus.c animation_bonus.c \
				  enemy_bonus.c exit_bonus.c utils_bonus.c textures_bonus.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS_FILES:.c=.o))

all: $(LIBFT) $(MLX) $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

bonus: $(LIBFT) $(MLX) $(OBJ_BONUS_DIR) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	mkdir -p $(OBJ_BONUS_DIR)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I./includes -I./libft -I./minilibx-linux -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: src_bonus/%.c | $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) -I./includes -I./libft -I./minilibx-linux -c $< -o $@

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./minilibx-linux

clean:
	rm -rf $(OBJ_DIR)
	make -C ./libft clean
	make -C ./minilibx-linux clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C ./libft fclean

re: fclean all

.PHONY: all bonus clean fclean re
