##
## EPITECH PROJECT, 2017
## libmy
## File description:
## Makefile
##

SRC	=	my_putchar.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_memset.c		\
		my_strdup.c		\
		my_getnumber.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS  +=       -Wall -Wextra -Iinclude

NAME	=	libmy.a

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean	:
	rm -f *.o

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all
