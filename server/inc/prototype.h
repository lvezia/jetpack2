/*
** prototype.h for jetpack2Tek3 in /home/david/dev/syn_pool/jetpack2Tek3/server/inc/
**
** Made by David Calo
** Login   <calo_d@epitech.eu>
**
** Started on  Fri Jul  8 21:15:55 2016 David Calo
** Last update Wed Jul 13 23:46:06 2016 David Calo
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
int	client_notify(t_fd *, char const *);

// game.c
int	process_game(t_game *);
int	update_game(t_server *);

// list.c
t_fd	*list_new(int, t_rw_fn, t_rw_fn);
int	list_add(t_fd *, t_fd *);
int	list_remove(t_fd *, size_t);
size_t	list_size(t_fd *);
t_fd	*list_get(t_fd *, size_t);

// map.c
int	map_border(t_player *, t_game *);
int	map_object(t_player *, t_game *);
int	map_coin(t_game *, t_fd *, int, char (*)[]);

// parser.c
int	parser(t_fd *, char *);
int	parser_id(t_fd *, char *);
int	parser_map(t_fd *, char *);
int	parser_ready(t_fd *, char *);
int	parser_fire(t_fd *, char *);

// player.c
int	player_info(t_server const *, int, int *);
int	update_player(t_server *);

// player_struct.c
int	player_init(t_game *, t_fd *);
int	player_clear(t_game *);

// select.c
int	server_select(t_server *);

// server.c
int	server_read(t_server *, size_t);
int	server_write(t_server *, size_t);
int	server_init(t_server *);

// socket.c
int	get_socket();
int	bind_listen_socket(int, PORT);

// time.c
double	update_time(t_game *);

// tools.c
int	print_usage(char const *);
int	xputerror(char const *);
int	xperror(char const *);
void	printlog(int, char const *);
char	*read_file(char const *);

// tools_check.c
int	check_int(char const *);
int	check_float(char const *);

// tools_string.c
int	xstrlenchr(char const *, char);
int	count_lines(char const *);
void	epur_str(char *, char);

#endif
