/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:18:04 by rmount            #+#    #+#             */
/*   Updated: 2023/03/31 17:15:39 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* 	This function is called by the make_byte function in the server repeatedly 
	to convert the sent signals (SIGUSR1 & SIGUSER 2) into 1s and 0s which 
	are then bit-shifted by the value of i (the count of bits already added 
	to the byte) and then added to the 'byte' variable.
	The bit shifting puts the new 1 in the correct location, and adding them to
	the value of byte brings the existing 1s back in. It's difficult to 
	explain this without an example.
	Once this variable is full (has had 8 bits written to it), it assigns 
	the value of the byte to another variable - re, resets byte and i to zero,
	then returns re.
*/
int	reconstruct(int bit)
{
	static int		byte;
	static int		i;
	char			re;

	if (bit == SIGUSR1)
	{
		bit = 1;
	}
	else
	{
		bit = 0;
	}
	byte += bit << i;
	i++;
	if (i == 8)
	{
		re = byte;
		byte = 0;
		i = 0;
		return (re);
	}
	return (-1);
}

/*
	This function is called by the send function in the client.
	It takes the byte we are sending and the process ID of the
	server process. 
	As long as byte is true (not zero) or the count of i is less
	than 8 the while loop will continue.
	We then check if the byte is odd or even by %2. If it is 
	odd we send SIGUSR1 to the server. If it's even, we send 
	SIGUSR2 to the server.
	We then bitshift byte to the right by 1, which drops the 
	right most number off the end and adds a zero to the 
	left end, and increment i.
	This continues until i reaches 8 which ends the while
	loop and we return to send where this function was 
	called from.
*/
void	deconstruct(int byte, int pid)
{
	int	i;

	i = 0;
	while (byte || i < 8)
	{
		if (byte % 2)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		byte >>= 1;
		usleep(100);
		i++;
	}
}
