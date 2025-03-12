#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int	check_len(char *argv[])
{
	int	num;

	num = 0;
	while(argv[num])
		num++;
	return (num - 1);
}

int	main(int argc, char *argv[])
{
	char	*line;
	int	*fd;
	int	num;
	
	num = 1;
	fd = (int*)malloc(check_len(argv));
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[2], O_RDONLY);
	fd[2] = open(argv[3], O_RDONLY);
	if (argc >= 2)
	{
		while ((line = get_next_line(fd[num - 1])) != NULL)
		{
			printf("%s", line);
			free(line);
			num++;
			if(num == 4)
				num = 1;	
		}
		close (fd[0]);
		close (fd[1]);
		close (fd[2]);
	}
	return (0);
}
