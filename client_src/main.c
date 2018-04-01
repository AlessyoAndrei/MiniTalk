#include "../include/server.h"

int		send(pid_t server_pid, char c)
{
    int		bit;
    int		signal;

    bit = 7;
    while (bit >= 0 )
    {
        if (((c >> bit) & 1) == 1)
            signal = SIGUSR1;
        else
            signal = SIGUSR2;
        if (kill(server_pid, signal) == -1)
        {
           ft_putstr(RED "Unable to send meessage.\n" RESET);
           return (0);
        }
        pause();
        --bit;
    }
    return (1);
}

int		send_message(pid_t server_pid, char *message)
{
    int		i;

    ft_putstr(YELLOW "Attempting to send message to server.\n" RESET);
    i = -1;
    while (message[++i] != '\0')
        if (!send(server_pid, message[i]))
            return (0);
    send(server_pid, '\0');
    ft_putstr(GREEN "Message successfully sent.\n" RESET);
    return (0);
}

void    receiver(int signal)
{
    if (signal)
    {
    }
}

int		main(int argc, char **argv)
{
    pid_t		server_pid;

    if (argc == 3)
    {
        signal(SIGUSR1, receiver);
        server_pid = (pid_t)ft_atoi(argv[1]);
        if (server_pid < 1)
        {
            ft_putstr(RED "Incorrect SERVER-PID\n" RESET);
            return (0);
        }
        ft_putstr("PID: " CYAN);
        ft_putnbr(getpid());
        ft_putstr(RESET "\n");
        send_message(server_pid, argv[2]);
    }
    else
        ft_putstr("Usage: ./client server-pid message\n");
    return (0);
}
