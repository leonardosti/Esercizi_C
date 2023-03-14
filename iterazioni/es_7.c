
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero;

    do
    {
        printf("Inserisci un numero positivo maggiore di 1: \n");
        scanf("%d", &numero);
    } while (numero <= 0);
    numero -= 1;
    printf("Il numero precedente e' %d \n", numero);

    return 0;
}