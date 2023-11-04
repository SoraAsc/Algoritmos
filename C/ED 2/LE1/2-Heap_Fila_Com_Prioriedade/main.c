#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "TAD_Heap.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Ordem de Chegada: Primeiro valor uma constante: ex: 1000
// (prioriedade + ordem de chegada)
// Os métodos foram deixados em inglês por padronização,
// mas a implementação em português para melhor explicação

int * buildAndFillArray(int n);
void showArray(int n, int *v);
void showChoices();

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	srand(100);
	//srand(time(NULL));
	int *v, n = 40, i, removed, option;
	Heap *heap;
	
	v = buildAndFillArray(40);
	
//	heap = createHeap(n);
//	for(i = 0; i < n; i++)
//		insertHeap(heap, &v[i]);
		
	heap = buildHeap(v, n);
			
	showChoices();	
	while(true)
	{
		printf("\nInforme a sua escolha (0 = Opcções): ");
		scanf("%d", &option);
		switch(option)
		{
			case 0:
				showChoices();
				break;
			case 1:
				peekHeap(heap, &removed);
				printf(" %d ", removed);
				break;
			case 2:
				deleteHeap(heap, &removed);
				printf(" %d ", removed);
				break;
			case 3:
				printf("\n------------------------------------------ Vetor ------------------------------------------\n"); 
				showArray(n, v);
				printf("\n------------------------------------------  Fim  ------------------------------------------\n"); 
				break;
			case 4:
				printf("\n------------------------------------------  Heap ------------------------------------------\n"); 
				showHeap(heap);
				printf("\n------------------------------------------  Fim  ------------------------------------------\n"); 
				break;
			case 5:
				printf("Elemento: ");
				scanf("%d", &removed);
				insertHeap(heap, &removed);
				break;
			default:
				return;
		}
	}
		
	freeHeap(heap);
	return 0;
}

int * buildAndFillArray(int n)
{
	int i;
	int* v = (int *) malloc(sizeof(int) * n);
	for( i = 0; i < n; i++)	
		v[i] = rand()%1001;
	return v;
}

void showArray(int n, int *v)
{
	int i;
	printf("[");
	for(i = 0; i < n; i++)
		printf("%d%s", v[i], (n == i + 1 ? "" : ", "));
	printf("]");
}

void showChoices()
{
	system("@cls||clear");
	printf("\n--------------- Opções ---------------");
	printf("\n0 - Ver Opcções");
	printf("\n1 - Ver Elemento no Topo");
	printf("\n2 - Remover Elemento do Topo");
	printf("\n3 - Mostrar Vetor Original");
	printf("\n4 - Mostrar Heap");
	printf("\n5 - Adicionar Elemento na Heap");
	printf("\n6 - Sair");
	printf("\n---------------   Fim  ---------------");
}
