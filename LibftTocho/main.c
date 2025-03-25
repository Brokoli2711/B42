#include "includes/libft.h"

int	main(int argc, char *argv[])
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	ft_printf(get_next_line(fd));
	close(fd);
	return (0);
}
