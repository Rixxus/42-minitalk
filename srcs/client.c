/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:32:33 by rmount            #+#    #+#             */
/*   Updated: 2023/03/27 12:32:11 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send(int pid, char *str)
{
    int i;
    int client_pid;

    client_pid = getpid();
    deconstruct(client_pid, pid, 32);
    i = 0;
    while (str[i])
    {
        deconstruct((unsigned char)str[i], pid, 8);
        i++;
    }
    deconstruct(0, pid, 8);
}

/*
When the main is executed, args should include a client PID and a message, making
argc == 3. If this doesn't happen, we write an error message and return 1.
We then call the send function.
*/
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_printf("Error. Input should be: ./client <PID> <MESSAGE>\n");
        return (-1);
    }
    send(ft_atoi(argv[1]), argv[2]);
    return (0);
}