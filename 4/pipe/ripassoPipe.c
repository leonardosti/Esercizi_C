#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

typedef struct
{
    char titolo[50];
    char autore[50];
    float prezzo;
} Libro;

int main(int argc, char *argv[])
{
    int fd[2]; // file descriptor
    int p;
    char risposta;

    if (pipe(fd) != 0)
    {
        printf("Errore nella pipe function\n");
        exit(-1);
    }
    p = fork();
    if (p < 0)
    {
        printf("Errore nella fork function\n");
        exit(-1);
    }
    else if (p == 0) // processo figlio
    {
        Libro buffer;
        close(fd[1]); // chiuso fd in scrittura
        for(int i = 0; i < 2; i++)
        {
            read(fd[0], &buffer, sizeof(buffer));
            printf("Titolo -> %s\n", buffer.titolo);
            printf("Autore -> %s\n", buffer.autore);
            printf("Prezzo -> %f\n", buffer.prezzo);
        }
        close(fd[1]);
    }
    else // processo padre
    {
        Libro libro;
        close(fd[0]); // chiuso fd in lettura
        for (int i = 0; i < 2; i++)
        {
            printf("Inserire il titolo del libro\n");
            scanf("%s", libro.titolo);
            printf("Inserire l'autore del libro\n");
            scanf("%s", libro.autore);
            printf("Inserire il prezzo del libro\n");
            scanf("%f", &libro.prezzo);
            write(fd[1], &libro, sizeof(libro));
        }
        close(fd[1]);
    }
    return 0;
}