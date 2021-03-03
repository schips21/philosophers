#include "philosophers_header.h"

void eat_even_philo(t_philo	*philo)
{
	sem_wait(philo->info->forks);
	if (philo->info->flag_death == 1)
	{
		sem_post(philo->info->forks);
		return;
	}

	sem_wait(philo->info->print);
	printf("%ld %s has taken a fork\n", get_time_in_millisec(), philo->philo_num_char);
	sem_post(philo->info->print);

	sem_wait(philo->info->forks);
	if (philo->info->flag_death == 1)
	{
		sem_post(philo->info->forks);
		return;
	}

	sem_wait(philo->info->print);
	printf("%ld %s has taken a fork\n", get_time_in_millisec(), philo->philo_num_char);
	printf("%ld %s is eating\n", get_time_in_millisec(), philo->philo_num_char);
	sem_post(philo->info->print);

	philo->time_start_eat = get_cur_time();
	philo_accurate_usleep(philo->info->time_eat, philo);
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
	if (philo->need_to_eat > 0)
		philo->need_to_eat--;
	if (philo->need_to_eat == 0)
		philo->info->end_eat++;

}

void	sleep_and_think(t_philo	*philo)
{
	if (philo->info->flag_death == 1)
		return;
	sem_wait(philo->info->print);
	printf("%ld %s is sleeping\n", get_time_in_millisec(), philo->philo_num_char);
	sem_post(philo->info->print);
	philo_accurate_usleep(philo->info->time_sleep, philo);

	if (philo->info->flag_death == 1)
		return;

	sem_wait(philo->info->print);
	printf("%ld %s is thinking\n", get_time_in_millisec(), philo->philo_num_char);
	sem_post(philo->info->print);
}