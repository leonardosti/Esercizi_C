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
#include <unistd.h>

int menu()
{
    int scelta = 0;
    char* string[] = {"visualizza", "invertito", "somma/media", "pari", "dispari", "ricerca", "elimina", "scambia", "ordina", "esci"};
    printf("Menu:\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%d - %s\n", i, string[i]);
    }
    printf("Inserire la scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

void visualizza(int numeri[]){
    for (int i = 0; i < 5; i++)
    {
        printf("%d, ", numeri[i]);
    }
    
}

int main(int argc, char *argv[])
{
    int numeri[] = {1, 2, 3, 4, 5};

    int scelta = menu();

    switch (scelta)
    {
    case 0:
    visualizza(numeri);
        break;
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    case 7:
        /* code */
        break;
    case 8:
        /* code */
        break;
    case 9:
        /* code */
        break;
    }

    return 0;
}