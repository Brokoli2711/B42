#include "ft_printf.h"

int	main()
{
	int	x = -4675;
	int	my_print = ft_printf("%u\n", x);
	int	sprint = printf("%u", x);
	printf("%u", my_print);
	printf("%u", sprint);
	return (0);
}
