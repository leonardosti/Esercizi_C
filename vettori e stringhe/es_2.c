#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char stringa[21];
    int contaDoppiette= 0, lunghezza;
    printf("Inserisci una stringa \n");
    scanf("%s", stringa);
    lunghezza = strlen(stringa);
    for (int i = 0; i < lunghezza; i++)
    {
        if (stringa[i]==stringa[i+1])
        {
            contaDoppiette++;
        }
    }
    printf("La stringa ha  %d doppiette;\n", contaDoppiette);
    return 0;
    
}