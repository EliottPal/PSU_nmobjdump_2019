##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## My Makefile
##

SRC	=	src/main.c						\
		src/obj_32/engine_32.c 				\
		src/obj_32/header_values_32.c	 	\
		src/obj_32/print_sections_32.c 		\
		src/obj_64/engine_64.c 				\
		src/obj_64/header_values_64.c	 	\
		src/obj_64/print_sections_64.c 		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror -g3

NAME	=	../my_objdump

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
