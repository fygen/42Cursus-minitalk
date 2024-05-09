#include "minitalk.h"

#define BUFFER_SIZE 256

/// @brief print the pid of the server
/// @param n integer to be printed
void ft_putpid(pid_t n)
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
void incoming_signal_to_output(int signal)
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
void send_data_to_pid(pid_t id, char *message)
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

int send_data_realtime(pid_t id)
{
    char buffer[BUFFER_SIZE];
    int num_bytes_read;

    while (1)
    {
        // Read input from stdin
        num_bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);

        if (num_bytes_read == -1)
        {
            write(STDOUT_FILENO, "no data: ", 10);
            return 1;
        }

        // Check if 'q' was entered
        if (buffer[0] == 'q' && num_bytes_read == 2)
        {
            write(STDOUT_FILENO, "Quit entered.", 13);
            break;
        }

        // Write input to stdout
        write(STDOUT_FILENO, "You entered: ", 13);
        write(STDOUT_FILENO, buffer, num_bytes_read);
        send_data_to_pid(id, buffer);

        // Clear buffer
        for (int i = 0; i < BUFFER_SIZE; i++)
        {
            buffer[i] = '\0';
        }
    }

    return 0;
}
