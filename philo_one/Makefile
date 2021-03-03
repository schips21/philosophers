# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schips <schips@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 21:38:52 by schips            #+#    #+#              #
#    Updated: 2021/03/03 21:42:45 by schips           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
FLAG = -Wall -Wextra -Werror

SRCS = *.c

# HEADER = libft.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJS) -o $@

%.o: %.c
	gcc $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all