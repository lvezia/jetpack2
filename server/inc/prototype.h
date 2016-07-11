/*
** prototype.h for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/inc/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 21:15:55 2016 David Calo
** Last update Mon Jul 11 12:01:42 2016 David Calo
*/

#ifndef PROTOTYPE_H_
# define PROTOTYPE_H_

// argument.c
int	arg_read(int, char const *[], t_server *);
int	arg_port(char const *, t_server *);
int	arg_gravity(char const *, t_server *);
int	arg_map(char const *, t_server *);

// client.c
int	client_read(t_server *, size_t);
int	client_write(t_server *, size_t);
int	client_accept(int);
int	client_close(t_fd *, size_t);

// game.c
int	process_game(t_server const *);
int	update_game(t_server const *);

// list.c
t_fd	*list_new(int, t_fd_fn, t_fd_fn);
int	list_add(t_fd *, t_fd *);
int	list_remove(t_fd *, size_t);
size_t	list_size(t_fd *);
t_fd	*list_get(t_fd *, size_t);

// parser.c
int	parser(char const *);

// select.c
int	server_select(t_server *);

// server.c
int	server_read(t_server *, size_t);
int	server_write(t_server *, size_t);
int	server_init(t_server *);

// socket.c
int	get_socket();
int	bind_listen_socket(int, PORT);

// tools.c
int	xstrlenchr(char const *, char);
int	xputerror(char const *);
int	xperror(char const *);
void	printlog(int, char const *);
char	*read_file(char const *);

// tools_check.c
int	check_int(char const *);
int	check_float(char const *);

#endif
