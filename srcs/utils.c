/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:18:04 by rmount            #+#    #+#             */
/*   Updated: 2023/03/31 14:35:05 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
