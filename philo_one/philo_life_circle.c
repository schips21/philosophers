/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_circle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schips <schips@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:55:17 by schips            #+#    #+#             */
/*   Updated: 2021/03/03 20:59:32 by schips           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_header.h"

void	eat_even_philo_last(t_philo *philo)
{
	philo->time_start_eat = get_cur_time();
	pthread_mutex_lock(philo->print);
	pthread_mutex_unlock(philo->print);
	philo_accurate_usleep(philo->info->time_eat, philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (philo->need_to_eat > 0)
		philo->need_to_eat--;
	if (philo->need_to_eat == 0)
		philo->info->end_eat++;
}

void	eat_even_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (philo->info->flag_death == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->print);
	printf("%ld %s has taken a fork\n", get_time_in_millisec(),
	philo->philo_num_char);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->right_fork);
	if (philo->info->flag_death == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->print);
	printf("%ld %s has taken a fork\n", get_time_in_millisec(),
	philo->philo_num_char);
	printf("%ld %s is eating\n", get_time_in_millisec(), philo->philo_num_char);
	pthread_mutex_unlock(philo->print);
	eat_even_philo_last(philo);
}

void	sleep_and_think(t_philo *philo)
{
	if (philo->info->flag_death == 1)
		return ;
	pthread_mutex_lock(philo->print);
	printf("%ld %s is sleeping\n", get_time_in_millisec(),
	philo->philo_num_char);
	pthread_mutex_unlock(philo->print);
	philo_accurate_usleep(philo->info->time_sleep, philo);
	if (philo->info->flag_death == 1)
		return ;
	pthread_mutex_lock(philo->print);
	printf("%ld %s is thinking\n", get_time_in_millisec(),
	philo->philo_num_char);
	pthread_mutex_unlock(philo->print);
}
