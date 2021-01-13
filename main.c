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
			ft_putstr_fd(philo->philo_num_char, 1);
			ft_putstr_fd(" has taken a right fork\n", 1);
			pthread_mutex_unlock(philo->print);

			pthread_mutex_lock(philo->left_fork);
			usleep(1000);
			pthread_mutex_lock(philo->print); //для вывода
			ft_putstr_fd(philo->philo_num_char, 1);
			ft_putstr_fd(" has taken a left fork\n", 1);
			pthread_mutex_unlock(philo->print);

			pthread_mutex_lock(philo->print);
			ft_putstr_fd(philo->philo_num_char, 1);
			ft_putstr_fd(" is eating\n", 1);
			pthread_mutex_unlock(philo->print);
			usleep(philo->info->time_eat * 1000);
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
		}
		else
		{
			pthread_mutex_lock(philo->left_fork);
			pthread_mutex_lock(philo->print); //для вывода
			ft_putstr_fd(philo->philo_num_char, 1);
			ft_putstr_fd(" has taken a left fork\n", 1);
			pthread_mutex_unlock(philo->print);

			pthread_mutex_lock(philo->right_fork);
			usleep(1000);

			pthread_mutex_lock(philo->print); //для вывода
			ft_putstr_fd(philo->philo_num_char, 1);
			ft_putstr_fd(" has taken a right fork\n", 1);
			pthread_mutex_unlock(philo->print);

			pthread_mutex_lock(philo->print);
			ft_putstr_fd(philo->philo_num_char, 1);
			ft_putstr_fd(" is eating\n", 1);
			pthread_mutex_unlock(philo->print);
			usleep(philo->info->time_eat * 1000);

			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
		}
		//sleep
		pthread_mutex_lock(philo->print); //для вывода
		ft_putstr_fd(philo->philo_num_char, 1);
		ft_putstr_fd(" is sleeping\n", 1);
		pthread_mutex_unlock(philo->print);
		usleep(philo->info->time_sleep);

//		think
		pthread_mutex_lock(philo->print); //для вывода
		ft_putstr_fd(philo->philo_num_char, 1);
		ft_putstr_fd(" is thinking\n", 1);
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
	if ((init_all(all, argc, argv)) == 1)
		return (1);
	i = 0;
	while (i < all->ph_count)
	{
		pthread_create(&(all->ph_thread[i]), NULL, philo_life, (void *)&(all->philo[i]));
		i++;
//		usleep(50);
	}
	while (42)
	{
		int i =0;
	}
	return (0);
}
