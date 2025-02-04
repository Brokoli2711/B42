#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int	main(int argc, char *argv[])
{
	char	*line;
	int	fd;
	
	line = "13";
	if (argc = 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (-1);
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s", line);
			free(line);
		}
		close(fd);
	}
	return (0);
}
