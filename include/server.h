#ifndef SERVER_H
# define SERVER_H

# include "libft.h"
# include <sys/types.h>
# include <signal.h>

# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"
# define GREEN   "\x1b[32m"
# define YELLOW   "\x1b[33m"
# define RED   "\x1b[31m"

typedef struct 		s_client
{
  pid_t				pid;
  char				data[50];
  int				len_bit;
  int				packet_c;
  struct s_client 	*next;
} 					t_client;

t_client			*g_client;

void				accept_client(t_client *client);
void				remove_client(pid_t pid);
void				print_message(t_client *client);
void				handler(int signal, siginfo_t *info, void *tmp);
void				exit_c(int signal);
int					parse_message(pid_t pid, int bit);
t_client			*alloc_client(pid_t pid);
t_client			*find_client(pid_t pid);

#endif
