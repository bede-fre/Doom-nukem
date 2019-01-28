# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:15:29 by lguiller          #+#    #+#              #
#    Updated: 2018/12/04 15:34:05 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

NAME	= libft.a
SRC		= $(addsuffix .c, ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr \
		  ft_memcmp ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat \
		  ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strstr \
		  ft_strnstr ft_strcmp ft_strncmp ft_atoi ft_isalpha \
		  ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper \
		  ft_tolower ft_memalloc ft_memdel ft_strnew ft_strdel \
		  ft_putchar ft_putstr ft_putendl ft_putchar_fd ft_putnbr \
		  ft_strclr ft_striter ft_striteri ft_strmap ft_strmapi \
		  ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim \
		  ft_strsplit ft_itoa ft_putstr_fd ft_putendl_fd ft_putnbr_base \
		  ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter \
		  ft_lstmap ft_putaddr ft_putaddr_fd ft_itoa_base ft_brackets \
		  ft_isprime ft_abs ft_strcspn ft_pgcd ft_ppcm ft_putnbr_fd \
		  ft_realloc ft_sqrt get_next_line ft_isspace print_memory \
		  ft_atoi_base power ft_split_whitespaces ft_error \
		  ft_puterror ft_fabs ft_rounded_to_mult ft_rgba ft_rad \
		  ft_remove_whitespaces ft_deg change_case ft_pointdef ft_signe)
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
