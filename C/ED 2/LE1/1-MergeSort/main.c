#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//------------------------------ Begin: Merge Sort ------------------------------
void merge(int *V, int inicio, int meio, int fim) {
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio + 1;
	temp = (int *) malloc(tamanho*sizeof(int));
	if(temp != NULL) {
		for(i = 0; i < tamanho; i++) {
			if(!fim1 && !fim2) {
				if(V[p1] < V[p2])
					temp[i] = V[p1++];
				else temp[i] = V[p2++];
				if(p1 > meio) fim1 = 1;
				if(p2 > fim) fim2 = 1;
			} else {
				if(!fim1) temp[i] = V[p1++];
				else temp[i] = V[p2++];
			}
		}
		for(j = 0, k = inicio; j < tamanho; j ++, k++)
			V[k] = temp[j];
	}
	free(temp);
}

void mergeSort(int *V, int inicio, int fim) {
	int meio;
	if(inicio < fim) {
		meio = floor((inicio + fim) / 2);
		mergeSort(V, inicio, meio);
		mergeSort(V, meio + 1, fim);
		merge(V, inicio, meio, fim);
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
	int *VMergeSort;
	clock_t tempoInicial = clock();
	printf("\nO Tamanho da Array: ");
	scanf("%d", &n);
	
	VMergeSort = createArray(n);

	fillArray(VMergeSort, n);
	printf("\n-------------------- Array Original(Merge Sort) --------------------\n");
	showArray(VMergeSort, n);
	
	mergeSort(VMergeSort, 0, n);
	printf("\n-------------------- Array Modificada(Merge Sort) --------------------\n");
	showArray(VMergeSort, n);
	
	printf("\n\nTempo decorrido: %.2f segundos", (double)(clock() - tempoInicial) / CLOCKS_PER_SEC);

	return 0;
}
