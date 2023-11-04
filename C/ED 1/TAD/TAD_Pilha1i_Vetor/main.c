#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "TAD_Pilha1i.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Preenche a stack com n números aleatórios.
void FillStack(Stack* pilha, int n)
{
	printf("\n-------------- Ordem Original --------------\n");
	int i;
	for(i = 0; i < n; i++)
	{
		int valor = rand() % 100;
		printf("%d ", valor);
		Push_Stack(pilha, valor);
	}
	printf("\n------------------ Fim ------------------");
}

void ShowStack(Stack* pilha)
{
	printf("\n-------------- Ordem Inversa --------------\n");
	while(!Empty_Stack(pilha))
	{
		int valor = Pop_Stack(pilha);
		printf("%d ", valor);
	}
	printf("\n------------------ Fim ------------------");
}

int main(void) {
	setlocale(LC_ALL,"Portuguese");
	Stack *s1 = Create_Stack();
	
//	Push_Stack(s1,5);
//	
//	printf("\nTamanho da Pilha: %d", Size_Stack(s1));
//	
//	printf("\nTopo da Pilha: %d", Peek_Stack(s1));
//	
//	printf("\nTamanho da Pilha: %d", Size_Stack(s1));

	FillStack(s1, 20);
	ShowStack(s1);
	
	Destroy_Stack(s1);
	return 0;
}

