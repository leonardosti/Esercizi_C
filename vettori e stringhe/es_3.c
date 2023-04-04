
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv)
{

    int n, supp;
    int numeri[100];

    do
    {
        printf("Quanti numeri vuoi inserire? \n");
        scanf("%d", &n);
    } while (n <= 0);

    for (int i = 0; i < n; i++)
    {
        printf("Inserisci il %d° numero \n", i + 1);
        scanf("%d", &numeri[i]);
    }

    for (int j = 0; j < n - 1; j++)
    {
        if (j % 2 == 0)
        {

            supp = numeri[j];
            numeri[j] = numeri[j++];
            numeri[j++] = supp;
        }
    }

    for (int k = 0; k < n; k++)
    {
        printf("%d ", numeri[k]);
    }

    return 0;
}