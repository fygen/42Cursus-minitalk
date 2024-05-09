#include "minitalk.h"


/// @brief server main function
/// @param
/// @return
int	main(void)
{
	pid_t server_id;

	server_id = getpid();
	ft_putpid(server_id);
	signal(SIGUSR1, incoming_signal_to_output);
	signal(SIGUSR2, incoming_signal_to_output);
	while (1)
	{
		pause();
	}
	return (0);
}
