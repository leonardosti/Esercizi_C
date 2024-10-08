#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 30
#define MAX_LIBRERIA 40

typedef struct
{
    char titolo[MAX_CHAR];
    char autore[MAX_CHAR];
    int annoPupplicazione;
    float prezzo;
} Libro;

typedef struct
{
    Libro libri[];
    char nome[MAX_CHAR];
}

int menu
{
    int scelta = 0;
    char *string[] = {"Esporta CSV", "Visualizza Libreria", "Ricerca titolo", "Ricerca Categoria", "esci"};
    printf("Menu:\n");
    for (int i = 0; i < MENU_LENGHT; i++)
    {
        printf("%d - %s\n", i, string[i]);
    }
    printf("Inserire la scelta: ");
    scanf("%d", &scelta);
    return scelta;
}
void LeggiCSV()
{
    FILE *file = fopen("libreria_libri.csv", "r");
    if (file == NULL)
    {
        printf("Errore con la lettura del file CSV\n");
        exit(1);
    }
}
void Visualizza()
{
}
void RicercaTitolo()
{
}
void RicercaCategoria()
{
}
int main()
{
    int scelta;

    do
    {
        scelta = menu();
        switch (scelta)
        {
        case 0:
            // Leggere il csv
            break;
        case 1:
            // visualizza l'intera libreria
            break;
        case 2:
            // ricerca titolo libro
            break;
        case 3:
            // ricerca categoria libro
            break;
        case 4:
            printf("Esci\n");
            break;
        default:
            printf("Scelta non valida\n");
        }
    } while (scelta != 4);

    return 0;
}