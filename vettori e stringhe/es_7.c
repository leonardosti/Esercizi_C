#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char stringa[20], stringa2[20], max[20], min[20], presenti[20];
    int cont = 0, trova;

    printf("Inserisci la prima stringa\n");
    scanf("%s", stringa);
    printf("Inserisci la seconda stringa\n");
    scanf("%s", stringa2);
    if (strlen(stringa) != strlen(stringa2))
    {
        if (strlen(stringa) > strlen(stringa2))
        {
            strcpy(max, stringa);
            strcpy(min, stringa);
        }
        else
        {
            strcpy(min, stringa);
            strcpy(max, stringa2);
        }
    }
    else
    {
        strcpy(min, stringa);
        strcpy(max, stringa);
    }
    for (int i = 0; i < strlen(max); i++)
    {
        for (int j = 0; j < strlen(min); j++)
        {
            if (min[j] == max[i])
            {
                trova = 1;
                break;
            }
        }
        if (trova == 1)
        {
            presenti[cont] = max[i];
            cont++;
        }
    }
    presenti[cont] = '\0';
    printf("Le lettere in comuni sono: %s\n", presenti);


    return 0;
}