# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 12:18:12 by lguiller          #+#    #+#              #
#    Updated: 2018/10/22 17:20:26 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

SDL_FOLDER =$(HOME)/goinfre/sdl/

SDL_MAIN_DOWNLOAD =https://www.libsdl.org/release/SDL2-2.0.8.tar.gz
SDL_MAIN_VERSION =SDL2-2.0.8.tar.gz
SDL_MAIN_FOLDER =$(SDL_MAIN_VERSION:.tar.gz=)

SDL_IMAGE_DOWNLOAD =https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.3.tar.gz
SDL_IMAGE_VERSION =SDL2_image-2.0.3.tar.gz
SDL_IMAGE_FOLDER =$(SDL_IMAGE_VERSION:.tar.gz=)

SDL_MIXER_DOWNLOAD =https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.2.tar.gz
SDL_MIXER_VERSION =SDL2_mixer-2.0.2.tar.gz
SDL_MIXER_FOLDER =$(SDL_MIXER_VERSION:.tar.gz=)

SDL_TTF_DOWNLOAD =https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.tar.gz
SDL_TTF_VERSION =SDL2_ttf-2.0.14.tar.gz
SDL_TTF_FOLDER =$(SDL_TTF_VERSION:.tar.gz=)

FREETYPE_DOWNLOAD =https://download.savannah.gnu.org/releases/freetype/freetype-2.8.1.tar.gz
FREETYPE_VERSION =freetype-2.8.1.tar.gz
FREETYPE_FOLDER =$(FREETYPE_VERSION:.tar.gz=)

SDL_MAIN_HEADER =SDL.h\
				 SDL_assert.h\
				 SDL_atomic.h\
				 SDL_audio.h\
				 SDL_bits.h\
				 SDL_blendmode.h\
				 SDL_cpuinfo.h\
				 SDL_egl.h\
				 SDL_endian.h\
				 SDL_error.h\
				 SDL_events.h\
				 SDL_filesystem.h\
				 SDL_gamecontroller.h\
				 SDL_gesture.h\
				 SDL_haptic.h\
				 SDL_hints.h\
				 SDL_joystick.h\
				 SDL_keyboard.h\
				 SDL_keycode.h\
				 SDL_loadso.h\
				 SDL_log.h\
				 SDL_main.h\
				 SDL_messagebox.h\
				 SDL_mouse.h\
				 SDL_mutex.h\
				 SDL_name.h\
				 SDL_opengl.h\
				 SDL_opengl_glext.h\
				 SDL_opengles.h\
				 SDL_opengles2_gl2ext.h\
				 SDL_opengles2_gl2.h\
				 SDL_opengles2_gl2platform.h\
				 SDL_opengles2.h\
				 SDL_opengles2_khrplatform.h\
				 SDL_pixels.h\
				 SDL_platform.h\
				 SDL_power.h\
				 SDL_quit.h\
				 SDL_rect.h\
				 SDL_render.h\
				 SDL_rwops.h\
				 SDL_scancode.h\
				 SDL_shape.h\
				 SDL_stdinc.h\
				 SDL_surface.h\
				 SDL_system.h\
				 SDL_syswm.h\
				 SDL_thread.h\
				 SDL_timer.h\
				 SDL_touch.h\
				 SDL_types.h\
				 SDL_version.h\
				 SDL_video.h\
				 SDL_vulkan.h\
				 begin_code.h\
				 close_code.h\

SDL_IMAGE_HEADER =SDL_image.h

SDL_MAIN_OBJ_LIBS =libSDL2.a

SDL_IMAGE_OBJ_LIBS =libSDL2_image.a

SDL_MAIN_LIBS_PATH =$(SDL_FOLDER)$(SDL_MAIN_FOLDER)/
SDL_MAIN_INCLUDE_PATH =$(SDL_FOLDER)$(SDL_MAIN_FOLDER)/include/
SDL_IMAGE_LIBS_PATH =$(SDL_FOLDER)$(SDL_MAIN_FOLDER)/
SDL_IMAGE_INCLUDE_PATH =$(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/

SDL_MAIN_INCLUDE= $(addprefix $(SDL_MAIN_INCLUDE_PATH), $(SDL_MAIN_HEADER))
SDL_MAIN_LIBS =$(SDL_FOLDER)lib/
SDL_MAIN =$(addprefix $(SDL_MAIN_LIBS), $(SDL_MAIN_OBJ_LIBS))
SDL_IMAGE_LIBS =$(SDL_FOLDER)lib/
SDL_IMAGE =$(addprefix $(SDL_IMAGE_LIBS), $(SDL_IMAGE_OBJ_LIBS))
SDL_IMAGE_INCLUDE = $(addprefix $(SDL_IMAGE_INCLUDE_PATH), $(SDL_IMAGE_HEADER))

CURL_PATH = curl -L

OBJS_DIR		= objs/
LIBFT_DIR		= libft/
GAME_DIR		= srcs/game/
EDITOR_DIR		= srcs/map_editor/

ifeq ($(OPE_SYS), Linux)
	MLX_DIR		= minilibx_x11
else
	MLX_DIR		= minilibx
endif

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

.PHONY: all title minilibx clean fclean re norme libft game editor

all: game

editor: libft
	@$(MAKE) -C $(EDITOR_DIR)

game: editor
	@$(MAKE) -C $(GAME_DIR)

minilibx: title
	@$(MAKE) -sC $(MLX_DIR) 2>/dev/null

libft: minilibx
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@$(MAKE) -sC $(MLX_DIR) clean
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(GAME_DIR) clean
	@$(MAKE) -sC $(EDITOR_DIR) clean

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@$(MAKE) -sC $(GAME_DIR) fclean
	@$(MAKE) -sC $(EDITOR_DIR) fclean

re:
	@$(MAKE) -s fclean
	@$(MAKE) -s

norme:
	@$(MAKE) -C $(GAME_DIR) norme
	@$(MAKE) -C $(EDITOR_DIR) norme

title:
	@echo $(_RED)
	@echo "◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆"
	@echo
	@echo "                     :::::::::   ::::::::   ::::::::    :::   :::        "
	@echo "                    :+:    :+: :+:    :+: :+:    :+:  :+:+: :+:+:        "
	@echo "                   +:+    +:+ +:+    +:+ +:+    +:+ +:+ +:+:+ +:+        "
	@echo "                  +#+    +:+ +#+    +:+ +#+    +:+ +#+  +:+  +#+         "
	@echo "                 +#+    +#+ +#+    +#+ +#+    +#+ +#+       +#+          "
	@echo "                #+#    #+# #+#    #+# #+#    #+# #+#       #+#           "
	@echo "               #########   ########   ########  ###       ###            "
	@echo
	@echo "          ::::    ::: :::    ::: :::    ::: ::::::::::   :::   :::       "
	@echo "         :+:+:   :+: :+:    :+: :+:   :+:  :+:         :+:+: :+:+:       "
	@echo "        :+:+:+  +:+ +:+    +:+ +:+  +:+   +:+        +:+ +:+:+ +:+       "
	@echo "       +#+ +:+ +#+ +#+    +:+ +#++:++    +#++:++#   +#+  +:+  +#+        "
	@echo "      +#+  +#+#+# +#+    +#+ +#+  +#+   +#+        +#+       +#+         "
	@echo "     #+#   #+#+# #+#    #+# #+#   #+#  #+#        #+#       #+#          "
	@echo "    ###    ####  ########  ###    ### ########## ###       ###           "
	@echo
	@echo "◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆"
	@printf $(_YELLOW)
	@echo "                                       2018 © lguiller bede-fre cmace    "
	@echo $(_END)

install:
	@echo "\x1b[44m\x1b[1mVerifing sdl_main ... $(HGLSS) \033[0m"
	@make sdl_main
	@echo "\x1b[42m\x1b[1m Done $(CHECK) \033[0m"
	@echo "\x1b[44m\x1b[1mVerifing sdl_image ... $(HGLSS) \033[0m"
	@make sdl_image
	@echo "\x1b[42m\x1b[1m Done $(CHECK) \033[0m"

sdl_main:
	@if [ ! -d "$(SDL_FOLDER)" ] ; then mkdir $(SDL_FOLDER); fi
	@if [ ! -e "$(SDL_FOLDER)$(SDL_MAIN_VERSION)" ] ; then cd $(SDL_FOLDER) && $(CURL_PATH) $(SDL_MAIN_DOWNLOAD) > $(SDL_MAIN_VERSION); fi
	@if [ ! -d "$(SDL_FOLDER)$(SDL_MAIN_FOLDER)" ] ; then cd $(SDL_FOLDER) && tar -xvzf $(SDL_MAIN_VERSION); fi
	@$(foreach file, $(SDL_MAIN), test -e $(file) || (echo "\x1b[41m\x1b[1mUhhh.... Missing file $(file) in $@\033[0m" ; \
		cd $(SDL_FOLDER)$(SDL_MAIN_FOLDER) ; ./configure --prefix=$$PWD/../ ;\
		make && make install);)
	@$(foreach file, $(SDL_MAIN_INCLUDE), test -e $(file) || (echo "\x1b[41m\x1b[1mUhhh.... Missing file $(file) in $@\033[0m" ; \
		cd $(SDL_FOLDER)$(SDL_MAIN_FOLDER) ; ./configure --prefix=$$PWD/../ ;\
		make && make install);)
	@cp -r $(SDL_MAIN_INCLUDE_PATH) ./includes/SDL

sdl_image:
	@if [ ! -d "$(SDL_FOLDER)" ] ; then make sdl_main; fi
	@if [ ! -e "$(SDL_FOLDER)$(SDL_IMAGE_VERSION)" ] ; then cd $(SDL_FOLDER) && $(CURL_PATH) $(SDL_IMAGE_DOWNLOAD) > $(SDL_IMAGE_VERSION); fi
	if [ ! -d "$(SDL_FOLDER)$(SDL_IMAGE_FOLDER)" ] ; then cd $(SDL_FOLDER) && tar -xvzf $(SDL_IMAGE_VERSION); fi
	@$(foreach file, $(SDL_IMAGE), test -e $(file) || (echo "\x1b[41m\x1b[1mUhhh.... Missing file $(file)\033[0m" ; \
		cd $(SDL_FOLDER)$(SDL_IMAGE_FOLDER) ; ./configure --prefix=$$PWD/../ --with-sdl-prefix=$$PWD/../../sdl ;\
		make && make install);)
	@$(foreach file, $(SDL_IMAGE_LIBS), test -e $(file) || (echo "\x1b[41m\x1b[1mUhhh.... Missing file $(file)\033[0m" ;\
		cd $(SDL_FOLDER)$(SDL_IMAGE_FOLDER) ; ./configure --prefix=$$PWD/../ --with-sdl-prefix=$$PWD/../../sdl ;\
		make && make install);)
	@cp $(SDL_FOLDER)SDL2_image-2.0.3/SDL_image.h ./includes/SDL/SDL_image.h
