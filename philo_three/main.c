#include "philosophers_header.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t i;

	i = 0;
	if (s != 0)
	{
		while (s[i] != 0)
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

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
	while (philo->info->flag_death != 1 && philo->need_to_eat != 0)
	{
		eat_even_philo(philo);
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
	if (!(all->info = malloc(sizeof(t_info))))
		return (philo_error("Malloc error\n"));
	if ((init_all(all, argc, argv)) == 1)
		return (1);
	i = 0;
	start_time = get_time_in_millisec();
	all->info->flag_death = 0;
	while (i < all->ph_count)
	{
		pthread_create(&(all->ph_thread[i]), NULL, philo_life, (void *)&(all->philo[i]));
		i++;
	}
//	i = 0;
//	while (all->info->flag_death == 0 && all->info->end_eat < all->info->ph_count)
//	{
//		if (get_cur_time() - all->philo[i].time_start_eat > all->info->time_die && all->philo[i].need_to_eat != 0)
//		{
//			sem_wait(all->info->print);
//			if (all->info->flag_death == 0)
//				printf("%ld %s died\n", get_time_in_millisec(), all->philo[i].philo_num_char);
//			sem_post(all->info->print);
//			all->info->flag_death = 1;
//			break;
//		}
//		i = (i + 1) % all->ph_count;
//	}
	return (0);
}
