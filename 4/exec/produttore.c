#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define BUFFER_DIM 1024
#define program "./consumentore.exe"

int spawn(char program[], char *argument)
{
    int p;

    if (p = fork() < 0)
    {
        return -1;
    }
    if (p > 0)
    {
        printf("Sono il processo figlio con PID: %d", getpid());
        return 0;
    }
    if (p == 0) // processo figlio
    {
        printf("Sono il processo figlio con PID: %d", getpid());
    }

    execv(program, argument);

    printf("Errore nella funzione execv\n");
    abort();
}

int main(int argc, char *argv[])
{
    FILE *log;
    int fifo;
    usigned char buffer[BUFFER_DIM];
    int n;
    char *arg[3];

    if (log = fopen("log.txt", "wr") == NULL)
    {
        printf("Errore nella creazione del file\n");
        return 0;
    }

    printf("Sono il consumatore\n");

    if (argc != 3)
    {
        return 0;
    }
    arg[0] = (char *malloc(strlen(program) + 1)); // +1 così prende anche il codice terminatore delle stringhe
    strcpy(arg[0], program);
    arg[1] = (char *malloc(strlen(argv[2]) + 1));
    strcpy(arg[1], argv[2]);
    arg[2] = NULL;

    if (spawn(program, arg) < 0) // controllo nel caso l'exec non vada a buon fine
    {
        free(arg[0]);
        free(arg[1]);
        return 0;
    }

    if (mkfifo("myFifo", 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("Errore nella creazione della fifo\n");
            return 1;
        }
    }

    fifo = open("myFifo", O_WRONLY);
    if (fifo < 0)
    {
        printf("Errore nell'apertura fifo\n");
        fclose(log);
        return 0;
    }

    return 0;
}