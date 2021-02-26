#ifndef PHILOSOPHERS_HEADER_H
# define PHILOSOPHERS_HEADER_H

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

#include <stdio.h>

long start_time;

typedef	struct				s_info
{
	int						ph_count;
	int						time_die;
	int						time_eat;
	int						time_sleep;
	int						must_eat;
	int                     flag_death;
	pthread_mutex_t			*lock_for_even_odd;
	int						end_eat;
}							t_info;

typedef	struct				s_philo
{
	int						philo_id;
	char					*philo_num_char;
	int						max_eat;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			*print;
	t_info					*info;
	long                    time_start_eat;
	int						need_to_eat;
//	long					start_for_philo;
}							t_philo;

typedef	struct				s_all
{
	int						ph_count;
	t_philo					*philo;
	t_info					*info;
	pthread_t				*ph_thread;
	pthread_mutex_t			**forks;
}							t_all;

int		philo_error(char *str);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		init_all(t_all *all, int argc, char **argv);
int		init_philo(t_all *all);
int		init_forks(t_all *all);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

long	get_time_in_millisec();
long	get_cur_time();
void	philo_accurate_usleep(long time_to, t_philo	*philo);
void	philo_print(char *str, t_philo *philo);

void    eat_odd_philo(t_philo	*philo);
void    eat_even_philo(t_philo	*philo);
void    sleep_and_think(t_philo	*philo);

#endif