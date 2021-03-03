cmake_minimum_required(VERSION 3.17)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

add_executable(philo_one
        philo_one/philosophers_header.h
        philo_one/main.c
        philo_one/philo_print.c
        philo_one/philo_init.c
        philo_one/ft_atoi.c
        philo_one/ft_itoa.c
        philo_one/philo_time.c
        philo_one/philo_life_circle.c)

add_executable(philo_two
        philo_two/philosophers_header.h
        philo_two/main.c
        philo_two/philo_init.c
        philo_two/ft_atoi.c
        philo_two/ft_itoa.c
        philo_two/philo_time.c
        philo_two/philo_life_circle.c)

add_executable(philo_three
        philo_three/philosophers_header.h
        philo_three/main.c
        philo_three/philo_init.c
        philo_three/ft_atoi.c
        philo_three/ft_itoa.c
        philo_three/philo_time.c
        philo_three/philo_life_circle.c)
