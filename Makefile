# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmount <rmount@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 09:48:08 by rmount            #+#    #+#              #
#    Updated: 2023/03/27 10:14:01 by rmount           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iheaders
PRINTF = ft_printf/libftprintf.a

RM = rm -f

SRCS = srcs/go.c

all: $(PRINTF)
	make $(CLIENT)
	make $(SERVER)

$(PRINTF):
	$(MAKE) -C ./ft_printf

$(CLIENT):
	$(CC) $(CFLAGS) $(SRCS) $(PRINTF) -o $(CLIENT)

$(SERVER):
	$(CC) $(CFLAGS) $(SRCS) $(PRINTF) -o $(SERVER)

clean:
	$(MAKE) clean -C ./ft_printf

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	$(RM) $(CLIENT)
	$(RM) $(SERVER)

re: fclean all

.PHONY: all clean fclean re