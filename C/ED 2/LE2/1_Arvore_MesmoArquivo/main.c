#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

#include <time.h>
#define N 10000

void gerarnumeros(int vetor[], int quantidade){
	int indice;
	srand(time(NULL));
	
	for(indice=0; indice < quantidade; indice++){
		vetor[indice] = rand()%10000; //vai gerar números de 0 a 9999
	};
}


void inserirB(int vetor[], int quantidade, ArvBin* arvore){
	int indice;
	
	for(indice=0; indice < quantidade; indice++){
		insere_ArBin(arvore, vetor[indice]);
	};
}


void inserirAVL(int vetor[], int quantidade, ArvAVL* arvore){
	int indice;
	
	for(indice=0; indice < quantidade; indice++){
		insere_ArvAVL(arvore, vetor[indice]);
	};
}

int main()
{
   // Definições de variáveis
	ArvBin* MinhaArvoreB;
	ArvAVL* MinhaArvoreAVL;
	int vet[N];
    
    gerarnumeros(vet,N);
   // Cria a árvore binária de busca
	printf("Arvore binaria de busca\n");

	MinhaArvoreB = cria_ArvBin();
	MinhaArvoreAVL = cria_ArvAVL();
	
	inserirB(vet, N, MinhaArvoreB);
	inserirAVL(vet, N, MinhaArvoreAVL);

    
	printf("\n A arvore de busca binaria contem os seguintes elementos:\n");
	emOrdem_ArvBin(MinhaArvoreB);
	printf("\n A arvore de busca binaria possui altura %d .\n", altura_ArvBin(MinhaArvoreB));
	
	system("PAUSE");
	
	printf("\n A arvore AVL contem os seguintes elementos:\n");
	emOrdem_ArvAVL(MinhaArvoreAVL);
	printf("A altura da arvore AVL: %d\n",altura_ArvAVL(MinhaArvoreAVL));
	
	libera_ArvAVL(MinhaArvoreAVL);
	libera_ArvBin(MinhaArvoreB); //coloquei isso pra liberar a árvore
	return 0;
}

