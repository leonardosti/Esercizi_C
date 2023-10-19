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
    student_t *std;
    std = malloc(sizeof(student_t)); // memory allocation; riseva uno spazio di memoria in maniera dinamica

    strcpy(std->nome, "Leonardo");
    strcpy(std->cognome, "Osti");
    std->media = 8;

    printf("%s\n", std->nome);
    printf("%s\n", std->cognome);
    printf("%d\n", std->media);
    
    free(std); // libera la memoria allocata in maniera dinamica

    return 0;
}