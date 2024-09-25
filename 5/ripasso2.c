/*Scrivere un programma in C che dopo aver inserito una stringa a piacere determini e o verifichi:
1) Che contenga solo lettere;
2) Il conteggio di una lettera (se presente) scelta dall’utente;
3) Crei 2 ulteriori stringhe che contengano 1 le lettere di posizione pari; la 2° le lettere di posizione
dispari;
4) Verifichi se contiene doppie.
Inserita una 2° stringa determinare:
1) Quale delle 2 è più lunga e più corta;
2) Quali sono le lettere contenute in ambedue le stringhe;
3) Quale delle 2 stringhe contiene più vocali;
4) Quale delle 2 stringhe contiene più consonanti;*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

int controllo(char stringa[])
{
    int temp = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] >= 48 && stringa[i] <= 57)
        {
            printf("E' presente un numero\nLa stringa deve contenere solo lettere\n");
            temp = 1;
            break;
        }
    }
    return temp;
}

int conteggio(char stringa[], char carattere)
{
    int temp = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == carattere)
        {
            temp++;
        }
    }
    return temp;
}

void posizione(char stringa[])
{
    /* code */
}

int main()
{
    char stringa[DIM];
    char carattere;

    do
    {
        printf("Inserisci la prima stringa:\n");
        scanf("%s", stringa);
    } while (controllo(stringa) == 1);

    printf("Insersci il carattere da contare:\n");
    scanf(" %c", &carattere);
    int cnt = conteggio(stringa, carattere) if (cnt == 0)
    {
        printf("Lettera non presente\n");
    }
    else
    {
        printf("Lettere presente: %d volte\n", cnt);
    }

    return 0;
}