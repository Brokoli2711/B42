#include "ft_printf.h"

int	main()
{
	int hola = ft_printf("    %", 42, -12);
	int	hola2 = printf("    %", 42, -12);

	ft_printf("%i\n", hola2);
	printf("%i", hola);
	return (0);
}
