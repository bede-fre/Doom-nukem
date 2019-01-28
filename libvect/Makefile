# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 14:09:33 by lguiller          #+#    #+#              #
#    Updated: 2018/11/27 14:09:35 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

NAME	= libvect.a
SRC		= $(addsuffix .c, rotation_3d normalize dot_product reverse_vect \
		  vector vector2 vector3 intersection convertion)
OBJ		= $(SRC:.c=.o)
FLAGS	= -Wall -Wextra -Werror -g

##################
##    COLORS    ##
##################

_GREY		= "\033[30m"
_RED		= "\033[31m"
_GREEN		= "\033[32m"
_YELLOW		= "\033[33m"
_BLUE		= "\033[34m"
_PURPLE		= "\033[35m"
_CYAN		= "\033[36m"
_WHITE		= "\033[37m"
_END		= "\033[0m"
_BOLD		= "\033[1m"
_CLEAR		= "\033[2K"
_SAVE		= "\033[7"
_BACK		= "\033[8"
_HIDE_CURS	= "\033[?25l"
_SHOW_CURS	= "\033[?25h"
_UP			= "\033[A"
_CUT		= "\033[k"

##################
##   TARGETS    ##
##################

.PHONY: all clean fclean re norme print

all: $(NAME)

print:
	@echo $(_CLEAR)$(_YELLOW)"Building - "$(_GREEN)$(NAME)$(_END)

$(NAME): print $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(_GREEN)"\nDone.\n"$(_END)$(_SHOW_CURS)

%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@
	@printf $^

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

norme:
	@norminette *.[c,h]
