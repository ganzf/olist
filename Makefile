#
## Makefile for engine in /home/ganz_f/my_engine
##
## Made by Felix Ganz
## Login   <ganz_f@epitech.net>
##
## Started on  Wed Jun  1 20:56:50 2016 Felix Ganz
## Last update Fri Jul  8 18:46:51 2016 Felix Ganz
##

LIBNAME		=	liblist.a

TEST		=	test

TEST_CLEAN	=	test_c

TEST_FCLEAN	=	test_f

TEST_RE		=	test_r

SRC_MANAGER	=	src/manager/new.c

SRC_LIST	=	src/list/new.c

SRC_ELEM	=	src/elem/new.c

SRC	=	$(SRC_MANAGER) \
		$(SRC_LIST) \
		$(SRC_ELEM)

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -W -Wall -Iinclude -O2

RM	=	rm -f

all	:	$(LIBNAME) $(TEST)

$(LIBNAME)	:	$(OBJ)
			ar rc $(LIBNAME) $(OBJ)
			@printf "[ \033[32mOK\033[0m ]\Library ready.\n"

$(TEST)	:
			make -C unit_test all

$(TEST_CLEAN)	:
			make -C unit_test clean


$(TEST_FCLEAN)	:
			make -C unit_test fclean

$(TEST_RE)	:
			make -C unit_test re

clean	:
		@$(RM) $(OBJ)
		@printf "[ \033[32mOK\033[0m ]\tReposiroty cleaned.\n"

fclean	:	clean
		@$(RM) $(NAME)
		@printf "[ \033[32mOK\033[0m ]\tRepository fcleaned.\n"

re	:	fclean all
		@printf "[ \033[32mOK\033[0m ]\tRebuilding project.\n"
