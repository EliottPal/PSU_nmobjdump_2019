##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## My Makefile
##

SRC	=	src/main.c			\
		src/nm_engine.c 	\


OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror -g3

NAME	=	../my_nm

all:		build

build:		$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f *~
		rm -f $(NAME)
		rm -f vgcore.*

re:		fclean all

.PHONY:		make clean fclean re
