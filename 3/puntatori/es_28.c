#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char stringa[20];
    int ;
    do
    {
        printf("Inserisci una stringa alfanumerica\n");
        scanf("%s", stringa);
    } while (isalnum(stringa));

    return 0;
}