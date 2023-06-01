#define MAX 100
#include <stdlib.h>
#include <stdio.h>

#include "TAD_Pilha1i.h"

// Cabeçalho
struct stack
{
	int top; // Posição do Topo da Pilha, indice
	int elementos[MAX];
};

Stack* Create_Stack()
{
	Stack *s;
	s = (Stack *) malloc(sizeof(Stack));
	if(s != NULL)
		s->top = -1;
	return s;
}



bool Empty_Stack(Stack* pilha)
{
	return (pilha->top == -1 ? true : false);
}

bool Full_Stack(Stack* pilha)
{
	if(pilha->top == MAX-1)
	{
		printf("\nEstouro de Pilha");
		return true;
	} else return false;
}

int Size_Stack(Stack* pilha)
{
	return pilha->top+1;
}

void Push_Stack(Stack *pilha, int valor)
{
	if(!Full_Stack(pilha))
	{
		pilha->top+=1;
		pilha->elementos[pilha->top] = valor;
	}
}

int Pop_Stack(Stack *pilha)
{
	int temp = -1;
	if(!Empty_Stack(pilha))
	{
		temp = pilha->elementos[pilha->top];
		pilha->top -= 1;
	}
	return temp;
}

int Peek_Stack(Stack *pilha)
{
	return (pilha->elementos[pilha->top]);
}

void Destroy_Stack(Stack* pilha)
{
	free(pilha);
}


