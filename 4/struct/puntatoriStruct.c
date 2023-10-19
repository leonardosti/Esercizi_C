#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[20];
    char cognome[20];
    int media;
} student_t;

int main(int argc, char *argv[])
{
    student_t studente;
    student_t *std = (student_t *)&studente; // cast per dichiarare che si sta puntando ad una struct

    strcpy(std->nome, "Leonardo");
    strcpy(std->cognome, "Osti");
    std->media = 8;

    printf("%s\n", std->nome);
    printf("%s\n", std->cognome);
    printf("%d\n", std->media);
    
    return 0;
}