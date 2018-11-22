# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmace <cmace@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 12:18:12 by lguiller          #+#    #+#              #
#    Updated: 2018/11/22 11:56:18 by cmace            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

OPE_SYS					= $(shell uname)
NAME					= doom-nukem
SRCS_FILES				= $(addsuffix .c, main bresenham display print_env \
						  check_and_stock_map init init2 minimap raycasting copy_struct \
						  input_device movements movements2 tools tools2)
SRCS					= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS					= $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))
SRCS_DIR				= srcs/
OBJS_DIR				= objs/
LIBFT_DIR				= libft
MLX_DIR					= minilibx
LIBVECT_DIR				= libvect
LIBFT					= $(LIBFT_DIR)/libft.a
MLX						= $(MLX_DIR)/libmlx.a
LIBVECT					= $(LIBVECT_DIR)/libvect.a
INCLUDES				= -I includes -I $(LIBFT_DIR) -I $(MLX_DIR) -I $(LIBVECT_DIR)\
							-I $(SDL_MAIN_INCLUDE_PATH) -I $(SDL_IMAGE_INCLUDE_PATH) \
							-I $(SDL_TTF_INCLUDE_PATH) -I $(FREETYPE_INCLUDE_PATH) \
							-I $(SDL_MIXER_INCLUDE_PATH)
FRAMEWORK				= -framework OpenGL -framework Appkit $(LIBFT) $(MLX) $(LIBVECT) \
							-I $(SDL_MAIN_INCLUDE_PATH) \
							-L $(SDL_MAIN_LIBS) -lSDL2 -I$(SDL_IMAGE_INCLUDE_PATH) \
							-L $(SDL_IMAGE_LIBS) -lSDL2_image -L $(SDL_TTF_LIBS) -lSDL2_ttf \
							-L $(FREETYPE_LIBS) -lfreetype -L $(SDL_MIXER_LIBS) -lSDL2_mixer
SDL_FOLDER				= $(HOME)/sdl/
SDL_MAIN_OBJ_LIBS		= libSDL2.a
SDL_IMAGE_OBJ_LIBS		= libSDL2_image.a
FREETYPE_OBJ_LIBS		= libfreetype.a
SDL_TTF_OBJ_LIBS		= libSDL2_ttf.a
SDL_MIXER_OBJ_LIBS		= libSDL2_mixer.a
SDL_MAIN_VERSION		= SDL2-2.0.8.tar.gz
SDL_IMAGE_VERSION		= SDL2_image-2.0.3.tar.gz
SDL_TTF_VERSION			= SDL2_ttf-2.0.14.tar.gz
FREETYPE_VERSION		= freetype-2.8.1.tar.gz
SDL_MIXER_VERSION		= SDL2_mixer-2.0.2.tar.gz
SDL_MAIN_FOLDER			= $(SDL_MAIN_VERSION:.tar.gz=)
SDL_IMAGE_FOLDER		= $(SDL_IMAGE_VERSION:.tar.gz=)
FREETYPE_FOLDER			= $(FREETYPE_VERSION:.tar.gz=)
SDL_TTF_FOLDER			= $(SDL_TTF_VERSION:.tar.gz=)
SDL_MIXER_FOLDER		= $(SDL_MIXER_VERSION:.tar.gz=)
SDL_MAIN_LIBS			= $(SDL_FOLDER)$(SDL_MAIN_FOLDER)/lib
SDL_IMAGE_LIBS			= $(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/lib
SDL_TTF_LIBS			= $(SDL_FOLDER)$(SDL_TTF_FOLDER)/lib
SDL_MIXER_LIBS			= $(SDL_FOLDER)$(SDL_MIXER_FOLDER)/lib
FREETYPE_LIBS			= $(SDL_FOLDER)$(FREETYPE_FOLDER)/build/lib
SDL_TTF_INCLUDE_PATH	= $(SDL_FOLDER)$(SDL_TTF_FOLDER)/include/SDL2
FREETYPE_INCLUDE_PATH	= $(SDL_FOLDER)$(FREETYPE_FOLDER)/include
SDL_IMAGE_INCLUDE_PATH	= $(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/include/SDL2
SDL_MAIN_INCLUDE_PATH	= $(SDL_FOLDER)$(SDL_MAIN_FOLDER)/include
SDL_MIXER_INCLUDE_PATH	= $(SDL_FOLDER)$(SDL_MIXER_FOLDER)/include/SDL2
TEST					= -Werror
FLAGS					= -Wall -Wextra $(TEST) -O2 -g

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
	@echo $(ARG)

$(NAME): create_dir $(OBJS)
	@gcc $(FLAGS) $(OBJS) $(FRAMEWORK) -o ../../$(NAME)
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
