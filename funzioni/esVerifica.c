#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double somma(double a, double b, int *cont)
{
    (*cont)++;
    return a + b;
}
double sottrazione(double a, double b, int *cont)
{
    (*cont)++;
    return a - b;
}
double moltiplicazione(double a, double b, int *cont)
{
    (*cont)++;
    return a * b;
}
double divisione(double a, double b, int *cont)
{
    (*cont)++;
    if (b != 0)
    {
        return a / b;
    }
    else
    {
        printf("Non si può dividere per 0");
    }
}

int main(int argc, char *argv[])
{
    double a, b, risultato;
    int cont = 0;
    char operatore[20];

    do
    {
        printf("Inserire a\n");
        scanf("%lf", &a);
        printf("Inserire b\n");
        scanf("%lf", &b);
        printf("Inserire l'operatore matematico\n");
        printf("+ - addizione;\n");
        printf("- - sottrazione;\n");
        printf("* - moltiplicazione;\n");
        printf("/ - divisione;\n");
        printf("fine - Interrompi ciclo;\n");
        scanf("%s", operatore);
        if (strcmp(operatore, "+") == 0)
        {
            risultato = somma(a, b, &cont);
        }
        else if (strcmp(operatore, "-") == 0)
        {
            risultato = sottrazione(a, b, &cont);
        }
        else if (strcmp(operatore, "*") == 0)
        {
            risultato = moltiplicazione(a, b, &cont);
        }
        else if (strcmp(operatore, "/") == 0)
        {
            risultato = divisione(a, b, &cont);
        }
        if (strcmp(operatore, "fine") != 0)
        {
            printf("%lf\n", risultato);
        }
    } while (strcmp(operatore, "fine") != 0);
    printf("Hai effettuato %d operazioni\n", cont);
    
    return 0;
}