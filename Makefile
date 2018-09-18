# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 12:36:39 by tberthie          #+#    #+#              #
#    Updated: 2018/09/18 12:41:43 by tberthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem

INCLUDES = -I includes/
FLAGS = -Weverything

OBJS = $(addprefix objs/, $(addsuffix .o, \
		main ))

all: $(NAME)

$(NAME): objs $(OBJS)
	gcc -o $(NAME) $(OBJS) $(FLAGS) $(INCLUDE)

objs/%.o: srcs/%.c
	gcc -o $@ -c $< $(FLAGS) $(INCLUDES)

objs:
	mkdir objs

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all
