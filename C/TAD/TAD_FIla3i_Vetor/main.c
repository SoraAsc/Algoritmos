#include <stdio.h>
#include <stdlib.h>
#include "TAD_Fila3i.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue* fila;
	
	fila = Create_Queue();
	
	Enqueue(fila, 1);
	Enqueue(fila, 2);
	Dequeue(fila);
	Dequeue(fila);
	Enqueue(fila, 3);
	Enqueue(fila, 1);
	
	printf("\nElementos Presentes na Fila: [3, 1] \n");
	
	printf("\nO Tamanho da Fila eh: %d", Size_Queue(fila));
	printf("\nA fila estah Cheia: %s", Full_Queue(fila) ? "true" : "false");
	printf("\nA fila estah Vazia: %s\n", Empty_Queue(fila) ? "true" : "false");
	
	printf("\nMostrar Elemento da Fila sem remover: %d", Peek_Queue(fila));
	printf("\nMostrar Elemento da Fila Removendo: %d", Dequeue(fila));
	printf("\nMostrar Elemento da Fila Removendo: %d\n", Dequeue(fila));
	
	printf("\nA fila estah Vazia: %s", Empty_Queue(fila) ? "true" : "false");
	
	Destroy_Queue(fila);
	return 0;
}
