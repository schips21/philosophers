#include "philosophers_header.h"

long	get_time_in_millisec()
{
	struct timeval	t;
	long			res_time;
	gettimeofday(&t, DST_NONE);
	res_time = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (res_time - start_time);
}

void	philo_accurate_usleep(long time_to)
{
	struct timeval	t;
	long current_time;
	long res_time;

	gettimeofday(&t, DST_NONE);
	current_time = t.tv_sec * 1000 + t.tv_usec / 1000;
	res_time = current_time + time_to;
//	current_time = res_time * 0.9;
	while (current_time <= res_time)
	{
		usleep(100);
		gettimeofday(&t, DST_NONE);
		current_time = t.tv_sec * 1000 + t.tv_usec / 1000;
	}
}