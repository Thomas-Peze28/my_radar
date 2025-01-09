##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makfile
##

SRC	= 	src/main.c	\
		src/window.c	\
		src/init.c	\
		src/set.c		\
		src/read_tower.c		\
		src/init_clock.c		\
		src/math/vector.c		\
		src/display/display_planes.c		\
		src/display/display_towers.c		\
		src/display/show_option.c		\
		src/plane/move_planes.c	\
		src/plane/set_planes.c	\
		src/tower/set_towers.c	\
		src/shape/collide.c	\
		src/shape/shape.c		\
		src/zones/assign_planes.c		\
		src/zones/destroy_zones.c		\
		src/zones/get_zone.c		\
		src/zones/init_zones.c	\
		src/zones/is_in_zone.c	\

NAME	=	my_radar

OBJ	=	$(SRC:.c=.o)

INC	= 	-I./include/ -I./include/structures/

CSFMLFLAGS = -lcsfml-graphics -lcsfml-system -l csfml-window -l csfml-audio

LDFLAGS =	-L./lib -lmy -lm

CFLAGS = -Wall -Wextra -Werror $(INC) $(LDFLAGS) $(CSFMLFLAGS)

all: build_lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

build_lib:
		make -C ./lib/my/

clean_lib:
		make clean -C ./lib/my/

clean: clean_lib
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

.PHONY: all fclean clean re
