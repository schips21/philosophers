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
	if (philo->philo_id % 2 == 0)
		usleep(150);
//	if (philo->philo_id % 2 == 1)
//	{
//		pthread_mutex_lock(philo->info->lock_for_even_odd);
//		pthread_mutex_unlock(philo->info->lock_for_even_odd);
//	}
	while (philo->info->flag_death != 1 && philo->need_to_eat != 0)
	{
		eat_even_philo(philo);
		sleep_and_think(philo);
	}
//	if (philo->need_to_eat == 0)
//		philo->info->must_eat--;
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

//	if (!(all->info->lock_for_even_odd = malloc(sizeof(pthread_mutex_t))))
//		return (philo_error("Malloc error\n"));
//	if ((pthread_mutex_init(all->info->lock_for_even_odd, NULL)) != 0)
//		return (philo_error("Mutex init error\n"));
//	pthread_mutex_lock(all->info->lock_for_even_odd);

	while (i < all->ph_count)
	{
		pthread_create(&(all->ph_thread[i]), NULL, philo_life, (void *)&(all->philo[i]));
//		if ((all->info->ph_count % 2 == 1 && i == all->info->ph_count - 1) ||
//			(all->info->ph_count % 2 == 0 && i == all->info->ph_count - 1))
//			pthread_mutex_unlock(all->info->lock_for_even_odd);
		i++;
//		usleep(30);
	}
//	usleep(10);
	i = 0;
	while (all->info->flag_death == 0 && all->info->end_eat < all->info->ph_count)
	{
		if (get_cur_time() - all->philo[i].time_start_eat > all->info->time_die && all->philo[i].need_to_eat != 0)
		{
			pthread_mutex_lock(all->philo[i].print); //для вывода
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
