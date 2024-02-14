#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define ARRAY_LEN 5
#define BUFFER_LEN 1024

int main(int argc, char *argv[])
{
    int fd[2]; // file descriptor
    int p;

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
        int temp[ARRAY_LEN];
        // printf("Processo figlio, PID: %d\n", getpid());
        close(fd[0]); // chiuso il fd in lettura
        for (int i = 0; i < ARRAY_LEN; i++)
        {
            printf("Inserire il %d° numero:\n", i + 1);
            scanf("%d", &temp[i]);
        }
        if (write(fd[1], temp, sizeof(int) * ARRAY_LEN) == -1)
        {
            printf("Errore nella scrittura della pipe\n");
            exit(-1);
        }
        close(fd[1]);
    }
    else // processo padre
    {
        int temp2[ARRAY_LEN];
        int mol = 0;
        // printf("Processo padre, PID: %d\n", getpid());
        close(fd[1]); // chiuso il fd in scrittura
        if (read(fd[0], temp2, sizeof(int) * ARRAY_LEN) == -1)
        {
            printf("Errore nella lettura della pipe\n");
            exit(-1);
        }
        close(fd[0]);
        printf("Inserire il moltiplicatore\n");
        scanf("%d", &mol);
        for (int i = 0; i < ARRAY_LEN; i++)
        {
            printf("numero %d moltiplicato: %d\n", i + 1, temp2[i] * mol);
        }
    }
    return 0;
}