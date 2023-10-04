#include <stdio.h>
#include <string.h>

int main(int argc, char *argv)
{
    char stringa[20], pari[20], dispari[20], stringa2[20];
    int verifica = 0, cntVocali = 0, cntVocali2 = 0, cntCons = 0, cntCons2 = 0, contP = 0, contD = 0;

    do
    {
        verifica = 0;
        printf("Insersci la prima stringa\n");
        scanf("%s", stringa);
        for (int i = 0; i < strlen(stringa); i++)
        {
            if (stringa[i] == '1' || stringa[i] == '2' || stringa[i] == '3' || stringa[i] == '4' || stringa[i] == '5' || stringa[i] == '7' || stringa[i] == '8' || stringa[i] == '9' || stringa[i] == '0')
            {
                verifica++;
            }
        }
    } while (verifica > 0);
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (i % 2 == 0)
        {
            pari[contP] = stringa[i];
            contP++;
        }
        else
        {
            dispari[contD] = stringa[i];
            contD++;
        }
    }
    printf("I caratteri posizione pari sono:\n");
    printf("%s\n", dispari);
    printf("I caratteri posizione dispari sono:\n");
    printf("%s\n", dispari);
    do
    {
        verifica = 0;
        printf("Insersci la seconda stringa\n");
        scanf("%s", stringa2);
        for (int i = 0; i < strlen(stringa2); i++)
        {
            if (stringa2[i] == '1' || stringa2[i] == '2' || stringa2[i] == '3' || stringa2[i] == '4' || stringa2[i] == '5' || stringa2[i] == '7' || stringa2[i] == '8' || stringa2[i] == '9' || stringa2[i] == '0')
            {
                verifica++;
            }
        }
    } while (verifica > 0);
    if (strlen(stringa) > strlen(stringa2))
    {
        printf("La stringa più lunga è la prima\n");
    }
    else if (strlen(stringa) == strlen(stringa2))
    {
        printf("Le due stringhe contengono lo stesso numero di caratteri\n");
    }
    else
    {
        printf("La stringa più lunga è la seconda\n");
    }
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == 'a' || stringa[i] == 'e' || stringa[i] == 'i' || stringa[i] == 'o' || stringa[i] == 'u')
        {
            cntVocali++;
        }
        else
        {
            cntCons++;
        }
    }
    for (int i = 0; i < strlen(stringa2); i++)
    {
        if (stringa2[i] == 'a' || stringa2[i] == 'e' || stringa2[i] == 'i' || stringa2[i] == 'o' || stringa2[i] == 'u')
        {
            cntVocali2++;
        }
        else
        {
            cntCons2++;
        }
    }
    if (cntVocali > cntVocali2)
    {
        printf("La prima stringa contiene più vocali\n");
    }
    else if (cntVocali == cntVocali2)
    {
        printf("Le stringhe contengono lo stesso numero di vocali\n");
    }
    else
    {
        printf("La seconda stringa contiene più vocali\n");
    }

    if (cntCons > cntCons2)
    {
        printf("La prima stringa contiene più consonanti\n");
    }
    else if (cntCons == cntCons2)
    {
        printf("Le stringhe contengono lo stesso numero di consonanti\n");
    }
    else
    {
        printf("La seconda stringa contiene più consonanti\n");
    }

    return 0;
}