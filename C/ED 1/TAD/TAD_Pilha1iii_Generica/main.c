#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "TAD_Pilha_Generica1iii.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Preenche a stack com n números aleatórios.
void FillStack(Stack* pilha, int n)
{
	printf("\n-------------- Ordem Original --------------\n");
	int i;
	for(i = 0; i < n; i++)
	{
		// Cria um novo endereço para o valor e o passa no PushStack
		float* valor = (float *) malloc(sizeof(float));
		*valor = rand() % 100;
		printf("%.2f ", *valor);
		PushStack(pilha, valor);
	}
	printf("\n------------------ Fim ------------------");
}

// Preenche a Pilha com outra Pilha.
//void FillStackWithAnotherStack(Stack* pilhaIn, Stack* pilhaOut)
//{
////	printf("\n-------------- Ordem Original --------------\n");
//	while(SizeStack(pilhaIn) > 0)
//	{	
//		PushStack(pilhaOut,PopStack(pilhaIn));
//	}	
////	printf("\n------------------ Fim ------------------");
//}

void ShowStack(Stack* pilha)
{
	printf("\n-------------- Ordem Inversa --------------\n");
	while(!EmptyStack(pilha))
	{
		float * valor = (float *) PopStack(pilha);
		printf("%.2f ", *valor);
	}
	printf("\n------------------ Fim ------------------");
}

int main(int argc, char *argv[]) 
{
	// Gera uma nova seed(semente) a cada execução, assim gerando números realmente "aleatórios".
	srand(time(NULL));
	
	Stack* s1 = CreateStack();
	//Stack* s1Inversa = CreateStack();
	
	// -------------- Testes --------------
	//float* valor = (float *) malloc(sizeof(float));
	//*valor = 5.5f;
	//printf("%d\n",FullStack(s1));
	//printf("%d\n",EmptyStack(s1));
	
	//PushStack(s1,valor);
	//valor = (float *) malloc(sizeof(float));
	//*valor = 7.8f;
	//PushStack(s1,valor);
	//printf("%.2f\n",*(float *)PopStack(s1));
	//printf("%.2f\n",*(float *)PopStack(s1));
	//
	//printf("%.2f\n",*(float *)PopStack(s1));
	//printf("%.2f\n",*(float *)PopStack(s1));
	// -------------- Fim Testes --------------
	
	FillStack(s1, 20);
	//FillStackWithAnotherStack(s1, s1Inversa);
	ShowStack(s1);
	DestroyStack(s1);
	
	return 0;
}
