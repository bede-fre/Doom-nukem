NAME	= libmlx.a
SRC		= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m \
		  mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1	= $(SRC:.c=.o)
OBJ		= $(OBJ1:.m=.o)
FLAGS	= -O2

.PHONY: all compil clean re

all: $(NAME)

$(NAME): compil
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[33mbuilding - \033[32m"$(NAME)
	@echo "Done.\n\033[0m"

compil:
	@gcc $(FLAGS) -c $(SRC)

clean:
	@/bin/rm -f $(OBJ) $(NAME)

re: clean all
