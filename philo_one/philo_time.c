/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schips <schips@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:52:42 by schips            #+#    #+#             */
/*   Updated: 2021/03/03 20:53:20 by schips           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_header.h"

long	get_time_in_millisec(void)
{
	struct timeval	t;
	long			res_time;

	gettimeofday(&t, DST_NONE);
	res_time = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (res_time - g_start_time);
}

long	get_cur_time(void)
{
	struct timeval	t;
	long			current_time;

	gettimeofday(&t, DST_NONE);
	current_time = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (current_time);
}

void	philo_accurate_usleep(long time_to, t_philo *philo)
{
	struct timeval	t;
	long			current_time;
	long			res_time;

	gettimeofday(&t, DST_NONE);
	current_time = t.tv_sec * 1000 + t.tv_usec / 1000;
	res_time = current_time + time_to;
	while (current_time <= res_time && philo->info->flag_death == 0)
	{
		usleep(100);
		gettimeofday(&t, DST_NONE);
		current_time = t.tv_sec * 1000 + t.tv_usec / 1000;
		if (philo->info->flag_death == 1)
			break ;
	}
}
