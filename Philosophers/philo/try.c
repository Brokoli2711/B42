#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <threads.h>

void	*hola(char *str)
{
	if(!str)
		return (NULL);
	printf("%s\n", str);
	return (NULL);
}

int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;
	char	*str;

	str = "hola";
	while(*str)
	{
		pthread_create(&thread1, NULL, hola(str), NULL);
		pthread_create(&thread2, NULL, hola(str + 1), NULL);
		sleep(10);
	}
	return (0);
}
