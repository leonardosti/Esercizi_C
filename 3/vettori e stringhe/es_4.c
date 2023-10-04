#include <stdio.h>
#include <string.h>

int main(int argc, char *argv)
{
    char stringa[100];
    char carattere;
    int cont = 0;
    printf("Inserisci la stringa\n");
    scanf("%s", stringa);
    printf("Inserisci il carattere da eliminare\n");
    scanf(" %c", &carattere);

    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == carattere)
        {
            for (i = 0; i < strlen(stringa); i++)
            {
                if (stringa[i] != carattere)
                {
                    printf("%c", stringa[i]);
                }
            }
        }
        else
        {
            cont++;
        }
    }
    printf("\n");
    if (cont > strlen(stringa))
    {
        printf("Carattere non presente nella stringa\n");
    }
    
    return 0;
}