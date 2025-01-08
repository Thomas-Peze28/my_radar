##
## EPITECH PROJECT, 2024
## makefile pong seb
## File description:
## makfile
##

SRC     = $(wildcard src/*.c src/*/*.c)

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
