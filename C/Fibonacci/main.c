#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define TAM 1000000000
unsigned long iteraCont = 0;
unsigned long fibo_itera(int n); //Iterativo

unsigned long fibo_recur(int n); //Recursivo

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	clock_t start_t, end_t;	
	iteraCont = 0;
	start_t = clock();
	printf("\nFibonacci Iterativo de tamanho %d: %lu\n", TAM, fibo_itera(TAM));
	end_t = clock();
	double duration = (double) (end_t - start_t) / CLOCKS_PER_SEC;
		printf("\nFoi feito %lu iterações em %.3f segundos", iteraCont, duration);
	
	iteraCont = 0;
	start_t = clock();
	printf("\nFibonacci Recursivo de tamanho %d: %lu\n", TAM, fibo_recur(TAM));
	end_t = clock();
	duration = (double) (end_t - start_t) / CLOCKS_PER_SEC;
	printf("\nFoi feito %lu iterações em %.3f segundos", iteraCont, duration);
	return 0;
}

unsigned long fibo_recur(int n)
{
	iteraCont++;
	if(n == 1)
		return 1;
	else if(n <= 0)
		return 0;
	return fibo_recur(n-1) + fibo_recur(n-2);
}

unsigned long fibo_itera(int n)
{
	unsigned long resultado = 0;
	unsigned long anterior = 1;	
	//printf("%d ", resultado);
	while(n > 0)
	{
		unsigned long temp = resultado;
		resultado += anterior;
		anterior = temp;
		//printf("%d ", resultado);
		n--;
		iteraCont++;
	}
	//printf("\n");
	return resultado;
}
