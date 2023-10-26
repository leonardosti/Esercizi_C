#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *nomi; // nomi è puntatore ad oggetti di tipo file
    nomi = fopen("nomi.txt", "w"); // apro il file nomi.txt in scrittura (il file non esiste, quindi lo crea, in caso contrario lo apre)
    if (nomi == NULL) // controlla se il file è stato creato
    {
        printf("File non aperto\n");
        exit(1);
    }
    /*else
    {
        printf("File aperto\n");
    }*/
    char vettNomi[20];
    char c;
    do
    {
        c = fgetc(nomi); // per leggere solo caratteri singoli
        putchar(c);
    } while (c != EOF); // EOF = end of file 
    
    for (size_t i = 0; i < 4; i++)
    {
        printf("Inserisci il nome %ld\n", i + 1);
        scanf("%s", vettNomi);
        fputs(vettNomi, nomi); // inserisce il contenuto dell'array nel file nomi
        fputc('\n', nomi); // aggiunge il carattere \n nel file nomi per andare a capo
    }
    fclose(nomi); // chiusura file nomi

    return 0;
}