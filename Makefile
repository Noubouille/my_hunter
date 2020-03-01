##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME    = my_hunter

CC    = gcc

RM    = rm -f

SRC	=	main.c	\
		game.c	\
		int_tochar.c	\
		my_put_nbr.c	\
		my_putchar.c	\
		my_putstr.c


OBJS    = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -l csfml-audio -l csfml-graphics -l csfml-network -l csfml-system -l csfml-window -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all