/*Scrivere un programma in C che dopo aver dichiarato una struttura denominata Auto con i seguenti
campi: ModelloAuto, marca, cilindrata, prezzo, anno_immatricolazione, determinare:
1) Il prezzo + alto e quello + basso visualizzando anche il modello dell&#39;auto;
2) Ordinare la lista delle auto in base all&#39;anno d&#39;immatricolazione;
3) Visualizzare il nome delle auto a partire da un prezzo scelto dall&#39;utente.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LENGHT 5

typedef struct
{
    char ModelloAuto[30];
    char marca[30];
    float cilindrata;
    float prezzo;
    int anno_immatricolazione;
} Auto;

int main()
{
    Auto arrayAuto[ARRAY_LENGHT] = {
        {"Golf", "Volkswagen", 1.6, 18000.00, 2018},
        {"Civic", "Honda", 2.0, 22500.00, 2020},
        {"500", "Fiat", 1.2, 13000.00, 2017},
        {"A4", "Audi", 2.0, 25000.00, 2019},
        {"Corsa", "Opel", 1.4, 15500.00, 2021}};

    float prezzoAlto = arrayAuto[0].prezzo, prezzoBasso = arrayAuto[0].prezzo;
    int posAlto, posBasso;

    // visualizzazione prezzi
    for (int i = 0; i < ARRAY_LENGHT; i++)
    {
        if (arrayAuto[i].prezzo > prezzoAlto)
        {
            prezzoAlto = arrayAuto[i].prezzo;
            posAlto = i;
        }
        if (arrayAuto[i].prezzo < prezzoBasso)
        {
            prezzoBasso = arrayAuto[i].prezzo;
            posBasso = i;
        }
    }
    printf("Il prezzo più alto è %.2f\n", arrayAuto[posAlto].prezzo);
    printf("Il prezzo più basso è %.2f\n", arrayAuto[posBasso].prezzo);

    // ordine anno
    for (int i = 0; i < ARRAY_LENGHT - 1; i++)
    {
        for (int j = 0; j < ARRAY_LENGHT - i - 1; j++)
        {
            if (arrayAuto[j].anno_immatricolazione > arrayAuto[j + 1].anno_immatricolazione)
            {
                Auto temp = arrayAuto[j];
                arrayAuto[j] = arrayAuto[j + 1];
                arrayAuto[j + 1] = temp;
            }
        }
    }
    printf("L'array ordinato in base all'anno di immatricolazione:\n");
    for (int i = 0; i < ARRAY_LENGHT; i++)
    {
        printf("Modello: %s, Marca: %s, Anno: %d, Prezzo: %.2f\n",
               arrayAuto[i].ModelloAuto, arrayAuto[i].marca,
               arrayAuto[i].anno_immatricolazione, arrayAuto[i].prezzo);
    }
    

    return 0;
}