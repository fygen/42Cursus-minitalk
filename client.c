#include "minitalk.h"

/// @brief client main function
/// @param argc count of the entries
/// @param argv the address of the char array starting point 
/// @return if program succeed
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
		send_data_to_pid(server_id, message); // send the message to the server
	}
	else if(argc == 2){
		server_id = ft_atoi(argv[1]); // set the server process id 
		send_data_realtime(server_id);
	}
	else
		write(1, "usage: ./client [pid-server] [message]", 39);
	return (0);
}
