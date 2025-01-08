##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

SRC	=	my_strlen.c  \
		my_put_nbr.c  \
		my_putchar.c  \
		my_putstr.c  \
		cat.c	\
		my_compute_power_it.c	\
		my_str_to_word_array_02.c	\
		my_atoi.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp my.h ../../include
		cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
