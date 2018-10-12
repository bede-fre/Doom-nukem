# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 12:18:12 by lguiller          #+#    #+#              #
#    Updated: 2018/10/12 14:52:01 by bede-fre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

OPE_SYS			= $(shell uname)
NAME			= doom-nukem
SRCS1			= $(addprefix $(OBJS_DIR), $(addsuffix .c, \
				  $(addprefix vector/, vector vector2 vector3 angle vecrot intersection) \
				  $(addprefix core/, main loop render map init) \
				  $(addprefix events/, keys mouse window) \
				  $(addprefix playerhandling/, playermove) \
				  $(addprefix tools/, error images putline allocate) \
				  ))
OBJS			= $(SRCS1:.c=.o)
SRCS_DIR		= srcs/
OBJS_DIR		= objs/
LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a
MINILIBX		= $(MLX_DIR)/libmlx.a
FLAGS			= -Wall -Wextra -Werror -O2 -g -fsanitize=address

ifeq ($(OPE_SYS), Linux)
	MLX_DIR		= minilibx_x11
	INCLUDES	= -I includes -I $(MLX_DIR) -I $(LIBFT_DIR) -I /usr/include
	FRAMEWORK	= -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm
else
	MLX_DIR		= mlx
	INCLUDES	= -I includes -I $(MLX_DIR) -I $(LIBFT_DIR)
	FRAMEWORK	= -framework OpenGL -framework Appkit
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

.PHONY: all title minilibx create_dir clean fclean re norme libft

all: $(NAME)

minilibx: title
	@make -sC $(MLX_DIR) 2>/dev/null

libft: minilibx
	@make -sC $(LIBFT_DIR)

$(NAME): libft create_dir $(OBJS)
	@gcc $(FLAGS) $(OBJS) $(LIBFT) $(FRAMEWORK) $(MINILIBX) -o $(NAME)
	@echo $(_CLEAR)$(_YELLOW)"building - "$(_GREEN)$(NAME)$(_END)
	@echo $(_GREEN)"Done."$(_END)$(_SHOW_CURS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@gcc $(FLAGS) $(INCLUDES) -c $^ -o $@

create_dir:
	@mkdir -p objs/events
	@mkdir -p objs/tools
	@mkdir -p objs/core
	@mkdir -p objs/vector
	@mkdir -p objs/playerhandling

clean:
	@make -sC $(MLX_DIR) clean
	@make -sC $(LIBFT_DIR) clean
	@/bin/rm -rf $(OBJS_DIR)

fclean: clean
	@make -sC $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME)

re:
	@$(MAKE) -s fclean
	@$(MAKE) -s

norme:
	@norminette srcs/*.c includes/*.h

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
