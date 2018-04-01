#include	"../include/server.h"

void		accept_client(t_client *client)
{
    if (client != NULL)
    {
        if (g_client != NULL)
            client->next = g_client;
        g_client = client;
    }
}

t_client	*alloc_client(pid_t pid)
{
    t_client	*client;

    client = (t_client*)malloc(sizeof(t_client));
    client->pid = pid;
    client->len_bit = 0;
    client->next = NULL;
    client->packet_c = 0;
    ft_bzero(client->data, 50);
    accept_client(client);
    return (client);
}

void		remove_client(pid_t pid)
{
    t_client	*fnd;
    t_client	*tmp;

    fnd = g_client;
    if (fnd->pid == pid)
    {
        tmp = g_client;
        g_client = g_client->next;
        free(tmp);
        return ;
    }
    while (fnd->next && fnd->next->pid != pid);
    tmp = fnd->next;
    fnd->next = fnd->next->next;
    free(tmp);
}

t_client    *find_client(pid_t pid)
{
    t_client    *tmp;

    tmp = g_client;
    while (tmp)
    {
        if (tmp->pid == pid)
            return (tmp);
        tmp = tmp->next;
    }
    return (alloc_client(pid));
}

void		print_message(t_client *client)
{   
    if (client->packet_c == 0)
        ft_putstr("Packet " YELLOW);
    else
        ft_putstr("Packet " GREEN);
    ft_putnbr(client->packet_c);
    if (client->packet_c == 0)
        ft_putstr(RESET " from " YELLOW);
    else
        ft_putstr(RESET " from " GREEN);
    ft_putnbr(client->pid);
    ft_putstr(RESET " : ");
    ft_putstr(client->data);
    ft_putstr("\n");
    ft_bzero(client->data, 50);
    client->len_bit = 0;
    ++client->packet_c;
}
