#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 30
#define MAX_LIBRERIA 40
#define MAX_LEN 100
#define MENU_LENGHT 5

typedef struct
{
    char titolo[MAX_CHAR];
    char autore[MAX_CHAR];
    int annoPubblicazione;
    float prezzo;
    char categoria[MAX_CHAR];
} Libro;

typedef struct
{
    Libro libri[MAX_LIBRERIA];
    int numeroLibri;
} Libreria;

int menu()
{
    int scelta = 0;
    char *string[] = {"Esporta CSV", "Visualizza Libreria", "Ricerca titolo", "Ricerca Categoria", "Esci"};
    printf("Menu:\n");
    for (int i = 0; i < MENU_LENGHT; i++)
    {
        printf("%d - %s\n", i, string[i]);
    }
    printf("Inserire la scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

void LeggiCSV(Libreria *libreria)
{
    FILE *file = fopen("libreria_libri.csv", "r"); // apro il file in lettura
    if (!file)
    {
        printf("Errore nell'apertura del file.\n");
        return;
    }

    char buffer[MAX_LEN];
    libreria->numeroLibri = 0;

    // Leggo i dati con fgets
    while (fgets(buffer, MAX_LEN, file) && libreria->numeroLibri < MAX_LIBRERIA)
    {
        char *token = strtok(buffer, ",");
        strcpy(libreria->libri[libreria->numeroLibri].titolo, token);

        token = strtok(NULL, ",");
        strcpy(libreria->libri[libreria->numeroLibri].autore, token);

        token = strtok(NULL, ",");
        libreria->libri[libreria->numeroLibri].annoPubblicazione = atoi(token);

        token = strtok(NULL, ",");
        libreria->libri[libreria->numeroLibri].prezzo = atof(token);

        token = strtok(NULL, ",");
        strcpy(libreria->libri[libreria->numeroLibri].categoria, token);

        libreria->numeroLibri++; // Incremento il numero dei libri
    }

    fclose(file); // chiudo il file
}

void Visualizza(Libreria *libreria)
{
    printf("Libreria:\n");
    for (int i = 0; i < libreria->numeroLibri; i++)
    {
        printf("Titolo: %s, Autore: %s, Anno: %d, Prezzo: %.2f, Categoria: %s\n",
               libreria->libri[i].titolo,
               libreria->libri[i].autore,
               libreria->libri[i].annoPubblicazione,
               libreria->libri[i].prezzo,
               libreria->libri[i].categoria);
    }
}

void RicercaTitolo(Libreria *libreria, const char *titolo)
{
    int trovato = 0;
    for (int i = 0; i < libreria->numeroLibri; i++)
    {
        if (strcmp(libreria->libri[i].titolo, titolo) == 0)
        {
            printf("Libro trovato: %s, Autore: %s, Anno: %d, Prezzo: %.2f, Categoria: %s\n",
                   libreria->libri[i].titolo,
                   libreria->libri[i].autore,
                   libreria->libri[i].annoPubblicazione,
                   libreria->libri[i].prezzo,
                   libreria->libri[i].categoria);
            return;
        }
    }
    printf("Libro non trovato\n");
}

void RicercaCategoria(Libreria *libreria, const char *categoria)
{
    int trovato = 0;
    for (int i = 0; i < libreria->numeroLibri; i++)
    {
        if (strcmp(libreria->libri[i].categoria, categoria) == 0)
        {
            printf("Libro: %s, Autore: %s, Anno: %d, Prezzo: %.2f\n",
                   libreria->libri[i].titolo,
                   libreria->libri[i].autore,
                   libreria->libri[i].annoPubblicazione,
                   libreria->libri[i].prezzo);
            trovato = 1;
        }
    }
    if (!trovato)
    {
        printf("Nessun libro trovato per la categoria: %s\n", categoria);
    }
}

int main()
{
    Libreria libreria;
    libreria.numeroLibri = 0;

    int scelta;
    char titolo[MAX_CHAR];
    char categoria[MAX_CHAR];

    do
    {
        scelta = menu();
        switch (scelta)
        {
        case 0:
            // Leggere il csv
            LeggiCSV(&libreria);
            break;
        case 1:
            // visualizza libreria
            Visualizza(&libreria);
            break;
        case 2:
            // ricerca titolo libro
            printf("Inserisci il titolo da cercare:\n");
            scanf(" %[^\n]", titolo);
            RicercaTitolo(&libreria, titolo);
            break;
        case 3:
            // ricerca categoria libro
            printf("Inserisci la categoria da cercare:\n");
            scanf(" %[^\n]", categoria); // leggo finchè l'utente non preme invio
            RicercaCategoria(&libreria, categoria);
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
