/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schips <schips@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:04:58 by schips            #+#    #+#             */
/*   Updated: 2021/03/03 21:36:18 by schips           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_header.h"

int		philo_error(char *str)
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

void	main_check_death(t_all *all, int i)
{
	while (all->info->flag_death == 0 &&
	all->info->end_eat < all->info->ph_count)
	{
		if (get_cur_time() - all->philo[i].time_start_eat > all->info->time_die
		&& all->philo[i].need_to_eat != 0)
		{
			sem_wait(all->info->print);
			if (all->info->flag_death == 0)
				printf("%ld %s died\n", get_time_in_millisec(),
				all->philo[i].philo_num_char);
			sem_post(all->info->print);
			all->info->flag_death = 1;
			break ;
		}
		i = (i + 1) % all->ph_count;
	}
}

int		main(int argc, char **argv)
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
	g_start_time = get_time_in_millisec();
	all->info->flag_death = 0;
	while (i < all->ph_count)
	{
		pthread_create(&(all->ph_thread[i]), NULL, philo_life,
		(void *)&(all->philo[i]));
		i++;
	}
	main_check_death(all, i);
	return (0);
}
