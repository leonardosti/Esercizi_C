#include <stdio.h>

void somma(int n1, int n2)
{
    int somma;
    somma = n1 + n2;
    printf("La somma dei numeri e': %d\n", somma);
}
int main(int argc, char *argv[])
{
    int n1, n2;
    printf("Inserisci il primo numero\n");
    scanf("%d", &n1);
    printf("Inserisci il secondo numero\n");
    scanf("%d", &n2);
    somma(n1, n2);
    
    return 0;
}