#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t fork_left;
pthread_mutex_t fork_right;
pthread_mutex_t print_mutex;

void    print(char *msg)
{
	pthread_mutex_lock(&print_mutex);
	printf("%s\n", msg);
	pthread_mutex_unlock(&print_mutex);
}

void    *philosopher_routine(void *arg)
{
	int i;

	i = 0;
	while (i < 3)
	{
		print("Le philosophe réfléchit");
		usleep(100000); // 0.1s

		pthread_mutex_lock(&fork_left);
		print("Le philosophe a pris la fourchette gauche");
		pthread_mutex_lock(&fork_right);
		print("Le philosophe a pris la fourchette droite");

		print("Le philosophe mange");
		usleep(100000);

		pthread_mutex_unlock(&fork_right);
		pthread_mutex_unlock(&fork_left);

		print("Le philosophe dort");
		usleep(100000);

		i++;
	}
	return (NULL);
}

int main(void)
{
	pthread_t philosopher;

	pthread_mutex_init(&fork_left, NULL);
	pthread_mutex_init(&fork_right, NULL);
	pthread_mutex_init(&print_mutex, NULL);

	pthread_create(&philosopher, NULL, philosopher_routine, NULL);
	pthread_join(philosopher, NULL);

	pthread_mutex_destroy(&fork_left);
	pthread_mutex_destroy(&fork_right);
	pthread_mutex_destroy(&print_mutex);

	return (0);
}
