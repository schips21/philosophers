#include "philosophers_header.h"

void eat_even_philo(t_philo	*philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (philo->info->flag_death == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return;
	}

	pthread_mutex_lock(philo->print); //для вывода
	printf("%ld %s has taken a left fork\n", get_time_in_millisec(), philo->philo_num_char);
	pthread_mutex_unlock(philo->print);

	pthread_mutex_lock(philo->right_fork);
	if (philo->info->flag_death == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		return;
	}
//	if ((philo->info->ph_count % 2 == 1 && philo->philo_id == philo->info->ph_count - 1) ||
//		(philo->info->ph_count % 2 == 0 && philo->philo_id == philo->info->ph_count - 1))
//		pthread_mutex_unlock(philo->info->lock_for_even_odd);

	pthread_mutex_lock(philo->print); //для вывода
	printf("%ld %s has taken a right fork\n", get_time_in_millisec(), philo->philo_num_char);
	printf("%ld %s is eating\n", get_time_in_millisec(), philo->philo_num_char);
	pthread_mutex_unlock(philo->print);

	philo->time_start_eat = get_cur_time();
	pthread_mutex_lock(philo->print); //для вывода
	pthread_mutex_unlock(philo->print);
	philo_accurate_usleep(philo->info->time_eat, philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
//	printf("%d philo->need_to_eat %d\n", philo->philo_id, philo->need_to_eat);
	if (philo->need_to_eat > 0)
		philo->need_to_eat--;
	if (philo->need_to_eat == 0)
	{
		philo->info->end_eat++;
//		printf("%d must eat %d\n", philo->philo_id, philo->info->end_eat);
	}
}

void	sleep_and_think(t_philo	*philo)
{
	if (philo->info->flag_death == 1)
		return;
	pthread_mutex_lock(philo->print); //для вывода
	printf("%ld %s is sleeping\n", get_time_in_millisec(), philo->philo_num_char);
	pthread_mutex_unlock(philo->print);
	philo_accurate_usleep(philo->info->time_sleep, philo);

	if (philo->info->flag_death == 1)
		return;

	pthread_mutex_lock(philo->print); //для вывода
	printf("%ld %s is thinking\n", get_time_in_millisec(), philo->philo_num_char);
	pthread_mutex_unlock(philo->print);
}