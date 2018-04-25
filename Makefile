##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	gameoflife.c		\
		map/get_from_file.c	\
		algo/algo.c		\
		algo/check_border.c	\
		algo/print.c		\
		algo/map_op.c		\
		map/verif_chars.c	\

OBJ	=	$(SRC:.c=.o)

RM	=	@rm -rf

LIB	=	-Llib/my -lmy

CFLAGS	+=	-Wall -Wextra -Iinclude

NAME	=	gameoflife

all:		 $(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc $(OBJ) $(LIB) -o $(NAME)

clean:
		@$(RM) $(OBJ)
		make clean -C lib/my

fclean:		clean
		$(RM) $(NAME)
		make fclean -C lib/my

re:		fclean all
		make re -C lib/my
