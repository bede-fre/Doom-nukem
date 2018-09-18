# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 12:36:39 by tberthie          #+#    #+#              #
#    Updated: 2018/09/18 17:25:52 by tberthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem

MLX = mlx/libmlx.a
INCLUDES = -I includes/ -I mlx/mlx.h
FLAGS = -framework OpenGL -framework AppKit -Wall -Wextra

OBJS = $(addprefix objs/, $(addsuffix .o, \
	   $(addprefix core/, main loop render ) \
	   $(addprefix events/, keys mouse window ) \
	   $(addprefix tools/, malloc error ) \
		))

all: $(NAME)

$(NAME): objs $(OBJS)
	make -C mlx
	gcc -o $(NAME) $(MLX) $(OBJS) $(FLAGS) $(INCLUDES)

objs/%.o: srcs/%.c
	gcc -o $@ -c $< $(FLAGS) $(INCLUDES)

objs:
	mkdir -p objs/events
	mkdir objs/tools
	mkdir objs/core

clean:
	make -C mlx clean
	rm -rf objs

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX)

re: fclean all
	make -C mlx re
