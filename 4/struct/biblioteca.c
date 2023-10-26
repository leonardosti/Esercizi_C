#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char autore[20];
    double prezzo;
    char titolo[20];
} biblioteca;
void inserimento(biblioteca *libro, int i)
{
    printf("Inserire autore del libro %d \n", i + 1);
    scanf("%s", libro->autore);
    printf("Inserire titolo del libro %d\n", i + 1);
    scanf("%s", libro->titolo); 
    printf("Inserire prezzo del libro %d \n", i + 1);
    scanf("%lf", &libro->prezzo);
}
void stampa(biblioteca *libri, int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
    {
        printf("Libro %d:\n", i + 1);
        printf("Autore: %s\n", libri[i].autore);
        printf("Titolo: %s\n", libri[i].titolo);
        printf("Prezzo: %lf\n", libri[i].prezzo);
    }
}
void sconto(biblioteca *libri, int lunghezza, int scontoPercentuale)
{
    for (int i = 0; i < lunghezza; i++)
    {
        libri[i].prezzo = libri[i].prezzo - (libri[i].prezzo * scontoPercentuale / 100);
    }
}
int main(int argc, char *argv[])
{

    const int lunghezza = 1;
    biblioteca libri[lunghezza];
    int scontoPercentuale;
    for (int i = 0; i < lunghezza; i++)
    {
        inserimento(&libri[i], i);
    }
    printf("===================================\n");
    stampa(libri, lunghezza);
    printf("Inserisci lo sconto in percentuale\n");
    scanf("%d", &scontoPercentuale);

    sconto(libri, lunghezza, scontoPercentuale);

    printf("===================================\n");
    stampa(libri, lunghezza);

    return 0;
}