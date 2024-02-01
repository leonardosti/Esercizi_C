#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int fd[2]; // descrittore
    int p;
    if (pipe(fd) < 0) // creazione pipe
    {
        printf("Errore nella creazione della pipe\n");
        exit(-1);
    }

    p = fork();
    if (p < 0)
    {
        printf("Errore nella generazione del processo figlio\n");
        exit(-1);
    }

    if (p != 0) // processo padre
    {
        printf("Processo padre: PID: %d, PID figlio %d\n", getpid(), p);
        close(fd[0]); // chiusa pipe in lettura (uscita pipe)

        const char *message = "Buona fortuna";
        if (write(fd[1], message, strlen(message)) < 0) // file descriptor, il messaggio, lunghezza del messaggio
        {
            printf("Errore di scrittura della pipe\n");
            exit(-1);
        }
        close(fd[1]); // il processo padre ha finito di comunicare quindi si chiude la pipe in scrittura
        wait(0);
    }
    else // processo figlio
    {
        unsigned char buffer[BUFFER_SIZE];
        printf("Processo figlio: PID: %d, PID padre %d\n", getpid(), getppid());
        close(fd[1]); // chiusa pipe in scrittura (ingresso pipe)
        
        int n = read(fd[0], buffer, BUFFER_SIZE);
        if (n < 0) // il messaggio è nel buffer e il processo figlio lo preleva 1024 alla volta
        {
            printf("Errore di lettura della pipe\n");
            exit(-1);
        }
        buffer[n] = '\0'; // inserisco il codice terminatore all'ultima posizione
        printf("messaggio: %s\n", buffer);
        close(fd[0]);
    }
    // la piepe function sincronizza i processi
    return 0;
}
