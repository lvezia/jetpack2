##
## Makefile for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/
##
## Made by David Calo
## Login   <calo_d@epitech.eu>
##
## Started on  Thu Jul  7 09:41:47 2016 David Calo
## Last update Tue Jul 12 18:44:10 2016 Louis Vezia
##

SERVER	= server

CLIENT	= client

all:
	make all -C $(SERVER)
	make all -C $(CLIENT)

$(SERVER):
	make -C $(SERVER)

$(CLIENT):
	make -C $(CLIENT)

clean:
	make clean -C $(SERVER)
	make clean -C $(CLIENT)

fclean:
	make fclean -C $(SERVER)
	make fclean -C $(CLIENT)

re:
	make re -C $(SERVER)
	make re -C $(CLIENT)

do:
	make do -C $(SERVER)
	make do -C $(CLIENT)

.PHONY: $(CLIENT) $(SERVER) all clean fclean re do
