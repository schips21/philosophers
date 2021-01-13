cmake_minimum_required(VERSION 3.17)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

add_executable(philosophers
        philosophers_header.h
        main.c
        ft_putstr_fd.c
        philo_init.c
        ft_atoi.c
        ft_itoa.c)
