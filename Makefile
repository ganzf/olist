#
## Makefile for engine in /home/ganz_f/my_engine
##
## Made by Felix Ganz
## Login   <ganz_f@epitech.net>
##
## Started on  Wed Jun  1 20:56:50 2016 Felix Ganz
## Last update Wed Jul  6 16:21:06 2016 Felix Ganz
##

NAME		=	olist

MAIN		=	src/main.c

SRC	=	$(MAIN) \

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -W -Wall -Iinclude -g3

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)
		@printf "[ \033[32mOK\033[0m ]\tProject built.\n"

clean	:
		@$(RM) $(OBJ)
		@printf "[ \033[32mOK\033[0m ]\tReposiroty cleaned.\n"

fclean	:
		@$(RM) $(NAME)
		@printf "[ \033[32mOK\033[0m ]\tRepository fcleaned.\n"

re	:	fclean all
		@printf "[ \033[32mOK\033[0m ]\tRebuilding project.\n"
