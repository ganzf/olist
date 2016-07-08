#
## Makefile for engine in /home/ganz_f/my_engine
##
## Made by Felix Ganz
## Login   <ganz_f@epitech.net>
##
## Started on  Wed Jun  1 20:56:50 2016 Felix Ganz
## Last update Fri Jul  8 18:55:04 2016 Felix Ganz
##

NAME		=	../olist_unit_test

MAIN		=	../src/main.c \
			../src/print_info.c

SRC	=	$(MAIN)

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -W -Wall -I../include -O2

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -L.. -llist
		@printf "[ \033[32mOK\033[0m ]Unit tests ready.\n"

clean	:
		@$(RM) $(OBJ)
		@printf "[ \033[32mOK\033[0m ]\tReposiroty cleaned.\n"

fclean	:	clean
		@$(RM) $(NAME)
		@printf "[ \033[32mOK\033[0m ]\tRepository fcleaned.\n"

re	:	fclean all
		@printf "[ \033[32mOK\033[0m ]\tRebuilding project.\n"
