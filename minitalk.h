#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"

void ft_putpid(pid_t n);
void	incoming_signal_to_output(int signal);
void	send_data_to_pid(pid_t id, char *message);
int send_data_realtime(pid_t id);

#endif
