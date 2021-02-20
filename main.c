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
	philo->time_start_eat = get_cur_time();
	while (philo->info->flag_death != 1)
	{
		//eat
		if (philo->philo_id % 2 != 0)
			eat_odd_philo(philo);
		else
			eat_even_philo(philo);
		//sleep and think
		sleep_and_think(philo);
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
	all->info->flag_death = 0;
	while (i < all->ph_count)
	{
//		if (i % 2 == 1)
//			usleep(100);
		pthread_create(&(all->ph_thread[i]), NULL, philo_life, (void *)&(all->philo[i]));
		i++;
		usleep(30);
	}
	usleep(10);
	i = 0;
	while (all->info->flag_death == 0)
	{
		if (get_cur_time() - all->philo[i].time_start_eat > all->info->time_die)
		{
			pthread_mutex_lock(all->philo[i].print); //для вывода
//			printf("%ld %ld\n", get_cur_time() - start_time, all->philo[i].time_start_eat - start_time);
			if (all->info->flag_death == 0)
				printf("%ld %s died in main %ld\n", get_time_in_millisec(), all->philo[i].philo_num_char, get_cur_time() - all->philo[i].time_start_eat);
			pthread_mutex_unlock(all->philo[i].print); //для вывода
			all->info->flag_death = 1;
			break;
		}
		i = (i + 1) % all->ph_count;
	}
	return (0);
}
