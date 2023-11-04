#include <stdio.h>
#include <stdlib.h>
#include "TAD_Fila3iii.h"

typedef struct node
{
	void* dado;
	struct node* prox;	
}NODE;

struct queue
{
	int cont; // Tamanho da Fila.
	NODE* inicio;
	NODE* final;
};

Queue* Create_Queue()
{
	Queue* fi = (Queue*)malloc(sizeof(Queue));
	if(fi != NULL){
		fi->final = NULL;
		fi->final = NULL;
		fi->cont = 0;
	}
	return fi;
}

void Destroy_Queue(Queue* fi){
	if( fi != NULL){
		NODE* no;
		while(fi->inicio != NULL){
			no = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(no);
		}
		free(fi);
	}
}


int Size_Queue(Queue* fi){
	if( fi == NULL)
		exit(0);
	return fi->cont;
	}


bool Full_Queue(Queue *fi){
	if( fi == NULL)
		exit(0);
	NODE* aux;
	if(aux = (NODE*)malloc(sizeof(NODE))){
		free(aux);
		return true;
	}
	return false;
}

bool Empty_Queue(Queue *fi){
	if( fi == NULL)
		exit(0);
	if(fi->cont == 0)
		return true;
	return false;
}

void Enqueue(Queue *fi, void * valor){
	if( fi == NULL)
		exit(0);
	NODE* no = (NODE*)malloc(sizeof(NODE));
	if(no == NULL)
		exit(1);
	no->dado = valor;
	no->prox = NULL;
	if(fi->final == NULL) // fila vazia
		fi->inicio = no;
	else
		fi->final->prox = no;
		fi->final = no;
		fi->cont++;
}

void * Dequeue(Queue *fi){
	NODE* aux;
	void * valor; // é pra receber o conteúdo que será retornado
	if(fi == NULL)
		exit(0);
	if(fi->inicio == NULL) // fila vazia
		exit(0);
	aux = fi->inicio;
	fi->inicio = fi->inicio->prox;
	valor = aux->dado;
	free(aux);
	if(fi->inicio == NULL) // verifica se a fila ficou vazia
		fi->final = NULL;
	fi->cont--;
	return valor;
}

void* Peek_Queue(Queue *fi){
	if(fi== NULL)
		exit(0);
	if(fi->inicio == NULL) // verifica se a fila está vazia
		exit(0);
	return fi->inicio->dado;
}
