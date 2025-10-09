#ifndef	PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <sys/time.h>

typedef	struct	s_config
{
	int	NB_PHILOS;
	int	TIME_TO_DIE;
	int	TIME_TO_EAT;
	int	TIME_TO_SLEEP;
	int	MUST_EAT;
}	t_config;

typedef	struct	s_philo
{
	int	id;
	int	nb_meal;
	long long	last_meal;
	pthread_t	thread_id;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	meal_lock;
	struct	s_data	*data;
}	t_philo;

typedef	struct	s_data
{
	long long	start_time;
	int		all_finished;
	int		stop;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_lock;
	t_config	config;
	t_philo		*philo;
}	t_data;

int     stopit_now(t_data *data);
void	pars_arg(int ac, char **av, t_data *data);
long	ft_atoi(char *str);
void	error(char *str, int i);
long long	get_time_ms(void);
void		print_msg(t_data *data, int id, const char *msg);
void	*philosopher_routine(void *arg);
void	*monitoring(void *arg);
void	fork_unlock(t_philo *philo);
int	init_data(t_data *data);
void    init_philo(t_data *data);
void    start_thread(t_data *data);
void    lock_last_meal(t_philo *philo);
void    destroy_all(t_data *data);
void    last_meal_lock(t_philo *philo);
void	precise_sleep(int sleep);

#endif
