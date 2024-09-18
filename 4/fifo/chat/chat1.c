#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int fd;
 
    char arr1[80], arr2[80];
    while (1)
    {
        // Open FIFO for write only
        fd = open("fifo1", O_WRONLY);
 
        // Take an input arr2ing from user.
        // 80 is maximum length
        fgets(arr2, 80, stdin);
 
        // Write the input arr2ing on FIFO
        // and close it
        write(fd, arr2, strlen(arr2)+1);
        close(fd);
 
        // Open FIFO for Read only
        fd = open("fifo1", O_RDONLY);
 
        // Read from FIFO
        read(fd, arr1, sizeof(arr1));
 
        // Print the read message
        printf("User2: %s\n", arr1);
        close(fd);
    }

    return 0;
}