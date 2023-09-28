
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero;

    do
    {
        printf("Inserisci un numero positivo: \n");
        scanf("%d", &numero);
    } while (numero <= 0);
    
    printf("I numeri compresi fra -%d e %d sono:\n", numero, numero);
    for (int i = -numero; i <= numero; i++)
    {
        printf("%d \n", i);
    }

    return 0;
}