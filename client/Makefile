##
## Makefile for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/client/
##
## Made by David Calo
## Login   <calo_d@epitech.eu>
##
## Started on  Thu Jul  7 10:22:07 2016 David Calo
## Last update Tue Jul 12 17:12:30 2016 louis vezia
##

NAME	= clientJ2T3

SRC	= main.c		\
	  pars_arg.c		\
	  init.c		\
	  run.c			\
	  graphique.c		\
	  communication.c	\
	  manage_msg.c		\
	  set_client.c		\
	  manage_msg.c		\
	  refresh_data.c	\
	  refresh_window.c	\
	  play.c		\
	  fire.c		\

CFLAGS	= -Wall -Wextra -Werror -g

LDFLAGS	= -I./inc/ -lpthread -lSDL

SRC_DIR	= src/

OBJ_DIR	= obj/

CC	= gcc

RM	= rm -f

OBJ	= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

$(NAME): $(OBJ)
	@/bin/echo -e "\x1b[32m*** $(NAME) successfully built ***\x1b[0m"
	$(CC) $^ -o ../$@ $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	@/bin/echo -e "\x1b[32m*** Client objects removed $(NAME) ***\x1b[0m"

fclean:
	$(RM) $(OBJ) ../$(NAME)
	@/bin/echo -e "\x1b[32m*** Binary $(NAME) removed ***\x1b[0m"

re: fclean all

do: fclean all clean

.PHONY: all clean fclean re do
