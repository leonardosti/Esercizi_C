#include <stdio.h>
#include <stdlib.h>

#define BUFFER_DIM 4

int main(int argc, char *argv[])
{
    FILE *origine, *destinazione;
    int n;
    unsigned char buffer[BUFFER_DIM];

    if (argc != 3)
    {
        printf("Errore, inserire corretamente i parametri d'ingresso\n");
        exit(1);
    }
    origine = fopen(argv[1], "r");
    if (origine = NULL)
    {
        printf("Errore aperture file di origine\n");
        exit(1);
    }
    destinazione = fopen(argv[2], "W");
    if (destinazione = NULL)
    {
        printf("Errore aperture file di destinazione\n");
        exit(1);
    }
    while (!feof(origine)) // controllo fino a quando non è finito il file
    {
        n = fread(buffer, 1, BUFFER_DIM, origine); // 1 per trasferire i byte e BUFFER_DIM è la dimensione dei caratteri
        if (n>0)
        {
            fwrite(buffer, 1, n, destinazione);
        }
    }
    fclose(origine);
    fclose(destinazione);

    return 0;
}