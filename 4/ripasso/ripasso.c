#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define array_length 10000
#define BUFFER_DIM 4

int figlioA, figlioB;
unsigned char buffer[BUFFER_DIM];
int main(int argc, char *argv[])
{
    figlioA = fork();
    if (figlioA == 0)
    {
        // Figlio A
    }
    else
    {
        figlioB = fork();
        if (figlioB == 0)
        {
            // Figlio B
        }
        else
        {
            // Padre
            int arrayRandom[array_length];
            FILE *numeri;
            for (int i = 0; i < array_length; i++)
            {
                arrayRandom[i] = rand() % 500 + 1; // Generatore casuale di numeri da 1 a 500
                numeri = fopen("numeriRandom.txt", "w");
                if (numeri == NULL)
                {
                    printf("Errore nell'apertura del file\n");
                    exit(1);
                }
                fwrite(buffer, 1, i, numeri);
                fputc(':', numeri);
                fwrite(buffer, 1, arrayRandom[i], numeri);
                fputc('\n', numeri);
            }
            fclose(numeri);
        }
    }

    return 0;
}