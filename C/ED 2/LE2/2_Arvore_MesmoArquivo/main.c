#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Arvore.h"

#include <time.h>
#define N 50

void gerarnumeros(int vetor[], int quantidade){
	int indice;
	srand(time(NULL));
	
	for(indice=0; indice < quantidade; indice++){
		vetor[indice] = rand()%100; //vai gerar números de 0 a 99
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
	setlocale(LC_ALL,"Portuguese");
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

    
	printf("\n A arvore de busca binaria contem os seguintes elementos em ordem:\n");
	emOrdem_ArvBin(MinhaArvoreB);
	
	printf("\n A arvore de busca binaria contem os seguintes elementos em pré-ordem:\n");
	preOrdem_ArvBin(MinhaArvoreB);
	
	printf("\n A arvore de busca binaria contem os seguintes elementos em pos-ordem:\n");
	posOrdem_ArvBin(MinhaArvoreB);
	
	system("PAUSE");
	
	printf("\n A arvore AVL contem os seguintes elementos em ordem:\n");
	emOrdem_ArvAVL(MinhaArvoreAVL);
	
	printf("\n A arvore AVL contem os seguintes elementos em pré-ordem:\n");
	preOrdem_ArvAVL(MinhaArvoreAVL);
	
	printf("\n A arvore AVL contem os seguintes elementos em pos-ordem:\n");
	posOrdem_ArvAVL(MinhaArvoreAVL);
	
	libera_ArvAVL(MinhaArvoreAVL);
	libera_ArvBin(MinhaArvoreB); //coloquei isso pra liberar a árvore
	return 0;
}

