
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv)
{

    char stringa[20], lettere[20], speciali[20], z = 'a', ordinate[20];
    int cntSpeciali = 0, cntLettere = 0;

    printf("Inserisci una stringa (inserisci caratteri speciali e lettere minuscole)\n");
    scanf("%s", stringa);
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] < 'a' || stringa[i] > 'z')
        {
            speciali[cntSpeciali] = stringa[i];
            cntSpeciali++;
        }
        else
        {
            lettere[cntLettere] = stringa[i];
            cntLettere++;
        }
    }
    cntLettere = 0;
    strcpy(ordinate, lettere);
    for (int i = 0; i < strlen(lettere); i++)
    {
        if (lettere[i] > z)
        {
            ordinate[cntLettere] = z;
            z = lettere[i];
            cntLettere++;
        }
    }
    printf("I caratteri speciali sono: %s\n", speciali);
    printf("Le lettere sono: %s\n\n", ordinate);

    return 0;
}