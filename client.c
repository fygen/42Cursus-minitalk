#include "minitalk.h"

/// @brief this function sends a signal to the server with the message
/// @param id process id of the process to which the signal is sent
/// @param message the message to be sent
static void	send_signal(pid_t id, char *message)
{
	int		i;
	int		j;
	char	result;

	i = 0;
	while (message[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			result = (message[i] >> j) & 1;
			if (result == 1)
				kill(id, SIGUSR1);
			else if (result == 0)
				kill(id, SIGUSR2);
			usleep(142);
			j--;
		}
		i++;
	}
}
 
int	main(int argc, char *argv[])
{
	pid_t	server_id; // server process id
	pid_t client_id; // client process id	
	char	*message; // message to be sent
	
	client_id = getpid();
	if (argc == 3)
	{
		server_id = ft_atoi(argv[1]); // set the server process id 
		message = ft_strjoin(ft_itoa(client_id), argv[2]); // join the client process id with the message
		send_signal(server_id, message); // send the message to the server
	}
	else
		write(1, "usage: ./client [pid-server] [message]", 39);
	return (0);
}
