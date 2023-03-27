/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:03:54 by rmount            #+#    #+#             */
/*   Updated: 2023/03/27 12:17:02 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    make_byte(int bit)
{
    int byte;
    int client_pid;

    byte = reconstruct(bit);
    if (byte > 0)
    {
        ft_printf("%c", byte);
    }
    if (!byte) 
    {
        ft_printf("\n");
    }
}

int main(void)
{
    int pid;

    pid = getpid();
    ft_printf("The server's PID is:%i\n", pid);
    signal(SIGUSR1, &make_byte);
    signal(SIGUSR2, &make_byte);
    while (1)
    {
        pause();
    }
}