/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_header.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schips <schips@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:24:13 by schips            #+#    #+#             */
/*   Updated: 2021/03/03 21:24:44 by schips           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_HEADER_H
# define PHILOSOPHERS_HEADER_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <stdio.h>

long g_start_time;

typedef	struct				s_info
{
	int						ph_count;
	int						time_die;
	int						time_eat;
	int						time_sleep;
	int						must_eat;
	int						flag_death;
	int						end_eat;
	sem_t					*print;
	sem_t					*forks;
}							t_info;

typedef	struct				s_philo
{
	int						philo_id;
	char					*philo_num_char;
	t_info					*info;
	long					time_start_eat;
	int						need_to_eat;
}							t_philo;

typedef	struct				s_all
{
	int						ph_count;
	t_philo					*philo;
	t_info					*info;
	pthread_t				*ph_thread;
}							t_all;

int							main(int argc, char **argv);
int							philo_error(char *str);
void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(char *s, int fd);

int							init_all(t_all *all, int argc, char **argv);
int							init_philo(t_all *all);
int							init_forks(t_all *all);
int							ft_atoi(const char *nptr);
char						*ft_strdup(const char *s);
char						*ft_itoa(int n);
size_t						ft_strlen(const char *s);

long						get_time_in_millisec(void);
long						get_cur_time(void);
void						philo_accurate_usleep(long time_to, t_philo	*philo);

void						eat_even_philo(t_philo *philo);
void						sleep_and_think(t_philo *philo);
int							init_validation(t_all *all);
void						main_check_death(t_all *all, int i);

#endif
