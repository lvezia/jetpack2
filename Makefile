##
## Makefile for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/
##
## Made by David Calo
## Login   <calo_d@epitech.eu>
##
## Started on  Thu Jul  7 09:41:47 2016 David Calo
## Last update Tue Jul 12 15:16:02 2016 Louis Vezia
##

CLIENT	= client

SERVER	= server

all:
	make all -C $(CLIENT)
	make all -C $(SERVER)

$(CLIENT):
	make -C $(CLIENT)

$(SERVER):
	make -C $(SERVER)

clean:
	make clean -C $(CLIENT)
	make clean -C $(SERVER)

fclean:
	make fclean -C $(CLIENT)
	make fclean -C $(SERVER)

re:
	make re -C $(CLIENT)
	make re -C $(SERVER)

do:
	make do -C $(CLIENT)
	make do -C $(SERVER)

.PHONY: $(CLIENT) $(SERVER) all clean fclean re do
