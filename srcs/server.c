/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:03:54 by rmount            #+#    #+#             */
/*   Updated: 2023/03/31 17:15:41 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	When a bit is received from the client, this function is called by
	the signal handler defined in the main.
	We define the byte variable and assign it the value of calling
	the reconstruct function (passing it the current bit).
	The completed byte is returned from the reconstruct function,
	and then we either print the byte (if its value is over 0), or print a new
	line if byte is null.
*/
void	make_byte(int bit)
{
	int	byte;

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

/*
	This function is called when the server executable is run.
	We use the getpid function (part of the unistd library) to
	get the process id of the current process (the server) and 
	assign it to a variable and then print it (so it can be 
	entered when running the client executable).

	We then use the signal function to set handlers for the 
	two different signals - SIGUSR1 and SIGUSR2 - so that when
	either of these signals are received by this process, 
	they are routed to the make_byte function.

	Finally, in order to keep the server running while we send
	bits from the client, we create a while loop that remains
	true and call the pause function which suspends program 
	execution until a signal arrives whose action is either 
	to execute a handler function, or to terminate the process.
*/
int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("The server's PID is:%i\n", pid);
	signal(SIGUSR1, &make_byte);
	signal(SIGUSR2, &make_byte);
	while (1)
	{
		pause();
	}
}
