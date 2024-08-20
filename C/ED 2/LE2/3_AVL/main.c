#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main()
{
   // Definições de variáveis
	ArvAVL* MinhaArvore;
    int num;
   // Cria a árvore binária de busca
	printf("Comeca o teste da Arvore AVL\n");

	MinhaArvore = cria_ArvAVL();

    // Ingressa dados na árvore binária de busca
	printf("Ingrese uma lista de inteiros positivos.\n");
	printf("Para concluir ingresse um numero negativo.\n");

	do{
	   printf("Ingrese um numero: ");
	   scanf ("%d", &num);
	   if(num > -1){
	     insere_ArvAVL(MinhaArvore, num);
	   }
	} while (num > -1);

	printf("\n A arvore contem os seguintes elementos:\n");
	preOrdem_ArvAVL(MinhaArvore);
	printf("A altura da arvore e: %d\n",altura_ArvAVL(MinhaArvore));
	return 0;
}
