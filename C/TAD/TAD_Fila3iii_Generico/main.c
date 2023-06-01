#include <stdio.h>
#include <stdlib.h>
#include "TAD_Fila3iii.h"



int main() {
	Queue* fila;
	
	fila = Create_Queue();
	
	Enqueue(fila, (int *) 7);
	Enqueue(fila, (int *) 10);
	Enqueue(fila, (int *) 8);
	
	printf("\nTamanho: %d", Size_Queue(fila));
	printf("\nPrimeiro elemento: %d", Peek_Queue(fila));
	printf("\nRemovendo o primeiro elemento: %d", Dequeue(fila));
		
	printf("\n\nNovo tamanho: %d", Size_Queue(fila));
	printf("\nAgora o primeiro elemento eh: %d", Peek_Queue(fila));
	printf("\nRemovendo o elemento: %d", Dequeue(fila));
	
	printf("\n\nO novo tamanho: %d", Size_Queue(fila));
	printf("\nO unico elemento: %d", Peek_Queue(fila));
	printf("\nRemovendo o elemento: %d", Dequeue(fila));
	
	printf("\nA pilha esta vazia?( 1= verdadeiro , 0 = falso): %d", Empty_Queue(fila));
	
	Destroy_Queue(fila);
	return 0;
}

