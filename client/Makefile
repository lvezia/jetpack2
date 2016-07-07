##
## Makefile for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/client/
##
## Made by David Calo
## Login   <calo_d@epitech.eu>
##
## Started on  Thu Jul  7 10:22:07 2016 David Calo
## Last update Thu Jul  7 19:25:55 2016 louis vezia
##

NAME	= clientJ2T3

SRC	= main.c	\
	  pars_arg.c	\
	  init.c	\
	  run.c		\
	  graphique.c	\
	  player.c	\

CFLAGS	= -Wall -Wextra -Werror -g

LDFLAGS	= -I./inc/ -lpthread

SRC_DIR	= src/

OBJ_DIR	= obj/

CC	= gcc

RM	= rm -f

OBJ	= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

$(NAME): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)
	@/bin/echo -e "\x1b[32m*** $(NAME) successfully build ***\x1b[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	@/bin/echo -e "\x1b[32m*** Objects client removed $(NAME) ***\x1b[0m"

fclean:
	$(RM) $(OBJ) $(NAME)
	@/bin/echo -e "\x1b[32m*** Binary $(NAME) removed ***\x1b[0m"

re: fclean all

do: fclean all clean

.PHONY: all clean fclean re do
