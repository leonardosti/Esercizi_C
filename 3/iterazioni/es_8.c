
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero;

    do
    {
        printf("Inserisci un numero positivo: \n");
        scanf("%d", &numero);
    } while (numero <= 0);

    printf("I numeri precedenti di %d in ordine decrescente sono:\n", numero);
    for (int i = numero - 1; i > 0; i--)
    {
        printf("%d \n", i);
    }

    return 0;
}