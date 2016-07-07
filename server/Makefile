##
## Makefile for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/
##
## Made by David Calo
## Login   <calo_d@epitech.eu>
##
## Started on  Thu Jul  7 10:22:07 2016 David Calo
## Last update Thu Jul  7 10:58:41 2016 David Calo
##

NAME	= serverJ2T3

SRC	= main.c

CFLAGS	= -Wall -Wextra -Werror -g

LDFLAGS	= -Iinc/

SRC_DIR	= src/

OBJ_DIR	= obj/

CC	= gcc

RM	= rm -f

OBJ	= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

$(NAME): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)

re: fclean all

do: fclean all clean

.PHONY: all clean fclean re do
