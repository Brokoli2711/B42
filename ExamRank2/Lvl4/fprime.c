#include <stdlib.h>
#include <stdio.h>

int isprime(int prime)
{
    int i;

    i = 2;
    if (prime == 1)
        return (1);
    while (i < prime) {
        if(prime % i++ == 0)
            return (0);
    }
    return (1);
}

int    fprime(int n)
{
    int prime;

    prime = 2;
    while (prime <= n)
    {
        if(isprime(prime) && (n % prime == 0))
        {
            printf("%i", prime);
            if (prime != n)
                printf("*");
            fprime(n/prime);
            break ;
        }
        prime++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);
    fprime(atoi(argv[1]));
    return (0);
}
