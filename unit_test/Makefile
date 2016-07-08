#
## Makefile for engine in /home/ganz_f/my_engine
##
## Made by Felix Ganz
## Login   <ganz_f@epitech.net>
##
## Started on  Wed Jun  1 20:56:50 2016 Felix Ganz
## Last update Fri Jul  8 18:09:21 2016 Felix Ganz
##

NAME		=	../olist_unit_test

MAIN		=	../src/main.c \
			../src/print_info.c

SRC_MANAGER	=	../src/manager/new.c

SRC_LIST	=	../src/list/new.c

SRC_ELEM	=	../src/elem/new.c

SRC	=	$(MAIN) \
		$(SRC_MANAGER) \
		$(SRC_LIST) \
		$(SRC_ELEM)

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -W -Wall -I../include -O2

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)
		@printf "[ \033[32mOK\033[0m ]Unit tests ready.\n"

clean	:
		@$(RM) $(OBJ)
		@printf "[ \033[32mOK\033[0m ]\tReposiroty cleaned.\n"

fclean	:	clean
		@$(RM) $(NAME)
		@printf "[ \033[32mOK\033[0m ]\tRepository fcleaned.\n"

re	:	fclean all
		@printf "[ \033[32mOK\033[0m ]\tRebuilding project.\n"
