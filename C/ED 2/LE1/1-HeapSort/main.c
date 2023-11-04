#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//------------------------------ Begin: Heap Sort ------------------------------
void criaHeap(int *V, int pai, int fim) {
	int aux = V[pai];
	int filho = 2 * pai + 1;
	while(filho <= fim){
		if(filho < fim)
			if(V[filho] < V[filho + 1])
				filho++;
		if(aux < V[filho]){
			V[pai] = V[filho];
			pai = filho;
			filho = 2 * pai + 1;
		} else filho = fim + 1;
	}
	V[pai] = aux;
}

void heapSort(int *V, int n) {
	int i, aux;
	for(i=(n-1)/2; i >=0; i--)
		criaHeap(V, i, n-1);
	for(i = n-1; i >=1; i--) {
		aux = V[0];
		V[0] = V[i];
		V[i] = aux;
		criaHeap(V, 0, i - 1);
	}	
}

//------------------------------ Begin: Auxiliar ------------------------------
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

int main(int argc, char *argv[]) {
//	srand(time(NULL));
	srand(100);
	int n;
	int *VHeapSort;
	clock_t tempoInicial = clock();
	printf("\nO Tamanho da Array: ");
	scanf("%d", &n);
	
	VHeapSort = createArray(n);

	
	fillArray(VHeapSort, n);
	printf("\n-------------------- Array Original(Heap Sort) --------------------\n");
	showArray(VHeapSort, n);
	
	heapSort(VHeapSort, n);
	printf("\n-------------------- Array Modificada(Heap Sort) --------------------\n");
	showArray(VHeapSort, n);
	
	printf("\n\nTempo decorrido: %.2f segundos", (double)(clock() - tempoInicial) / CLOCKS_PER_SEC);
	return 0;
}
