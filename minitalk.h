#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>
# include <stdarg.h>
# include <unistd.h>

void	ft_putpid(pid_t n);
void	incoming_signal_to_output(int signal);
void	send_data_to_pid(pid_t id, char *message);
int	    send_data_realtime(pid_t id, pid_t sid);
char	*deljoiner(char *dlm, char *str1, char *str2);
// char	*deljoiner(char dlm, ...);

#endif
