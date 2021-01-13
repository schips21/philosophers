#ifndef PHILOSOPHERS_HEADER_H
# define PHILOSOPHERS_HEADER_H

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#include <stdio.h>


typedef	struct				s_info
{
	int						ph_count;
	int						time_die;
	int						time_eat;
	int						time_sleep;
	int						must_eat;
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
}							t_philo;

typedef	struct				s_all
{
	int						ph_count;
	t_philo					*philo;
	t_info					*info;
	pthread_t				*ph_thread;
	pthread_mutex_t			**forks;
}							t_all;

int		main(int argc, char **argv);
int		philo_error(char *str);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		init_all(t_all *all, int argc, char **argv);
int		init_philo(t_all *all);
int		init_forks(t_all *all);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);


#endif