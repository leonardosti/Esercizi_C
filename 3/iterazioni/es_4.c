
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero;

    do
    {
        printf("Inserisci un numero positivo: \n");
        scanf("%d", &numero);
    } while (numero <= 0);

    printf("I numeri pari e minori di %d sono:\n", numero);
    for (int i = 0; i < numero; i += 2)
    {
        printf("%d \n", i);
    }

    return 0;
}