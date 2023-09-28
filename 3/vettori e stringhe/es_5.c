#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv)
{
    int n, maxP = 0, minP = INT_MAX, maxD = 0, minD = INT_MAX;
    int posMaxP, posMinP, posMaxD, posMinD;

    printf("Quanti numeri vuoi inserire\n");
    scanf("%d", &n);
    int numeri[n];
    for (int i = 0; i < n; i++)
    {
        printf("Inserisci il %d° numero\n", i + 1);
        scanf("%d", &numeri[i]);
        if (numeri[i] % 2 == 0)
        {
            if (numeri[i] > maxP)
            {
                maxP = numeri[i];
                posMaxP = i;
            }
            if (numeri[i] < minP)
            {
                minP = numeri[i];
                posMinP = i;
            }
        }
        else
        {
            if (numeri[i] > maxD)
            {
                maxD = numeri[i];
                posMaxD = i;
            }
            if (numeri[i] < minD)
            {
                minD = numeri[i];
                posMinD = i;
            }
        }
    }
    printf("Il massimo dei numeri pari inseriti è %d, e la sua posizione nell'array è %d\n", maxP, posMaxP + 1);
    printf("Il minimo dei numeri pari inseriti è %d, e la sua posizione nell'array è %d\n", minP, posMinP + 1);
    printf("Il massimo dei numeri dispari inseriti è %d, e la sua posizione nell'array è %d\n", maxD, posMaxD + 1);
    printf("Il minimo dei numeri dispari inseriti è %d, e la sua posizione nell'array è %d\n", minD, posMinD + 1);

    return 0;
}