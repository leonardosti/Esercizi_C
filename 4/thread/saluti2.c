#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h> // libreria per i thread

// thread POSIX
void* stampaSaluti(void *par)
{
    printf("%s\n", (char*)par);
}

int main(int argc, char *argv[])
{
    ptherad_t threadBuongiorno, threadBuonasera, threadBuonanotte;

    char* msg1 = "Buongiorno";
    char* msg2 = "Buonasera";
    char* msg3 = "Buonanotte";

    // creazione theard
    pthread_create(&threadBuongiorno, NULL, &stampaSaluti, msg1);
    pthread_create(&threadBuonasera, NULL, &stampaSaluti, msg2);
    pthread_create(&threadBuonanotte, NULL, &stampaSaluti, msg3);
    pthread_join(threadBuongiorno, NULL);
    pthread_join(threadBuonasera, NULL);
    pthread_join(threadBuonanotte, NULL);

    return 0;
}