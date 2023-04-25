#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char stringa[20], stringa2[20], max[20], min[20];
    int cont = 0;

    printf("Inserisci la prima stringa\n");
    scanf("%s", stringa);
    printf("Inserisci la seconda stringa\n");
    scanf("%s", stringa2);
    if (strlen(stringa) != strlen(stringa2))
    {
        if (strlen(stringa) < strlen(stringa2))
        {
            strcpy(max, stringa2);
            strcpy(min, stringa);
        }
        else
        {
            strcpy(max, stringa2);
            strcpy(min, stringa);
        }
    }
    else
    {
        strcpy(max, stringa);
        strcpy(min, stringa2);
    }
    printf("Lettere in comune:\n");
    for (int i = 0; i < strlen(max); i++)
    {
        for (int j = 0; j < strlen(min); j++)
        {
            if (cont != 0)
            {
                break;
            }
            if (max[i] == min[j])
            {
                printf("%s \n", &min[j]);
                cont++;
            }
        }
    }

    return 0;
}