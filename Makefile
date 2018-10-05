# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toliver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 19:50:33 by toliver           #+#    #+#              #
#    Updated: 2018/10/05 18:06:12 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem

MLX = mlx/libmlx.a
INCLUDES = -I includes -I mlx
FLAGS = -framework OpenGL -framework AppKit -Wall -Wextra -g3 -fsanitize=address

OBJS = $(addprefix objs/, $(addsuffix .o, \
	   $(addprefix vector/, vector vector2 angle vecrot intersection) \
	   $(addprefix core/, main loop render map) \
	   $(addprefix events/, keys mouse window ) \
	   $(addprefix playerhandling/, playermove) \
	   $(addprefix tools/, malloc error images putline allocate) \
		))

.PHONY: all all clean fclean re objs $(NAME)

all: $(NAME)

minilibx:
	make -C mlx

$(NAME): minilibx objs $(OBJS)
	gcc $(FLAGS) $(OBJS) $(MLX) $(INCLUDES) -o $(NAME)

objs/%.o: srcs/%.c
	gcc $(FLAGS) $(INCLUDES) -c $^ -o $@

objs:
	mkdir -p objs/events
	mkdir -p objs/tools
	mkdir -p objs/core
	mkdir -p objs/vector
	mkdir -p objs/playerhandling

clean:
	make -C mlx clean
	rm -rf objs

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX)

re:
	$(MAKE) fclean
	$(MAKE)
	make -C mlx re
