#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int is_negative(int nbr)
{
    if(nbr < 0)
        return (1);
    return (0);
}

int check_length(int nbr)
{
    int len;
    long    n;

    n = nbr;

    len = 0;
    if (n == 0)
        return (1);
    if (is_negative(n))
    {
        len++;
        n *= -1;
    }
    while(n > 0)
    {
        n /= 10;
        len++;
    }
    return (len);
}

char    *ft_itoa(int nbr)
{
    char    *str_nbr;
    int     i;
    long    n;

    n = nbr;
    i = check_length(nbr);
    str_nbr = malloc(sizeof(char) * i + 1);
    if (!str_nbr)
        return (NULL);
    str_nbr[i] = '\0';
    if (is_negative(nbr))
    {
        str_nbr[0] = '-';
        n *= -1;
    }
    if (n == 0)
        str_nbr[0] = '0';
    while (n > 0)
    {
        str_nbr[i - 1] = (n % 10) + 48;
        n /= 10;
        i--;
    }
    return (str_nbr);
}

int main(void)
{
    printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(27));
    printf("%s\n", ft_itoa(-5432));
    printf("%s\n", ft_itoa(-1));
    printf("%s\n", ft_itoa(INT_MIN));
    return (0); 
}
