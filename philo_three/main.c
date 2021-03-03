/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schips <schips@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:32:23 by schips            #+#    #+#             */
/*   Updated: 2021/03/03 20:38:34 by schips           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_header.h"

int		philo_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	*philo_check_death(void *philo_2)
{
	t_philo	*philo;

	philo = (t_philo *)philo_2;
	while (philo->info->flag_death == 0 &&
	philo->info->end_eat < philo->info->ph_count)
	{
		if (philo->need_to_eat == 0)
			exit(2);
		if (get_cur_time() - philo->time_start_eat > philo->info->time_die &&
		philo->need_to_eat != 0)
		{
			sem_wait(philo->info->dead_philo);
			sem_wait(philo->info->print);
			if (philo->info->flag_death == 0)
				printf("%ld %s died\n", get_time_in_millisec(),
				philo->philo_num_char);
			sem_post(philo->info->print);
			philo->info->flag_death = 1;
			exit(1);
		}
	}
	return (0x000);
}

void	*philo_life(void *philo_2)
{
	t_philo	*philo;

	philo = (t_philo *)philo_2;
	pthread_create(&(philo->info->ph_thread[philo->philo_id]), NULL,
	philo_check_death, philo_2);
	if (philo->philo_id % 2 == 0)
		usleep(150);
	while (philo->info->flag_death != 1 && philo->need_to_eat != 0)
	{
		eat_even_philo(philo);
		sleep_and_think(philo);
	}
	return (0x000);
}

int		main_proc(t_all *all, int i)
{
	pid_t	pid;

	g_start_time = get_time_in_millisec();
	while (i < all->ph_count)
	{
		pid = fork();
		if (pid < 0)
			return (philo_error("Process error\n"));
		if (pid == 0)
			philo_life((void *)&(all->philo[i]));
		all->philo[i].pid = pid;
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_all	*all;
	int		i;
	int		exit_stat;

	if (argc != 5 && argc != 6)
		return (philo_error("Error: wrong number of arguments\n"));
	if (!(all = (t_all*)malloc(sizeof(t_all))))
		return (philo_error("Malloc error\n"));
	if (!(all->info = malloc(sizeof(t_info))))
		return (philo_error("Malloc error\n"));
	if ((init_all(all, argc, argv)) == 1)
		return (1);
	all->info->flag_death = 0;
	if (main_proc(all, 0) == 1)
		exit(1);
	waitpid(-1, &exit_stat, WUNTRACED);
	i = 0;
	while (i < all->ph_count)
	{
		kill(all->philo[i].pid, SIGTERM);
		i++;
	}
	exit(0);
}
