#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char stringa[21];
    char carattere;
    int contaCarattere = 0, lunghezza;
    printf("Inserisci una stringa \n");
    scanf("%s", stringa);
    lunghezza = strlen(stringa);
    printf("Inserisci il carattere da cercare \n");
    scanf("%s", &carattere);
    for (int i = 0; i < lunghezza; i++)
    {
        if (carattere==stringa[i])
        {
            contaCarattere++;
        }
    }
    printf("Il carattere compare %d volte;\n", contaCarattere);
    
    return 0;
}
