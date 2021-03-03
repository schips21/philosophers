# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schips <schips@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/03 21:38:52 by schips            #+#    #+#              #
#    Updated: 2021/03/03 21:53:02 by schips           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three

SRCS = ft_atoi.c ft_itoa.c main.c philo_init.c philo_life_circle.c \
		philo_time.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all