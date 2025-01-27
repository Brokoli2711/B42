#include "ft_printf.h"

int	main(void)
{
	printf("printf 1 es:%d\n" ,ft_printf("%s %u %x %x", "hola", -27, 34567, 34567));
	ft_printf("printf 2 es:%d\n" ,ft_printf("%s %u %x %x", "hola", -27, 34567, 34567));

	return (0);
}
