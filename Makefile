# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmace <cmace@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 12:18:12 by lguiller          #+#    #+#              #
#    Updated: 2018/11/17 14:44:23 by cmace            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

SDL_FOLDER				= $(HOME)/sdl/
SDL_MAIN_DOWNLOAD		= https://www.libsdl.org/release/SDL2-2.0.8.tar.gz
SDL_MAIN_VERSION		= SDL2-2.0.8.tar.gz
SDL_MAIN_FOLDER			= $(SDL_MAIN_VERSION:.tar.gz=)
SDL_IMAGE_DOWNLOAD		= https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.3.tar.gz
SDL_IMAGE_VERSION		= SDL2_image-2.0.3.tar.gz
SDL_IMAGE_FOLDER		= $(SDL_IMAGE_VERSION:.tar.gz=)
SDL_MIXER_DOWNLOAD		= https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.2.tar.gz
SDL_MIXER_VERSION		= SDL2_mixer-2.0.2.tar.gz
SDL_MIXER_FOLDER		= $(SDL_MIXER_VERSION:.tar.gz=)
SDL_TTF_DOWNLOAD		= https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.tar.gz
SDL_TTF_VERSION			= SDL2_ttf-2.0.14.tar.gz
SDL_TTF_FOLDER			= $(SDL_TTF_VERSION:.tar.gz=)
FREETYPE_DOWNLOAD		= https://download.savannah.gnu.org/releases/freetype/freetype-2.8.1.tar.gz
FREETYPE_VERSION		= freetype-2.8.1.tar.gz
FREETYPE_FOLDER			= $(FREETYPE_VERSION:.tar.gz=)
SDL_MAIN_HEADER			= $(addsuffix .h, SDL SDL_assert SDL_atomic SDL_audio SDL_bits \
							 SDL_blendmode SDL_cpuinfo SDL_egl SDL_endian SDL_error SDL_events \
							 SDL_filesystem SDL_gamecontroller SDL_gesture SDL_haptic SDL_hints \
							 SDL_joystick SDL_keyboard SDL_keycode SDL_loadso SDL_log \
							 SDL_main SDL_messagebox SDL_mouse SDL_mutex SDL_name SDL_opengl \
							 SDL_opengl_glext SDL_opengles SDL_opengles2_gl2ext SDL_opengles2_gl2 \
							 SDL_opengles2_gl2platform SDL_opengles2 SDL_opengles2_khrplatform \
							 SDL_pixels SDL_platform SDL_power SDL_quit SDL_rect SDL_render \
							 SDL_rwops SDL_scancode SDL_shape SDL_stdinc SDL_surface SDL_system \
							 SDL_syswm SDL_thread SDL_timer SDL_touch SDL_types SDL_version \
							 SDL_video SDL_vulkan begin_code close_code)
SDL_IMAGE_HEADER 		= SDL_image.h
SDL_TTF_HEADER			= SDL_ttf.h
FREETYPE_HEADER			= ft2build.h
SDL_MAIN_OBJ_LIBS		= libSDL2.a
SDL_IMAGE_OBJ_LIBS		= libSDL2_image.a
FREETYPE_OBJ_LIBS		= libfreetype.a
SDL_TTF_OBJ_LIBS		= libSDL2_ttf.a
SDL_MIXER_OBJ_LIBS		= libSDL2_mixer.a
SDL_MAIN_LIBS_PATH		= $(SDL_FOLDER)$(SDL_MAIN_FOLDER)/lib/
SDL_MAIN_INCLUDE_PATH	= $(SDL_FOLDER)$(SDL_MAIN_FOLDER)/include/SDL2/
SDL_IMAGE_LIBS_PATH		= $(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/lib/
SDL_IMAGE_INCLUDE_PATH	= $(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/include/SDL2/
SDL_MIXER_LIBS_PATH		= $(SDL_FOLDER)$(SDL_MIXER_FOLDER)/lib/
SDL_MIXER_INCLUDE_PATH	= $(SDL_FOLDER)$(SDL_MIXER_FOLDER)/include/SDL2/
SDL_TTF_LIBS_PATH		= $(SDL_FOLDER)$(SDL_TTF_FOLDER)/lib/
SDL_TTF_INCLUDE_PATH	= $(SDL_FOLDER)$(SDL_TTF_FOLDER)/include/SDL2/

SDL_MAIN_LIBS			= $(addprefix $(SDL_MAIN_LIBS_PATH), $(SDL_MAIN_OBJ_LIBS))
SDL_MAIN_INCLUDE		= $(addprefix $(SDL_MAIN_INCLUDE_PATH), $(SDL_MAIN_HEADER))
SDL_IMAGE_LIBS			= $(addprefix $(SDL_IMAGE_LIBS_PATH), $(SDL_IMAGE_OBJ_LIBS))
SDL_IMAGE_INCLUDE		= $(addprefix $(SDL_IMAGE_INCLUDE_PATH), $(SDL_IMAGE_HEADER))
SDL_MIXER_LIBS			= $(addprefix $(SDL_MIXER_LIBS_PATH), $(SDL_MIXER_OBJ_LIBS))
SDL_MIXER_INCLUDE		= $(addprefix $(SDL_MIXER_INCLUDE_PATH), $(SDL_MIXER_HEADER))
SDL_TTF_LIBS			= $(addprefix $(SDL_TTF_LIBS_PATH), $(SDL_TTF_OBJ_LIBS))
SDL_TTF_INCLUDE			= $(addprefix $(SDL_TTF_INCLUDE_PATH), $(SDL_TTF_HEADER))
CURL_PATH				= curl -L
OBJS_DIR				= objs/
LIBFT_DIR				= libft/
LIBVECT_DIR				= libvect/
MLX_DIR					= minilibx/
GAME_DIR				= srcs/game/
EDITOR_DIR				= srcs/map_editor/


##################
##    COLORS    ##
##################

_BLACK					= "\033[30m"
_RED					= "\033[31m"
_GREEN					= "\033[32m"
_YELLOW					= "\033[33m"
_BLUE					= "\033[34m"
_VIOLET					= "\033[35m"
_CYAN					= "\033[36m"
_WHITE					= "\033[37m"
_END					= "\033[0m"
_CLEAR					= "\033[2K"
_HIDE_CURS				= "\033[?25l"
_SHOW_CURS				= "\033[?25h"
_UP						= "\033[A"
_CUT					= "\033[k"

##################
##   TARGETS    ##
##################

.PHONY: all title clean fclean re norme lib game editor install reall cleansdl \
	sdl_main sdl_image sdl_mixer sub_sdl_ttf sdl_ttf

all: game

editor: lib
	@$(MAKE) -C $(EDITOR_DIR)

game: editor
	@$(MAKE) -C $(GAME_DIR)

lib: install
	@$(MAKE) -sC $(LIBFT_DIR)
	@$(MAKE) -sC $(LIBVECT_DIR)
	@$(MAKE) -sC $(MLX_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(LIBVECT_DIR) clean
	@$(MAKE) -sC $(MLX_DIR) clean
	@$(MAKE) -sC $(GAME_DIR) clean
	@$(MAKE) -sC $(EDITOR_DIR) clean
	@rm -rf SDL

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@$(MAKE) -sC $(LIBVECT_DIR) fclean
	@$(MAKE) -sC $(GAME_DIR) fclean
	@$(MAKE) -sC $(EDITOR_DIR) fclean
	@rm -rf SDL

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
	@if [ ! -d "$(SDL_FOLDER)" ] ; then mkdir $(SDL_FOLDER) ; fi
	@echo "\x1b[44m\x1b[1mVerifing sdl_main ... $(HGLSS) \033[0m"
	@make sdl_main
	@echo "\x1b[42m\x1b[1m Done $(CHECK) \033[0m"
	@echo "\x1b[44m\x1b[1mVerifing sdl_image ... $(HGLSS) \033[0m"
	@make sdl_image
	@echo "\x1b[42m\x1b[1m Done $(CHECK) \033[0m"
	@echo "\x1b[44m\x1b[1mVerifing sdl_ttf ... $(HGLSS) \033[0m"
	@make sdl_ttf
	@echo "\x1b[42m\x1b[1m Done $(CHECK) \033[0m"
	@echo "\x1b[44m\x1b[1mVerifing sdl_mixer ... $(HGLSS) \033[0m"
	@make sdl_mixer
	@echo "\x1b[42m\x1b[1m Done $(CHECK) \033[0m"

sdl_main:
	@if [ ! -d "$(SDL_FOLDER)$(SDL_MAIN_FOLDER)" ] ; then ($(CURL_PATH) \
		$(SDL_MAIN_DOWNLOAD) > $(SDL_FOLDER)$(SDL_MAIN_VERSION) ;\
		tar -xzf $(SDL_FOLDER)$(SDL_MAIN_VERSION) -C $(SDL_FOLDER)); fi
	@if [ ! -d "$(SDL_FOLDER)$(SDL_MAIN_FOLDER)/build" ] ; then mkdir \
		$(SDL_FOLDER)$(SDL_MAIN_FOLDER)/build ; fi
	@$(foreach file, $(SDL_MAIN_LIBS), test -e $(file) || \
		(echo "\n\033[31mMissing file ($(file)) in $@\033[0m" ; \
		cd $(SDL_FOLDER)$(SDL_MAIN_FOLDER)/build ; ../configure \
		--prefix=$(SDL_FOLDER)$(SDL_MAIN_FOLDER) ; make $(MFLAGS) -C \
		$(SDL_FOLDER)$(SDL_MAIN_FOLDER)/build ; make $(MFLAGS) -C \
		$(SDL_FOLDER)$(SDL_MAIN_FOLDER)/build install );)
	@$(foreach file, $(SDL_MAIN_INCLUDE), test -e $(file) || \
		(echo "\n\033[31mMissing file ($(file)) in $@\033[0m" ; cd \
		$(SDL_FOLDER)$(SDL_MAIN_FOLDER)/build ; ../configure \
		--prefix=$(SDL_FOLDER)$(SDL_MAIN_FOLDER) ; make $(MFLAGS) -C \
		$(SDL_FOLDER)$(SDL_MAIN_FOLDER)/build ; make $(MFLAGS) -C \
		$(SDL_FOLDER)$(SDL_MAIN_FOLDER)/build install );)

sdl_image:
	@if [ ! -d "$(SDL_FOLDER)$(SDL_IMAGE_FOLDER)" ] ; then ($(CURL_PATH) \
		$(SDL_IMAGE_DOWNLOAD) > $(SDL_FOLDER)$(SDL_IMAGE_VERSION) ;\
		tar -xzf $(SDL_FOLDER)$(SDL_IMAGE_VERSION) -C $(SDL_FOLDER)) ; fi
	@if [ ! -d "$(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/build" ] ; then mkdir \
		$(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/build ; fi
	@$(foreach file, $(SDL_IMAGE_LIBS), test -e $(file) || \
		(echo "\n\033[31mMissing file ($(file)) in $@\033[0m" ; cd \
		$(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/build ; ../configure \
		--prefix=$(SDL_FOLDER)$(SDL_IMAGE_FOLDER) \
		--with-sdl-prefix=$(SDL_FOLDER)$(SDL_MAIN_FOLDER) ; make $(MFLAGS) -C \
		$(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/build ; make $(MFLAGS) -C \
		$(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/build install);)
	@$(foreach file, $(SDL_IMAGE_INCLUDE), test -e $(file) || \
		(echo "\n\033[31mMissing file ($(file)) in $@\033[0m" ; cd \
		$(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/build ; ../configure \
		--prefix=$(SDL_FOLDER)$(SDL_IMAGE_FOLDER) \
		--with-sdl-prefix=$(SDL_FOLDER)$(SDL_MAIN_FOLDER) ; make $(MFLAGS) -C \
		$(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/build ; make $(MFLAGS) -C \
		$(SDL_FOLDER)$(SDL_IMAGE_FOLDER)/build install);)

sdl_mixer:
	@if [ ! -d "$(SDL_FOLDER)$(SDL_MIXER_FOLDER)" ] ; then ($(CURL_PATH) \
		$(SDL_MIXER_DOWNLOAD) > $(SDL_FOLDER)$(SDL_MIXER_VERSION) ;\
		tar -xzf $(SDL_FOLDER)$(SDL_MIXER_VERSION) -C $(SDL_FOLDER) ;) fi
	@if [ ! -d "$(SDL_FOLDER)$(SDL_MIXER_FOLDER)/build" ] ; then mkdir \
		$(SDL_FOLDER)$(SDL_MIXER_FOLDER)/build ; fi
	@$(foreach file, $(SDL_MIXER_LIBS), test -e $(file) || \
		(echo "\n\033[31mMissing file ($(file)) in $@\033[0m" ; cd \
		$(SDL_FOLDER)$(SDL_MIXER_FOLDER)/build ; ../configure \
		--prefix=$(SDL_FOLDER)$(SDL_MIXER_FOLDER) \
		--with-sdl-prefix=$(SDL_FOLDER)$(SDL_MAIN_FOLDER) ; make $(MFLAGS) -C \
		$(SDL_FOLDER)$(SDL_MIXER_FOLDER)/build ; make $(MFLAGS) -C \
		$(SDL_FOLDER)$(SDL_MIXER_FOLDER)/build install);)
	@$(foreach file, $(SDL_MIXER_INCLUDE), test -e $(file) || \
		(echo "\n\033[31mMissing file ($(file)) in $@\033[0m" ; cd \
		$(SDL_FOLDER)$(SDL_MIXER_FOLDER)/build ; ../configure \
		--prefix=$(SDL_FOLDER)$(SDL_MIXER_FOLDER) \
		--with-sdl-prefix=$(SDL_FOLDER)$(SDL_MAIN_FOLDER) ; make $(MFLAGS) -C \
		$(SDL_FOLDER)$(SDL_MIXER_FOLDER)/build ; make $(MFLAGS) -C \
		$(SDL_FOLDER)$(SDL_MIXER_FOLDER)/build install);)

sub_sdl_ttf:
	cd $(SDL_FOLDER)$(FREETYPE_FOLDER)/build ; ../configure --prefix=$$PWD
	make $(MFLAGS) -C $(SDL_FOLDER)$(FREETYPE_FOLDER)/build
	make $(MFLAGS) -C $(SDL_FOLDER)$(FREETYPE_FOLDER)/build install
	cd $(SDL_FOLDER)$(SDL_TTF_FOLDER) ; ./configure --prefix=$$PWD \
		--with-sdl-prefix=$(SDL_FOLDER)$(SDL_MAIN_FOLDER) \
		--with-freetype-exec-prefix=$(SDL_FOLDER)$(FREETYPE_FOLDER)/build
	make $(MFLAGS) -C $(SDL_FOLDER)$(SDL_TTF_FOLDER)
	make $(MFLAGS) -C $(SDL_FOLDER)$(SDL_TTF_FOLDER) install

sdl_ttf:
	@if [ ! -d "$(SDL_FOLDER)$(SDL_TTF_FOLDER)" ] ; then ($(CURL_PATH) \
		$(SDL_TTF_DOWNLOAD) > $(SDL_FOLDER)$(SDL_TTF_VERSION) ;\
		tar -xzf $(SDL_FOLDER)$(SDL_TTF_VERSION) -C $(SDL_FOLDER)) ; fi
	@if [ ! -d "$(SDL_FOLDER)$(SDL_TTF_FOLDER)/build" ] ; then mkdir \
		$(SDL_FOLDER)$(SDL_TTF_FOLDER)/build ; fi
	@if [ ! -f "$(SDL_FOLDER)$(FREETYPE_VERSION)" ] ; then $(CURL_PATH) \
		$(FREETYPE_DOWNLOAD) > $(SDL_FOLDER)$(FREETYPE_VERSION) ; fi
	@if [ ! -d "$(SDL_FOLDER)$(FREETYPE_FOLDER)" ] ; then tar -xzf \
		$(SDL_FOLDER)$(FREETYPE_VERSION) -C $(SDL_FOLDER) ; fi
	@if [ ! -d "$(SDL_FOLDER)$(FREETYPE_FOLDER)/build" ] ; then mkdir \
		$(SDL_FOLDER)$(FREETYPE_FOLDER)/build ; fi
	@$(foreach file, $(SDL_TTF_LIBS), test -e $(file) || \
		(echo "\n\033[31mMissing file ($(file)) in $@\033[0m" ; make sub_sdl_ttf );)
	@$(foreach file, $(SDL_TTF_INCLUDE), test -e $(file) || \
		(echo "\n\033[31mMissing file ($(file)) in $@\033[0m" ; make sub_sdl_ttf );)


cleansdl:
	@rm -rf $(SDL_FOLDER)
	@rm -rf SDL

reall: cleansdl re
