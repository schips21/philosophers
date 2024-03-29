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
		all->philo[i].print = all->forks[all->ph_count];
		all->philo[i].left_fork = all->forks[i];
		if (i == 0)
			all->philo[i].right_fork = all->forks[all->ph_count - 1];
		else
			all->philo[i].right_fork = all->forks[i - 1];
		all->philo[i].max_eat = all->info->must_eat;
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
	int i;

	i = 0;
	all->forks = NULL;
	if (!(all->forks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *)
	* (all->ph_count + 1))))
		return (philo_error("Malloc error\n"));
	while (i <= all->ph_count)
	{
		if (!(all->forks[i] = malloc(sizeof(pthread_mutex_t))))
			return (philo_error("Malloc error\n"));
		i++;
	}
	i = 0;
	while (i <= all->ph_count)
	{
		if ((pthread_mutex_init(all->forks[i], NULL)) != 0)
			return (philo_error("Mutex init error\n"));
		i++;
	}
	return (0);
}

int		init_validation(t_all *all)
{
	if (all->ph_count == -2 || all->info->time_die == -2 ||
		all->info->time_eat == -2 || all->info->time_sleep == -2 ||
		all->info->must_eat == -2)
		return (1);
	if (all->ph_count > 200 || all->info->time_die < 60 ||
		all->info->time_eat < 60 || all->info->time_sleep < 60)
		return (1);
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
		all->info->must_eat = -1;
	else
		all->info->must_eat = ft_atoi(argv[5]);
	if (init_validation(all) == 1)
		return (philo_error("Initialization error\n"));
	if (!(all->philo = (t_philo *)malloc(sizeof(t_philo) * all->ph_count)))
		return (philo_error("Malloc error\n"));
	if (init_forks(all) == 1)
		return (1);
	init_philo(all);
	return (0);
}
