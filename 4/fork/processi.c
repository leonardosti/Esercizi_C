#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int p; // variabile che permette di gestire i processi (padre e figlio)
int main(int argc, char *argv[])
{
    p = fork(); // la funzione fork genera un processo (processo padre -> processo figlio)
    if (p != 0) // processo padre
    {
        printf("processo padre: %d\n", p);
        printf("PID processo padre: %d\n", getpid()); // PID -> Process ID
    }
    else // processo figlio
    {
        printf("processo figlio: %d\n", p);
        printf("PID processo figlio: %d\n", getpid()); // il PID del processo figlio è sempre uguale alla "p" del processo padre, e la "p" del figlio è sempre uguale a 0
        printf("PID processo padre all'interno del processo figlio: %d\n", getppid()); // PID del processo padre 
    }

    return 0;
}