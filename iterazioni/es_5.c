
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero1, numero2, i;

    do
    {
        do
        {
            printf("Inserisci il primo numero: \n");
            scanf("%d", &numero1);
        } while (numero1 <= 0);
        do
        {
            printf("Inserisci il secondo numero: \n");
            scanf("%d", &numero2);
        } while (numero2 <= 0);
    } while (numero1 >= numero2);

    printf("I numeri compresi tra %d e %d sono:\n", numero1, numero2);
    do
    {
        printf("%d \n", numero1);
        numero1++;
    } while (numero1 <= numero2);

    return 0;
}