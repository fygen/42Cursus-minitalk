#include "minitalk.h"

#define BUFFER_SIZE 256


/// @brief print the pid of the server
/// @param n integer to be printed
void	ft_putpid(pid_t n)
{
	char c;

	if (n > 9)
	{
		ft_putpid((n / 10));
		ft_putpid((n % 10));
	}
	else
	{
		c = 48 + n;
		write(1, &c, 1);
	}
}

/// @brief write the message to the standard output
/// @param signal the signal to be handled
void	incoming_signal_to_output(int signal)
{
	static char chr;
	static int i;
	i++;
	if (signal == SIGUSR1)
		chr = chr | 1;
	if (i == 8)
	{
		write(1, &chr, 1);
		i = 0;
		chr = 0;
	}
	chr = chr << 1;
}

/// @brief this function sends a signal to the server with the message
/// @param id process id of the process to which the signal is sent
/// @param message the message to be sent
void	send_data_to_pid(pid_t id, char *message)
{
	int i;
	int j;
	char result;

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

/// @brief send data from one to other
/// @param id the destination id TO
/// @param fid the sender id SENDER
/// @return
int	send_data_realtime(pid_t tid, pid_t fid)
{
	char buffer[BUFFER_SIZE];
	int num_bytes_read;
	char *message; // message to be sent

	while (1)
	{
		// Read input from stdin
		num_bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);

		if (num_bytes_read == -1)
		{
			write(STDOUT_FILENO, "no data: ", 10);
			return (1);
		}

		// Check if 'q' was entered
		if (buffer[0] == 'q' && num_bytes_read == 2)
		{
			write(STDOUT_FILENO, "Quit entered.", 13);
			break ;
		}

		// Write input to stdout
		write(STDOUT_FILENO, "You entered: ", 13);
		write(STDOUT_FILENO, buffer, num_bytes_read);
		message = deljoiner(":", ft_strjoin("\n", ft_itoa(tid)), buffer);
		message = deljoiner(":", message, ft_itoa(fid));

		// message = ft_strjoin(ft_itoa(id), buffer);
		// message = ft_strjoin(message, ft_itoa(fid));
		send_data_to_pid(tid, message);
		char *from =  deljoiner("fromPID: ",ft_itoa(getppid()),"\n"); 
		write(1, from, ft_strlen(from));
		// Clear buffer
		for (int i = 0; i < BUFFER_SIZE; i++)
		{
			buffer[i] = '\0';
		}
	}

	return (0);
}

/// @brief Join 2 strings with delimiter
/// @param dlm char[] delimiter
/// @param str1 char[] address
/// @param str2 char[] adress
/// @return
char	*deljoiner(char *dlm, char *str1, char *str2)
{
	char *str;
	str = ft_strjoin(str1, dlm);
	str = ft_strjoin(str, str2);
	return (str);
}

// char	*deljoiner(char dlm, ...)
// {
// 	va_list args;
// 	char *result = NULL;
// 	write(1,"here I AM THE BUG", 18);
// 	// Initialize va_list to iterate over arguments
// 	va_start(args, dlm);
// 	// Calculate the total length of the joined string
// 	char *arg = va_arg(args, char *);
// 	while (arg != NULL)
// 	{
// 		result = ft_strjoin(arg, &dlm);
// 		arg = va_arg(args, char *);
// 		result = ft_strjoin(result, arg ? arg : "");
// 	}

// 	// Clean up va_list
// 	va_end(args);

// 	return (result);
// }