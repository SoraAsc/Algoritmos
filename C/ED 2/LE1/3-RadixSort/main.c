#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * countingSort(int * A, int * B, int * C, int n) {
	// k � o maior elemento do vetor A, n � o tamanho do vetor A.
    int i, j, k;

	// Descobrir o maior n�mero dentro do vetor original(A)
    k = A[0];
    for(i = 1 ; i < n; i++)
        if(A[i]>k)
            k = A[i];

	k = k + 1;
	// Vetor contador com valores zerados
    C = (int *) calloc(k, sizeof(int));
    // Vetor de sa�da
    B = (int *) calloc(n, sizeof(int));

	// Soma quantas vezes repete o elemento na sua respectiva posi��o
    for(j = 0; j < n; j++)
        C[A[j]] = C[A[j]] + 1;

	// V� quantos elementos s�o menores que ele somando
    for(i = 1; i < k; i++)
        C[i] = C[i] + C[i-1];
    
    // Como nessa implementa��o, colocamos uma posi��o a mais em k, � importante lembrar de subtrair a posi��o do vetor B por 1.
    for(j = n-1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    return B;
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

int main()
{
    //srand(time(NULL));
    srand(100);
    int *A, *B, *C, n;
    n = 40;
    A = createArray(n);

    fillArray(A, n);
	printf("\n-------------------- Array Original(Counting Sort) --------------------\n");
	showArray(A, n);

	B = countingSort(A, B, C, n);
	printf("\n-------------------- Array Modificada(Counting Sort) --------------------\n");
	showArray(B, n);

    return 0;
}

