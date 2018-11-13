# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmace <cmace@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 12:18:12 by lguiller          #+#    #+#              #
#    Updated: 2018/11/13 16:50:19 by cmace            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

OPE_SYS					= $(shell uname)
NAME					= editor
SRCS_FILES				= $(addsuffix .c, main init events tools make_grid refresh_events \
							check_frame init2 clear start_draw draw tools2 stock_map)
SRCS					= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS					= $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))
SRCS_DIR				= srcs/
OBJS_DIR				= objs/
LIBFT_DIR				= libft
LIBVECT_DIR				= libvect
LIBFT					= $(LIBFT_DIR)/libft.a
LIBVECT					= $(LIBVECT_DIR)/libvect.a
INCLUDES				= -I includes -I $(LIBFT_DIR) -I $(LIBVECT_DIR) -I $(SDL_MAIN_INCLUDE_PATH) -I $(SDL_IMAGE_INCLUDE_PATH) -I $(SDL_TTF_INCLUDE_PATH) -I $(FREETYPE_INCLUDE_PATH)
FRAMEWORK				= -framework OpenGL -framework Appkit
SDL_FOLDER				= $(HOME)/sdl/
SDL_MAIN_OBJ_LIBS		= libSDL2.a
SDL_IMAGE_OBJ_LIBS		= libSDL2_image.a
FREETYPE_OBJ_LIBS		= libfreetype.a
SDL_TTF_OBJ_LIBS		= libSDL2_ttf.a
SDL_MAIN_VERSION		= SDL2-2.0.8.tar.gz
SDL_IMAGE_VERSION		= SDL2_image-2.0.3.tar.gz
SDL_TTF_VERSION			= SDL2_ttf-2.0.14.tar.gz
FREETYPE_VERSION		= freetype-2.8.1.tar.gz
SDL_MAIN_FOLDER			= $(SDL_MAIN_VERSION:.tar.gz=)
SDL_IMAGE_FOLDER		= $(SDL_IMAGE_VERSION:.tar.gz=)
FREETYPE_FOLDER			= $(FREETYPE_VERSION:.tar.gz=)
SDL_TTF_FOLDER			= $(SDL_TTF_VERSION:.tar.gz=)
SDL_MAIN_LIBS			= $(SDL_FOLDER)$(SDL_MAIN_FOLDER)/lib
SDL_IMAGE_LIBS			= $(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/lib
SDL_TTF_LIBS			= $(SDL_FOLDER)$(SDL_TTF_FOLDER)/lib
FREETYPE_LIBS			= $(SDL_FOLDER)$(FREETYPE_FOLDER)/build/lib
SDL_TTF_INCLUDE_PATH	= $(SDL_FOLDER)$(SDL_TTF_FOLDER)/
FREETYPE_INCLUDE_PATH	= $(SDL_FOLDER)$(FREETYPE_FOLDER)/
SDL_IMAGE_INCLUDE_PATH	= $(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/
SDL_MAIN_INCLUDE_PATH	= $(SDL_FOLDER)$(SDL_MAIN_FOLDER)/include/
SDL_IMAGE				= $(addprefix $(LIBS), $(SDL_IMAGE_OBJ_LIBS))
SDL_MAIN				= $(addprefix $(LIBS), $(SDL_MAIN_OBJ_LIBS))
SDL_TTF					= $(addprefix $(LIBS), $(SDL_TTF_OBJ_LIBS))
FREETYPE				= $(addprefix $(LIBS), $(FREETYPE_OBJ_LIBS))
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
	echo $(SDL_MAIN_LIBS)
	echo $(SDL_IMAGE_LIBS)
	echo $(SDL_TTF_LIBS)
	echo $(FREETYPE_LIBS)
	@gcc $(FLAGS) $(OBJS) $(LIBFT) $(LIBVECT) $(FRAMEWORK) $(MINILIBX) -I $(SDL_MAIN_INCLUDE_PATH) \
		-L $(SDL_MAIN_LIBS) -lSDL2 -I$(SDL_IMAGE_INCLUDE_PATH) -L $(SDL_IMAGE_LIBS) \
		-lSDL2_image -I $(FREETYPE_INCLUDE_PATH) -L $(FREETYPE_LIBS) -lfreetype -I $(SDL_TTF_INCLUDE_PATH) -L $(SDL_TTF_LIBS) -lSDL2_ttf\
		-o ../../$(NAME)
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
