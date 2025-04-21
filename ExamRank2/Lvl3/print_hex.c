#include <stdio.h>

void	print_hex(unsigned char n)
{
	char	*hex_digits = "0123456789ABCDEF";

	printf("%c%c", hex_digits[n / 16], hex_digits[n % 16]);
}

int	main(void)
{
	print_hex((unsigned char)27);
	return (0);
}
