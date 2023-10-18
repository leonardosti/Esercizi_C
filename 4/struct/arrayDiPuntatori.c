#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[20];
    char cognome[20];
    int media;
} student_t;
void stampa(student_t *studenti, const int len)
{
    // stampa array
    for (int i = 0; i < len; i++)
    {
        printf("Nome : %s \n", (studenti->nome + i));
        printf("Cognome : %s \n", (studenti->cognome + i));
        printf("Media : %d \n", (studenti->media + i));
    }
}
void Inserimento(student_t *studenti, int i)
{
    printf("Inserire nome dello studente %d \n", i + 1);
    scanf("%s", studenti[i].nome);
    printf("Inserire cognome dello studente %d\n", i + 1);
    scanf("%s", studenti[i].cognome);
    printf("Inserire media dello studente %d \n", i + 1);
    scanf("%d", &studenti[i].media);
}
int main(int argc, char *argv[])
{
    const int lunghezza = 3;
    student_t *studenti[lunghezza];
    
    for (int i = 0; i < lunghezza; i++)
    {
        studenti[i] = (student_t*)malloc(sizeof(student_t));
        Inserimento(studenti[0], i);
    }
    stampa(studenti[0], lunghezza);
    //  libero la memoria
    for (int i = 0; i < lunghezza; i++)
    {
        free(studenti[i]);
    }

    return 0;
}