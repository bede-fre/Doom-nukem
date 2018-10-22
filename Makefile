# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 12:18:12 by lguiller          #+#    #+#              #
#    Updated: 2018/10/22 11:51:40 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

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
	@echo "                                               2018 © lguiller bede-fre"
	@echo $(_END)
