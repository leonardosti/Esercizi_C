#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int p, status;
int main(int argc, char *argv[])
{
    p = fork();
    if (p == 0) // processo figlio
    {
        printf("processo figlio: %d\n", p);
        printf("PID processo figlio: %d\n", getpid());
        printf("PID processo padre all'interno del processo figlio: %d\n", getppid());
        exit(32);
    }
    else // processo padre
    {
        printf("processo padre: %d\n", p);
        printf("PID processo padre: %d\n", getpid());
        printf("Attendo che il processo figlio %d sia terminato\n", wait(&status)); // recupera il PID del processo figlio che ha terminato
        printf("Il codice di terminazione del processo figlio: %d\n", WEXITSTATUS(status)); // ritorna la variabile status usata dal metodo exit (usato dal processo figlio), ripreso poi dal processo padre
    }

    return 0;
}