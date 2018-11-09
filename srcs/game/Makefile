# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmace <cmace@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 12:18:12 by lguiller          #+#    #+#              #
#    Updated: 2018/11/09 10:33:02 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

OPE_SYS					= $(shell uname)
NAME					= doom-nukem
SRCS_FILES				= $(addsuffix .c, main bresenham display print_env \
						  check_and_stock_map init minimap raycasting copy_struct \
						  input_device movements to_map)
SRCS					= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS					= $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))
SRCS_DIR				= srcs/
OBJS_DIR				= objs/
LIBFT_DIR				= libft/
MLX_DIR					= minilibx/
LIBFT					= $(LIBFT_DIR)/libft.a
MLX						= $(MLX_DIR)/libmlx.a
INCLUDES				= -I includes -I $(LIBFT_DIR) -I $(MLX_DIR) -I ../../
FRAMEWORK				= -framework OpenGL -framework Appkit
SDL_FOLDER				= $(HOME)/goinfre/sdl/
SDL_MAIN_OBJ_LIBS		= libSDL2.a
SDL_IMAGE_OBJ_LIBS		= libSDL2_image.a
SDL_MAIN_FOLDER			= $(SDL_MAIN_VERSION:.tar.gz=)
SDL_MAIN_LIBS			= $(SDL_FOLDER)lib/
SDL_IMAGE_LIBS			= $(SDL_FOLDER)lib/
SDL_IMAGE_FOLDER		= $(SDL_IMAGE_VERSION:.tar.gz=)
SDL_IMAGE_INCLUDE_PATH	= $(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/
SDL_MAIN_INCLUDE_PATH	= $(SDL_FOLDER)$(SDL_MAIN_FOLDER)/include/
SDL_IMAGE				= $(addprefix $(SDL_IMAGE_LIBS), $(SDL_IMAGE_OBJ_LIBS))
SDL_MAIN				= $(addprefix $(SDL_MAIN_LIBS), $(SDL_MAIN_OBJ_LIBS))
FLAGS					= -Wall -Wextra -Werror -g

##################
##    COLORS    ##
##################

_BLACK		= "\033[30m"
_RED		= "\033[31m"
_GREEN		= "\033[32m"
_YELLOW		= "\033[33m"
_BLUE		= "\033[34m"
_VIOLET		= "\033[35m"
_CYAN		= "\033[36m"
_WHITE		= "\033[37m"
_END		= "\033[0m"
_CLEAR		= "\033[2K"
_HIDE_CURS	= "\033[?25l"
_SHOW_CURS	= "\033[?25h"
_UP			= "\033[A"
_CUT		= "\033[k"

##################
##   TARGETS    ##
##################

.PHONY: all create_dir clean fclean re norme

all: $(NAME)

$(NAME): create_dir $(OBJS)
	@gcc $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(FRAMEWORK) $(MINILIBX) -I $(SDL_MAIN_INCLUDE_PATH) \
		-L $(SDL_MAIN_LIBS) -lSDL2 -I$(SDL_IMAGE_INCLUDE_PATH) -L $(SDL_IMAGE_LIBS) \
		-lSDL2_image -o ../../$(NAME)
	@echo $(_CLEAR)$(_YELLOW)"building - "$(_GREEN)$(NAME)$(_END)
	@echo $(_GREEN)"Done."$(_END)$(_SHOW_CURS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@gcc $(FLAGS) $(INCLUDES) -c $^ -o $@

create_dir:
	@mkdir -p objs/

clean:
	@/bin/rm -rf $(OBJS_DIR)

fclean: clean
	@/bin/rm -f ../../$(NAME)

re:
	@$(MAKE) -s fclean
	@$(MAKE) -s

norme:
	@norminette srcs/*.c includes/*.h
