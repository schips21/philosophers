#include "philosophers_header.h"

long	get_time_in_millisec()
{
	struct timeval	t;
	long			res_time;
	gettimeofday(&t, DST_NONE);
	res_time = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (res_time - start_time);
}

long	get_cur_time()
{
	struct timeval	t;
	long current_time;

	gettimeofday(&t, DST_NONE);
	current_time = t.tv_sec * 1000 + t.tv_usec / 1000;
	return current_time;
}

void	philo_accurate_usleep(long time_to, t_philo	*philo)
{
	struct timeval	t;
	long current_time;
	long res_time;

	gettimeofday(&t, DST_NONE);
	current_time = t.tv_sec * 1000 + t.tv_usec / 1000;
	res_time = current_time + time_to;
	while (current_time <= res_time && philo->info->flag_death == 0)
	{
		usleep(100);
		gettimeofday(&t, DST_NONE);
		current_time = t.tv_sec * 1000 + t.tv_usec / 1000;
		if (philo->info->flag_death == 1)
			break;
	}
}
