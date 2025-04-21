
#include <stdio.h>
int	is_valid(char s)
{
	if((s >= 'A' && s <= 'Z') || s >= 'a' && s <= 'z')
		return (1);
	return (0);
}

char	conversion(char s)
{
	if(s <= 'm' && s >= 'a')
		return ('a' + ('z' - s));
	else if(s >= 'n' && s <= 'z')
		return ('z' - (s - 'a'));
	else if(s <= 'M' && s >= 'A')
		return ('A' + ('Z' - s));
	else
		return ('Z' - (s - 'A'));
}

static void	alpha_mirror(char *s)
{
	while(*s)
	{
		if(is_valid(*s))
			*s = conversion(*s);
		s++;
	}
}

int	main(int argc, char **argv)
{
	char	*s1 = argv[1];

	if (argc != 2)
		return (0);
	printf("%s", s1);
	alpha_mirror(s1);
	printf("%s", s1);
	return (0);
}
