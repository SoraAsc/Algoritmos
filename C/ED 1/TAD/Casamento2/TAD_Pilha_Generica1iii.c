#include <stdlib.h>
#include <stdio.h>
#include "TAD_Pilha_Generica1iii.h"

typedef struct node
{
	void* element;
	struct node* link;
	
} STACK_NODE;

struct stack
{
	int size;
	STACK_NODE* top;
};

// Aloca um endereço na memória para a pilha e a retorna.
Stack* CreateStack()
{
	Stack* s;
	s = (Stack *) malloc(sizeof(Stack));
	if( s != NULL)
	{
		s->size = 0;
		s->top = NULL;
	}
	return s;
}


// Retorna 1 ou 0, dependendo do estado da pilha, sendo 1 pilha vazia.
int EmptyStack(Stack* pilha)
{
	// Operador Ternário: (Se tamanho da pilha for maior que 0, retorna 0, se não 1).
	return (pilha->size > 0 ? 0 : 1);
}

// Retorna 1 ou 0, dependendo do estado da pilha, sendo 1 pilha cheia.
int FullStack(Stack * pilha)
{
	STACK_NODE* temp;
	if((temp = (STACK_NODE*) malloc(sizeof(*(pilha->top)))))
	{
		free(temp);
		return 0;
	}
	return 1;
}

// Retorna o tamanho(size) atual da pilha.
int SizeStack(Stack* pilha)
{
	return pilha->size;
}

// Insere um novo elemento no topo da pilha.
void PushStack(Stack* pilha, void* valor)
{
	STACK_NODE* novoNode = (STACK_NODE*) malloc(sizeof(STACK_NODE));
	if(!novoNode)
	{
		printf("\nEstouro da pilha");
		exit(1);
	}
	
	novoNode->element = valor;
	novoNode->link = pilha->top;
	pilha->top = novoNode;
	(pilha->size)++;	
}

// Remove o elemento no topo da pilha.
void* PopStack(Stack* pilha)
{
	void* valor;
	STACK_NODE* temp;
	
	if(pilha->size == 0)
		valor = NULL;
	else
	{
		temp = pilha->top;
		valor = pilha->top->element;
		pilha->top = pilha->top->link;
		free(temp);
		(pilha->size)--;
	}
	return valor;
}

// Acessa o elemento no topo da pilha, sem remove-lo.
void* PeekStack(Stack* pilha)
{
	if(pilha->size == 0) return NULL;
	else return pilha->top->element;	
}

// Apaga os endereços alocados pela pilha junto com seus nós e elementos.
Stack* DestroyStack(Stack* pilha)
{
	STACK_NODE* temp;
	
	if(pilha)
	{
		while(pilha->top != NULL)
		{
			free(pilha->top->element);
			temp = pilha->top;
			pilha->top = pilha->top->link;
			free(temp);
		}
		free(pilha);
	}
	return NULL;
}



