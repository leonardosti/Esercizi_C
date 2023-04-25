#include <stdio.h>
#include <stdlib.h>

int ricerca(int n, int numero, char *argv[])
{
    int posizione = -1;
    for (int i = 0; i < n; i++)
    {
        if (numero == atoi(argv[i]))
        {
            posizione = i;
            break;
        }
    }
    return posizione;
}
int main(int argc, char *argv[])
{
    int numero;
    printf("Inserisci il numero da ricercare\n");
    scanf("%d", &numero);
    int trovato = ricerca(argc, numero, argv);
    if (trovato != -1)
    {
        printf("Il numero è presente nella posizione n. %d\n", trovato);
    }
    else
    {
        printf("Il numero non è presente nell'array argv\n");
    }

    return 0;
}