#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TAD_Pilha_Inteiro1ii.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Preenche a stack com n n�meros aleat�rios.
void FillStack(Stack* pilha, int n)
{
	printf("\n-------------- Ordem Original --------------\n");
	int i;
	for(i = 0; i < n; i++)
	{
		// Cria um novo endere�o para o valor e o passa no PushStack
		int valor = rand() % 100;
		printf("%d ", valor);
		PushStack(pilha, valor);
	}
	printf("\n------------------ Fim ------------------");
}

void ShowStack(Stack* pilha)
{
	printf("\n-------------- Ordem Inversa --------------\n");
	while(!EmptyStack(pilha))
	{
		int valor = PopStack(pilha);
		printf("%d ", valor);
	}
	printf("\n------------------ Fim ------------------");
}

int main(int argc, char *argv[]) 
{
	// Gera uma nova seed(semente) a cada execu��o, assim gerando n�meros realmente "aleat�rios".
	srand(time(NULL));
	
	Stack* s1 = CreateStack();
	
	FillStack(s1, 20);
	ShowStack(s1);
	
	DestroyStack(s1);
	
	return 0;
}

