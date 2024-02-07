# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 16:54:30 by hemottu           #+#    #+#              #
#    Updated: 2024/02/02 20:01:56 by hemottu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus
CC = clang
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	inc/
SRC_DIR_BONUS = src_bonus/
OBJ_DIR_BONUS = obj_bonus/
INC_DIR_BONUS = inc_bonus/

RESET		=	\033[0m
GREEN		=	\033[32m

SRC_FILES =		main.c \
				init.c \
				window.c \
				free.c \
				signals.c \
				rotate.c \
				moves.c \
				textures.c \
				draw/draw_img.c \
				draw/set_pixel.c \
				draw/colors.c \
				draw/draw_walls.c \
				raycast.c \
				parsing/set_first_position.c \
				parsing/parsing.c \
				parsing/file_handling.c \
				parsing/map_checks.c \
				parsing/map_checks_2.c \
				parsing/utils.c \
				parsing/texture_checks.c \
				parsing/utils_2.c

SRC_FILES_BONUS =	main_bonus.c \
					init_bonus.c \
					window_bonus.c \
					free_bonus.c \
					signals_bonus.c \
					rotate_bonus.c \
					moves_bonus.c \
					textures_bonus.c \
					draw_bonus/draw_img_bonus.c \
					draw_bonus/set_pixel_bonus.c \
					draw_bonus/colors_bonus.c \
					draw_bonus/draw_minimap_bonus.c \
					draw_bonus/draw_walls_bonus.c \
					raycast_bonus.c \
					parsing_bonus/set_first_position_bonus.c \
					parsing_bonus/parsing_bonus.c \
					parsing_bonus/file_handling_bonus.c \
					parsing_bonus/map_checks_bonus.c \
					parsing_bonus/map_checks_2_bonus.c \
					parsing_bonus/utils_bonus.c \
					parsing_bonus/texture_checks_bonus.c \
					parsing_bonus/utils_2_bonus.c

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_FILES_BONUS = $(SRC_FILES_BONUS:.c=.o)

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
SRC_BONUS	=	$(addprefix $(SRC_DIR_BONUS), $(SRC_FILES_BONUS))
OBJ_BONUS	=	$(addprefix $(OBJ_DIR_BONUS), $(OBJ_FILES_BONUS))

MLX = minilibx-linux/libmlx.a

LIBFT = libft/libft.a

DEPS = $(OBJ:.o=.d)

all: $(NAME)
	@printf "\n$(GREEN)"
	@printf "      _     _           ____  _____\n"
	@printf "     | |   (_)         |___ \|  __ \ \n"
	@printf "  ___| |__  _ _ __  ___  __) | |  | |\n"
	@printf " / __| '_ \| | '_ \/ __||__ <| |  | |\n"
	@printf "| (__| | | | | |_) \__ \___) | |__| |\n"
	@printf " \___|_| |_|_| .__/|___/____/|_____/ \n"
	@printf "             | |  \n"
	@printf "             |_| $(RESET)\n"
	@printf "\n"

bonus: $(NAME_BONUS)
	@printf "\n$(GREEN)"
	@printf "      _     _           ____  _____  _ \n"
	@printf "     | |   (_)         |___ \|  __ \| |\n"
	@printf "  ___| |__  _ _ __  ___  __) | |  | | |__   ___  _ __  _   _ ___  \n"
	@printf " / __| '_ \| | '_ \/ __||__ <| |  | | '_ \ / _ \| '_ \| | | / __| \n"
	@printf "| (__| | | | | |_) \__ \___) | |__| | |_) | (_) | | | | |_| \__ \ \n"
	@printf " \___|_| |_|_| .__/|___/____/|_____/|_.__/ \___/|_| |_|\__,_|___/ \n"
	@printf "             | |  \n"
	@printf "             |_| $(RESET)\n"
	@printf "\n"

$(NAME): $(OBJ) $(MLX) $(HEADERS) $(LIBFT)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) -lX11 -lm -lXext -Lminilibx-linux/ -lmlx -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(MLX) $(HEADERS) $(LIBFT)
	$(CC) $(OBJ_BONUS) $(CFLAGS) $(LIBFT) -lX11 -lm -lXext -Lminilibx-linux/ -lmlx -o $(NAME_BONUS)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -MP -I $(INC_DIR) -Iminilibx-linux/ -I libft/include/ -o $@ -c $<

$(OBJ_DIR_BONUS)%.o:$(SRC_DIR_BONUS)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -MP -I $(INC_DIR_BONUS) -Iminilibx-linux/ -I libft/include/ -o $@ -c $<

-include $(DEPS)

$(MLX): 
	make -C minilibx-linux	

$(LIBFT):
	make -C libft


clean:
	rm -rf $(OBJ) $(OBJ_DIR) $(OBJ_DIR_BONUS)
	make clean -C minilibx-linux
	make clean -C libft

fclean:	clean
	rm -rf $(NAME) $(NAME_BONUS) $(MLX) $(LIBFT)

re: fclean all

.PHONY:	all re clean fclean bonus
