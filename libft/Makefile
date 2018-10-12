# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:15:29 by lguiller          #+#    #+#              #
#    Updated: 2018/10/12 14:50:01 by bede-fre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

NAME	= libft.a
SRC		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
		  ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
		  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
		  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		  ft_tolower.c ft_memdel.c ft_strnew.c ft_strdel.c ft_memalloc.c \
		  ft_putchar.c ft_putstr.c ft_putendl.c ft_putchar_fd.c ft_putnbr.c \
		  ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		  ft_strsplit.c ft_itoa.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_base.c \
		  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		  ft_lstmap.c ft_putaddr.c ft_putaddr_fd.c ft_itoa_base.c ft_brackets.c \
		  ft_isprime.c ft_abs.c ft_strcspn.c ft_pgcd.c ft_ppcm.c ft_putnbr_fd.c \
		  ft_realloc.c ft_sqrt.c get_next_line.c ft_isspace.c print_memory.c \
		  ft_atoi_base.c power.c ft_split_whitespaces.c \
		  ft_puterror.c ft_fabs.c ft_rounded_to_mult.c ft_rgba.c ft_rad.c \
		  ft_remove_whitespaces.c ft_deg.c change_case.c
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

.PHONY: all clean fclean re norme

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(_YELLOW)"building - "$(_GREEN)$(NAME)$(_END)
	@echo $(_GREEN)"Done."$(_END)$(_SHOW_CURS)

%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

norme:
	@norminette *.[c,h]
