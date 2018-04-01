#include "../include/server.h"

int     parse_message(pid_t pid, int bit)
{
    int         len;
    t_client    *client;

    if ((client = find_client(pid)) != NULL)
    {
        len = (client->len_bit / 8);
        if (len >= 50)
        {
            client->data[len] = '\0';
            print_message(client);
        }
        client->data[len] = ((client->data[len] << 1) | bit);
        ++client->len_bit;
        if ((client->len_bit % 8) == 0 && client->data[len] == '\0')
            print_message(client);
        return (1);
    }
    return (0);
}

void        handler(int signal, siginfo_t *info, void *tmp)
{
    if (info != NULL && tmp != NULL)
        if (!parse_message(info->si_pid, signal == SIGUSR1))
            ft_putstr("error.\n");
}

void        exit_c(int signal)
{
    t_client    *tmp;

    if (signal == SIGINT)
    {
        if (g_client)
            while (g_client)
            {
                tmp = g_client;
                g_client = g_client->next;
                free(tmp);
            }
        exit(0);
    }
}

void		listen()
{
    t_client	*tmp;

    while (1)
    {
        usleep(100);
        tmp = g_client;
        while (tmp)
        {
            if (kill(tmp->pid, SIGUSR1) == -1)
                    remove_client(tmp->pid);
            tmp = tmp->next;
        }
    }
}

int		main()
{
    pid_t			    server_pid;
    struct sigaction	action;

    action.sa_sigaction = handler;
    action.sa_flags = SA_SIGINFO | SA_ONSTACK;
    g_client = NULL;
    if (sigaction(SIGUSR1, &action, NULL) == 0 && sigaction(SIGUSR2, &action, NULL) == 0 && signal(SIGINT, exit_c) == 0)
    {
        server_pid = getpid();
        ft_putstr("Server-PID: "CYAN);
        ft_putnbr((int)server_pid);
        ft_putstr(RESET "\n");
        listen();
        return (0);
    }
    else
        ft_putstr("Fail.\n");
    return (1);
}
