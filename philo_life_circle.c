#include "philosophers_header.h"

void eat_odd_philo(t_philo	*philo)
{
	pthread_mutex_lock(philo->right_fork);

	if (philo->info->flag_death == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		return;
	}
	else if (get_cur_time() - philo->time_start_eat >= philo->info->time_die)
	{
		pthread_mutex_lock(philo->print); //для вывода
		if (philo->info->flag_death == 0)
			printf("%ld %s died\n", get_time_in_millisec(), philo->philo_num_char);
		pthread_mutex_unlock(philo->print); //для вывода
		pthread_mutex_unlock(philo->right_fork);
		philo->info->flag_death = 1;
		return;
	}

	pthread_mutex_lock(philo->print); //для вывода
	printf("%ld %s has taken a right fork\n", get_time_in_millisec(), philo->philo_num_char);
//	philo_print(" has taken a right fork\n", philo);
	pthread_mutex_unlock(philo->print);


	pthread_mutex_lock(philo->left_fork);

	if (philo->info->flag_death == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return;
	}

	pthread_mutex_lock(philo->print); //для вывода
	printf("%ld %s has taken a left fork\n", get_time_in_millisec(), philo->philo_num_char);
	printf("%ld %s is eating\n", get_time_in_millisec(), philo->philo_num_char);
//	philo_print(" has taken a left fork\n", philo);
//	philo_print(" is eating\n", philo);
	pthread_mutex_unlock(philo->print);

	philo->time_start_eat = get_cur_time();
	philo_accurate_usleep(philo->info->time_eat, philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void eat_even_philo(t_philo	*philo)
{
	pthread_mutex_lock(philo->left_fork);

	if (philo->info->flag_death == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return;
	}
	else if (get_cur_time() - philo->time_start_eat >= philo->info->time_die)
	{
		pthread_mutex_lock(philo->print); //для вывода
		if (philo->info->flag_death == 0)
			printf("%ld %s died\n", get_time_in_millisec(), philo->philo_num_char);
		pthread_mutex_unlock(philo->print); //для вывода
		pthread_mutex_unlock(philo->left_fork);
		philo->info->flag_death = 1;
		return;
	}

	pthread_mutex_lock(philo->print); //для вывода
	printf("%ld %s has taken a left fork\n", get_time_in_millisec(), philo->philo_num_char);
//	philo_print(" has taken a left fork\n", philo);
	pthread_mutex_unlock(philo->print);

	pthread_mutex_lock(philo->right_fork);

	if (philo->info->flag_death == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		return;
	}

	pthread_mutex_lock(philo->print); //для вывода
	printf("%ld %s has taken a right fork\n", get_time_in_millisec(), philo->philo_num_char);
	printf("%ld %s is eating\n", get_time_in_millisec(), philo->philo_num_char);
//	philo_print(" has taken a right fork\n", philo);
//	philo_print(" is eating\n", philo);
	pthread_mutex_unlock(philo->print);

	philo->time_start_eat = get_cur_time();
	pthread_mutex_lock(philo->print); //для вывода
//	printf("%s time %ld\n", philo->philo_num_char, philo->time_start_eat - start_time);
	pthread_mutex_unlock(philo->print);
	philo_accurate_usleep(philo->info->time_eat, philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleep_and_think(t_philo	*philo)
{
	if (philo->info->flag_death == 1)
		return;
	pthread_mutex_lock(philo->print); //для вывода
	printf("%ld %s is sleeping\n", get_time_in_millisec(), philo->philo_num_char);
//	philo_print(" is sleeping\n", philo);
	pthread_mutex_unlock(philo->print);
	philo_accurate_usleep(philo->info->time_sleep, philo);

	if (philo->info->flag_death == 1)
		return;

	pthread_mutex_lock(philo->print); //для вывода
	printf("%ld %s is thinking\n", get_time_in_millisec(), philo->philo_num_char);
//	philo_print(" is thinking\n", philo);
	pthread_mutex_unlock(philo->print);
}