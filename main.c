#include "philosophers_header.h"

int	philo_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

void	*philo_life(void *philo_2)
{
	t_philo	*philo;

	philo = (t_philo *)philo_2;
	while (philo->max_eat != -2)
	{
		//eat
		if (philo->philo_id % 2 != 0)
		{
			pthread_mutex_lock(philo->right_fork);
			pthread_mutex_lock(philo->print); //для вывода
			printf("%ld %s has taken a right fork\n", get_time_in_millisec(), philo->philo_num_char);
//			philo_print(" has taken a right fork\n", philo);
			pthread_mutex_unlock(philo->print);

			pthread_mutex_lock(philo->left_fork);
			pthread_mutex_lock(philo->print); //для вывода
			printf("%ld %s has taken a left fork\n", get_time_in_millisec(), philo->philo_num_char);
			printf("%ld %s is eating\n", get_time_in_millisec(), philo->philo_num_char);
//			philo_print(" has taken a left fork\n", philo);
//			philo_print(" is eating\n", philo);
			pthread_mutex_unlock(philo->print);

			//
			philo_accurate_usleep(philo->info->time_eat);
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
		}
		else
		{
			pthread_mutex_lock(philo->left_fork);
			pthread_mutex_lock(philo->print); //для вывода
			printf("%ld %s has taken a left fork\n", get_time_in_millisec(), philo->philo_num_char);
//			philo_print(" has taken a left fork\n", philo);
			pthread_mutex_unlock(philo->print);

			pthread_mutex_lock(philo->right_fork);
			pthread_mutex_lock(philo->print); //для вывода
			printf("%ld %s has taken a right fork\n", get_time_in_millisec(), philo->philo_num_char);
			printf("%ld %s is eating\n", get_time_in_millisec(), philo->philo_num_char);
//			philo_print(" has taken a right fork\n", philo);
//			philo_print(" is eating\n", philo);
			pthread_mutex_unlock(philo->print);
			philo_accurate_usleep(philo->info->time_eat);

			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
		}
		//sleep
		pthread_mutex_lock(philo->print); //для вывода
		printf("%ld %s is sleeping\n", get_time_in_millisec(), philo->philo_num_char);
//		philo_print(" is sleeping\n", philo);
		pthread_mutex_unlock(philo->print);
		philo_accurate_usleep(philo->info->time_sleep);

//		think
		pthread_mutex_lock(philo->print); //для вывода
		printf("%ld %s is thinking\n", get_time_in_millisec(), philo->philo_num_char);
//		philo_print(" is thinking\n", philo);
		pthread_mutex_unlock(philo->print);
	}
	return (0x000);
}

int main(int argc, char **argv)
{
	t_all	*all;
	int		i;

	if (argc != 5 && argc != 6)
		return (philo_error("Error: wrong number of arguments\n"));
	if (!(all = (t_all*)malloc(sizeof(t_all))))
		return (philo_error("Malloc error\n"));
	if (!(all->info = malloc(sizeof(all->info))))
		return (philo_error("Malloc error\n"));
	if ((init_all(all, argc, argv)) == 1)
		return (1);
	i = 0;
	start_time = get_time_in_millisec();
	while (i < all->ph_count)
	{
		pthread_create(&(all->ph_thread[i]), NULL, philo_life, (void *)&(all->philo[i]));
		i++;
	}
	while (42)
	{
		int i =0;
	}
	return (0);
}
