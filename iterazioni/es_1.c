
#include <stdio.h>

int main(int argc, char *argv[])
{

	int numero, successivo;

	do
	{									  
		printf("Inserisci un numero positivo: \n"); 
		scanf("%d", &numero);				  
	} while (numero <= 0);
	successivo = numero + 1;
	printf("il successivo e': %d\n", successivo); 

	return 0; 
}