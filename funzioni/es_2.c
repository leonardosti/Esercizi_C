#include <stdio.h>
#include <stdlib.h>

int tot(int n, char *argv[])
{
    int somma = 0;
    for (int i = 1; i < n; i++)
    {
        somma += atoi(argv[i]);
    }
    return somma;
}
int main(int argc, char *argv[])
{
    int n = argc;
    double media;
    int somma = tot(n, argv);
    media = somma / (n - 1);
    printf("La media dei numeri e': %f\n", media);

    return 0;
}