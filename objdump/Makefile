##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## My Makefile
##

SRC	=	src/main.c							\
		src/objdump_errors.c 				\
		src/obj_32/engine_32.c 				\
		src/obj_32/header_values_32.c	 	\
		src/obj_32/print_sections_32.c 		\
		src/obj_64/engine_64.c 				\
		src/obj_64/header_values_64.c	 	\
		src/obj_64/print_sections_64.c 		\


SRC_TEST = 	src/objdump_errors.c 				\
			src/obj_32/engine_32.c 				\
			src/obj_32/header_values_32.c	 	\
			src/obj_32/print_sections_32.c 		\
			src/obj_64/engine_64.c 				\
			src/obj_64/header_values_64.c	 	\
			src/obj_64/print_sections_64.c 		\
			../tests/objdump_tests.c 			\

OBJ	=	$(SRC:.c=.o)

OBJ_TEST = $(SRC_TEST:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror -g3 --coverage

NAME	=	../my_objdump

all:		build

build:		$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f $(OBJ_TEST)

fclean:		clean
		rm -f *~
		rm -f $(NAME)
		rm -f vgcore.*
		rm -f *.gcno
		rm -f src/obj_64/*.gcda
		rm -f src/obj_64/*.gcno
		rm -f src/obj_32/*.gcda
		rm -f src/obj_32/*.gcno
		rm -f src/*.gcno
		rm -f src/*.gcda
		rm -f ../tests/*.gcno
		rm -f ../tests/*.gcda
		rm -f ../tests/*.o
		rm -f unit_tests

re:		fclean all

tests_run:    $(OBJ_TEST)
	gcc -o unit_tests $(OBJ_TEST) -lcriterion --coverage
	./unit_tests
	@gcovr

.PHONY:		make clean fclean re
