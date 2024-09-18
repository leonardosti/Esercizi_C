#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* Consumatore(void *par)
{
    
}
void* Produttore(void *par)
{

}

int main(int argc, char *argv[])
{
    pthread_t threadC, threadP;
    pthread_create(&threadC, NULL, &Consumatore, NULL);
    pthread_create(&threadP, NULL, &Produttore, NULL);

    return 0;
}