#include <stdio.h>
#include <stdlib.h>
#include "TAD_Fila3i.h"

#define MAX 2

struct queue
{
	int elements[MAX];
	int front, rear;
	int cont;
 };
 
Queue* Create_Queue()
{
	Queue* q;
	q = (Queue *) malloc(sizeof(Queue));
	if(q != NULL)
	{
		q->cont = 0;
		q->front = -1;
		q->rear = -1;
	}
	return q;
}

bool Empty_Queue(Queue* fila)
{
	return (fila->front == -1 ? true : false);
}

bool Full_Queue(Queue* fila)
{
	if(fila->cont == MAX)	
		return true;
	return false;
}

int Size_Queue(Queue* fila)
{
	return fila->cont;
}

void Enqueue(Queue* fila, int valor)
{
	if(Full_Queue(fila))
	{
		printf("\nA fila estah cheia");
		exit(1);
	}
	if(Empty_Queue(fila)) fila->front = 0;
	fila->rear = (fila->rear + 1) % MAX;
	fila->elements[fila->rear] = valor;
	fila->cont++;
}

int Dequeue(Queue* fila)
{
	if(Empty_Queue(fila))
	{
		printf("\nA fila estah vazia!");
		exit(1);
	}
	int elemento = fila->elements[fila->front];
	if(fila->front == fila->rear)
	{
		fila->front = -1;
		fila->rear = -1;
	}
	else fila->front = (fila->front + 1) % MAX;
	fila->cont--;
	return elemento;
}

int Peek_Queue(Queue* fila)
{
	return fila->elements[fila->front];
}

void Destroy_Queue(Queue* fila)
{
	free(fila);
}



