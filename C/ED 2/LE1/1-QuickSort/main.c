#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//------------------------------ Begin: Quick Sort ------------------------------
int particiona(int *V, int inicio, int final) {
	int esq, dir, pivo, aux;
	esq = inicio;
	dir = final;
	pivo = V[inicio];
	while(esq < dir) {
		while(V[esq] <= pivo)
			esq++;
		while(V[dir] > pivo)
			dir--;
		if(esq < dir) {
			aux = V[esq];
			V[esq] = V[dir];
			V[dir] = aux;
		}
	}
	V[inicio] = V[dir];
	V[dir] = pivo;
	return dir;
}

void quickSort(int *V, int inicio, int fim) {
	int pivo;
	if(fim > inicio) {
		pivo = particiona(V, inicio, fim);
		quickSort(V, inicio, pivo - 1);
		quickSort(V, pivo  + 1, fim);
	}
}
//------------------------------ End: Quick Sort ------------------------------

//------------------------------ Begin: Aux ------------------------------
int * createArray(int n)
{
	return (int *) malloc(n * sizeof(int));
}

int * fillArray(int *V, int n)
{
	int i;
	for(i = 0; i < n; i++)	
		V[i] = rand() % 100;
	
	return V;
}

void showArray(int *V, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", V[i]);
}

//------------------------------ End: Aux ------------------------------

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//srand(time(NULL));
	srand(100);
	int n;
	int *VQuickSort;
	clock_t tempoInicial = clock();
	printf("\nO Tamanho da Array: ");
	scanf("%d", &n);
	
	VQuickSort = createArray(n);
	
	fillArray(VQuickSort, n);
	printf("\n-------------------- Array Original(Quick Sort) --------------------\n");
	showArray(VQuickSort, n);
	
	quickSort(VQuickSort, 0, n);
	printf("\n-------------------- Array Ordenada(Quick Sort) --------------------\n");
	showArray(VQuickSort, n);	
	
	free(VQuickSort);
	
	printf("\n\nTempo decorrido: %.2f segundos", (double)(clock() - tempoInicial) / CLOCKS_PER_SEC);

	return 0;
}
