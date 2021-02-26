#include "philosophers_header.h"

int		init_philo(t_all *all)
{
	int i;

	i = 0;
	if (!(all->ph_thread = malloc(sizeof(pthread_t) * all->ph_count)))
		return (philo_error("Malloc error\n"));
	while (i < all->ph_count)
	{
		all->philo[i].philo_id = i;
		all->philo[i].philo_num_char = ft_itoa(all->philo[i].philo_id + 1);
		all->philo[i].info = all->info;
		all->philo[i].time_start_eat = get_cur_time();
		if (all->info->must_eat == -1)
			all->philo[i].need_to_eat = -1;
		else
			all->philo[i].need_to_eat = all->info->must_eat;
		i++;
	}
	return (0);
}

int		init_forks(t_all *all)
{
	if (!(all->info->forks = malloc(sizeof(sem_t*))))
		return (philo_error("Malloc error\n"));
	all->info->forks = sem_open("/forks", O_CREAT | S_IRWXU, 0644, all->info->ph_count);
//	if (sem_init(all->info->forks, 0, all->ph_count) == -1)
//		return (philo_error("Semaphore error\n"));
	if (!(all->info->print = malloc(sizeof(sem_t*))))
		return (philo_error("Malloc error\n"));
	all->info->print = sem_open("/print", O_CREAT | S_IRWXU, 0644, 1);
//	if (sem_init(all->info->print, 0, 1) == -1)
//		return (philo_error("Semaphore error\n"));
	return (0);
}

int		init_all(t_all *all, int argc, char **argv)
{
	all->ph_count = ft_atoi(argv[1]);
	all->info->ph_count = all->ph_count;
	all->info->time_die = ft_atoi(argv[2]);
	all->info->end_eat = 0;
	all->info->time_eat = ft_atoi(argv[3]);
	all->info->time_sleep = ft_atoi(argv[4]);
	if (argc == 5)
	{
		all->info->must_eat = -1;
//		all->info->end_eat = -1;
	}
	else
		all->info->must_eat = ft_atoi(argv[5]);
	// добавить проверку валидности параметров
	if (!(all->philo = malloc(sizeof(t_philo) * all->ph_count)))
		return (philo_error("Malloc error\n"));
	if (init_forks(all) == 1)
		return (1);
	// инициализация каждого философа
	init_philo(all);
	printf("%d\n", all->info->end_eat);
	return (0);
}