/*Scrivere un programma in C che effettui, attraverso un menù, le seguenti operazione sugli array:
1) Visualizzi a video gli elementi dell’array inseriti o generati casualmente;
2) Visualizzi a video l’array invertito cioè sostituendo il primo elemento con l&#39;ultimo , il secondo con il
penultimo e cosi via;
3) Visualizzi a video la somma e media degli elementi del vettore;
4) Visualizzi a video tutti i numeri pari;
5) Visualizzi a video tutti i numeri dispari;
6) Ricerchi un numero (letto in input) nell’array;
7) Elimini un elemento (letto in input) dell’array (se esistente);
8) Alterni (o scambi ) a due a due le posizioni del vettore: esempio
vettore: 1,2,3,4 vettore alternato: 2,1,4,3 (attenzione se lungo dispari);
9) Ordini il vettore (ordinamento a scelta).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENU_LENGHT 9

int menu()
{
    int scelta = 0;
    char *string[] = {"visualizza", "invertito", "somma/media", "pari", "dispari", "ricerca", "elimina", "scambia", "ordina", "esci"};
    printf("Menu:\n");
    for (int i = 0; i < MENU_LENGHT; i++)
    {
        printf("%d - %s\n", i, string[i]);
    }
    printf("Inserire la scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

void visualizza(int numeri[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("%d, ", numeri[i]);
    }
    printf("\n");
}

void revers(int numeri[], int dim)
{
    for (int i = dim - 1; i <= 0; i--)
    {
        printf("%d, ", numeri[i]);
    }
}

void somma(int numeri[], int dim)
{
    int somma = 0;
    float media;

    for (int i = 0; i < dim; i++)
    {
        somma += numeri[i];
    }
    media = (float)somma / dim;

    printf("somma: %d\nmedia: %.2f\n", somma, media);
}

void pari(int numeri[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        if (numeri[i] % 2 == 0)
        {
            printf("%d, ", numeri[i]);
        }
    }
    printf("\n");
}

void dispari(int numeri[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        if (numeri[i] % 2 != 0)
        {
            printf("%d, ", numeri[i]);
        }
    }
    printf("\n");
}

void cerca(int numeri[], int dim)
{
    int numero, trovato = 0;

    printf("Numero da ricercare: ");
    scanf("%d", &numero);

    for (int i = 0; i < dim; i++)
    {
        if (numero == numeri[i])
        {
            trovato = 1;
            break;
        }
    }

    if (trovato)
    {
        printf("Il numero è presente nell'array\n");
    }
    else
    {
        printf("Il numero non è presente nell'array\n");
    }
}

void elimina(int numeri[], int *dim)
{
    int numero, trovato = -1;

    printf("Numero da eliminare: ");
    scanf("%d", &numero);

    for (int i = 0; i < *dim; i++)
    {
        if (numeri[i] == numero)
        {
            trovato = i;
            break;
        }
    }

    if (trovato != -1)
    {
        for (int i = trovato; i < *dim - 1; i++)
        {
            numeri[i] = numeri[i + 1];
        }
        (*dim)--;
        printf("Numero eliminato. Nuovo array:\n");
        visualizza(numeri, *dim);
    }
    else
    {
        printf("Numero non trovato\n");
    }
}

void scambia(int numeri[], int dim)
{
    for (int i = 0; i < dim - 1; i += 2)
    {
        int temp = numeri[i];
        numeri[i] = numeri[i + 1];
        numeri[i + 1] = temp;
    }
    visualizza(numeri, dim);
}

void ordina(int numeri[], int dim)
{
    int temp;
    for (int i = 0; i < dim - 1; i++)
    {
        for (int j = 0; j < dim - i - 1; j++)
        {
            if (numeri[j] > numeri[j + 1])
            {
                temp = numeri[j];
                numeri[j] = numeri[j + 1];
                numeri[j + 1] = temp;
            }
        }
    }
    visualizza(numeri, dim);
}

int main()
{
    int numeri[] = {1, 2, 3, 4, 5};
    int dim = 5;

    int scelta;

    do
    {
        scelta = menu();
        switch (scelta)
        {
        case 0:
            visualizza(numeri, dim);
            break;
        case 1:
            revers(numeri, dim);
            break;
        case 2:
            somma(numeri, dim);
            break;
        case 3:
            pari(numeri, dim);
            break;
        case 4:
            dispari(numeri, dim);
            break;
        case 5:
            cerca(numeri, dim);
            break;
        case 6:
            elimina(numeri, &dim);
            break;
        case 7:
            scambia(numeri, dim);
            break;
        case 8:
            ordina(numeri, dim);
            break;
        case 9:
            printf("Uscita\n");
            break;
        default:
            printf("Scelta non valida\n");
        }
    } while (scelta != 9);

    return 0;
}
