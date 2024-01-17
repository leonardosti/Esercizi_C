#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define array_length 10000

int figlioA, figlioB;
int main(int argc, char *argv[])
{
    int arrayRandom[array_length];
    FILE *numeri;
    numeri = fopen("numeriRandom.txt", "w");
    if (numeri == NULL)
    {
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    for (int i = 0; i < array_length; i++)
    {
        arrayRandom[i] = rand() % 500 + 1; // Generatore casuale di numeri da 1 a 500
        fprintf(numeri, "%d %s %d\n", i, ":", arrayRandom[i]);
    }
    fclose(numeri); // chiuso lo stream
    if (argc != 2)
    {
        printf("Argomenti insufficenti\n");
        exit(1);
    }
    int n = atoi(argv[1]); // converto in intero il numero inserito dall'utente
    figlioA = fork();
    if (figlioA == 0)
    {
        // Figlio A
        printf("Ricerca processo figlio A\n");
        for (int i = 2000; i < 6000; i++)
        {
            if (n == arrayRandom[i])
            {
                printf("PID: %d, %d : %d\n", getpid(), i, arrayRandom[i]);
            }
        }
    }
    else
    {
        figlioB = fork();
        if (figlioB == 0)
        {
            // Figlio B
            printf("Ricerca processo figlio B\n");
            for (int i = 6000; i < 10000; i++)
            {
                if (n == arrayRandom[i])
                {
                    printf("PID: %d, %d : %d\n", getpid(), i, arrayRandom[i]);
                }
            }
        }
        else
        {
            // Padre
            printf("Ricerca processo padre\n");
            for (int i = 0; i < 2000; i++)
            {
                if (n == arrayRandom[i])
                {
                    printf("PID: %d, %d : %d\n", getpid(), i, arrayRandom[i]);
                }
            }
        }
    }

    return 0;
}