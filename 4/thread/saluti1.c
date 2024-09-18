#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h> // libreria per i thread

// thread POSIX
void* stampaBuongiorno(void *par)
{
    printf("Buongiorno\n");
}
void* stampaBuonasera(void *par)
{
    printf("Buonasera\n");
}
void* stampaBuonanotte(void *par)
{
    printf("Buonanotter\n");
}

int main(int argc, char *argv[])
{
    ptherad_t threadBuongiorno, threadBuonasera, threadBuonanotte;

    printf("ciao\n");

    // creazione theard
    pthread_create(&threadBuongiorno, NULL, &stampaBuongiorno, NULL);
    pthread_create(&threadBuonasera, NULL, &stampaBuonasera, NULL);
    pthread_create(&threadBuonanotte, NULL, &stampaBuonanotte, NULL);
    pthread_join(threadBuongiorno, NULL);
    pthread_join(threadBuonasera, NULL);
    pthread_join(threadBuonanotte, NULL);

    return 0;
}