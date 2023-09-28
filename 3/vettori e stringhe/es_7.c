#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
<<<<<<< HEAD
    char stringa[20], stringa2[20], max[20], min[20];
    int cont = 0;
=======
    char stringa[20], stringa2[20], max[20], min[20], presenti[20];
    int cont = 0, trova;
>>>>>>> 1a04c3349ddc0e5115e07265fdc53ca20a03eec6

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
<<<<<<< HEAD
                printf("%s \n", &min[j]);
                cont++;
=======
                trova = 1;
                break;
>>>>>>> 1a04c3349ddc0e5115e07265fdc53ca20a03eec6
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