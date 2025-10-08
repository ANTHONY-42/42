#include "philo.h"

void    fork_unlock(t_philo *philo)
{
        pthread_mutex_unlock(philo->fork_r);
        pthread_mutex_unlock(philo->fork_l);
}

void	last_meal_lock(t_philo *philo)
{
        pthread_mutex_lock(&philo->meal_lock);
        philo->last_meal = get_time_ms();
        pthread_mutex_unlock(&philo->meal_lock);
}
