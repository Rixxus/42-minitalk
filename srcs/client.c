/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:32:33 by rmount            #+#    #+#             */
/*   Updated: 2023/03/31 17:17:14 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	This function is called by the main function in the client.
	It takes the process ID of the server and the string that
	we are sending to the server.
	It steps through the string one char at a time, and calls the 
	deconstruct function, passing the current char and the server's PID.
	Once we reach the end of the string, we send a zero to the deconstruct
	function.
*/
void	send(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		deconstruct(str[i], pid);
		i++;
	}
	deconstruct(0, pid);
}

/*
When the main is executed, args should include a client PID and a message, making
argc == 3. If this doesn't happen, we write an error message and return 1.
We then call the send function.
ft_atoi is called on argv[1] (the server's process id) to pass it as a number 
instead of a string, then we call the send function with the parameters of 
the PID and the string we want to send (argv[2]).
*/
int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error. Input should be: ./client <PID> <MESSAGE>\n");
		return (-1);
	}
	send(ft_atoi(argv[1]), argv[2]);
	return (0);
}
