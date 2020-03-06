##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## My Makefile
##

SRC	=	src/main.c					\
		src/nm_errors.c 			\
		src/nm_64/nm_engine_64.c 	\
		src/nm_64/get_type_64.c		\
		src/nm_32/nm_engine_32.c 	\
		src/nm_32/get_type_32.c		\
		# ../tests/nm_tests.c 		\

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
		rm -f ../tests/*.gcno

re:		fclean all

# tests_run:    $(OBJ)
# 	gcc -o unit_tests $(OBJ) -lcriterion --coverage
# 	./unit_tests
# 	@gcovr

.PHONY:		make clean fclean re
