#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int p, conta_padre, conta_figlio;
int main(int argc, char *argv[])
{
    p = fork();
    if (p < 0)
    {
        printf("Errore nell'esecuzione del programma\n");
        exit(1);
    }
    else if (p != 0)
    {
        printf("Processo padre:\n");
        printf("PID processo padre: %d, PID processo figlio: %d\n", getpid(), p);
        for (conta_padre= 0; conta_padre <= 19; conta_padre++)
        {
            printf("%d\n", conta_padre);
        }
    }
    else
    {
        printf("Processo figlio:\n");
        printf("PID processo padre: %d, PID processo figlio: %d\n", getppid(), getpid());
        for (conta_figlio = 0; conta_figlio <= 170; conta_figlio++)
        {
            printf("%d\n", conta_figlio);
        }
    }

    return 0;
}