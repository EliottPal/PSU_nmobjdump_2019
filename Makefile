##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## My Makefile
##

NM_DIR	=	$(realpath ./nm/)

OBJDUMP_DIR =	$(realpath ./objdump/)

OBJ	=	$(SRC:.c=.o)

all:		build

build:		$(OBJ)
		$(MAKE) -C $(NM_DIR)
		$(MAKE) -C $(OBJDUMP_DIR)

nm:		$(OBJ)
	$(MAKE) -C $(NM_DIR)

objdump:	$(OBJ)
	$(MAKE) -C $(OBJDUMP_DIR)

clean:
	$(MAKE) -C $(NM_DIR) clean
	$(MAKE) -C $(OBJDUMP_DIR) clean

fclean:
	$(MAKE) -C $(NM_DIR) fclean
	$(MAKE) -C $(OBJDUMP_DIR) fclean

re: 	fclean all

tests_run:
	$(MAKE) -C $(NM_DIR) tests_run
	$(MAKE) -C $(OBJDUMP_DIR) tests_run

.PHONY:		make nm objdump clean fclean all re tests_run
