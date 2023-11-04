#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Tamanho do Vetor
#define TAM 50000

void bubbleSort(int *V, int N, unsigned int * atribuicaoCont, unsigned int *comparacaoCont);

void selectionSort(int *V, int N, unsigned int * atribuicaoCont, unsigned int *comparacaoCont);

void insertionSort(int *V, int N, unsigned int * atribuicaoCont, unsigned int *comparacaoCont);

int* preencherVetor(int N);

void copiarVetor(int N, int *V, int *temp_V);

void mostrarVetor(int N, int *V);

int main(int argc, char *argv[]) 
{
	setlocale(LC_CTYPE, "Portuguese");
	setlocale(LC_NUMERIC, "en_US.UTF-8");
	srand(100); //Usado na questão 3
	//srand( (unsigned)time(NULL) );
	
	clock_t start_t, end_t;
	FILE* file;
	int opt = 0;
	unsigned int atribuicaoCont = 0, compaCont = 0;
	
	char nomeAlgoritmo[25] = "";
	int *v = preencherVetor(TAM);
	int *a = (int *) malloc(TAM * sizeof(int));	
	copiarVetor(TAM, v, a);
	
	file = fopen("UsedTime.csv", "a");	
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo\n");
		return 404;
	}
	
	fseek(file, 0, SEEK_END);
	if(ftell(file) == 0)
		fprintf(file, "Nome do Algoritmo, Tamanho do Vetor, Tempo Usado, Comparações Feitas, Atribuições Feitas\n");	
	
	printf("0 - Bubble Sort | 1 - Selection Sort | 2 - Insertion Sort\nSelecione o Algoritmo entre 0 a 2: ");
	scanf("%d", &opt);
	
	//mostrarVetor(TAM, a); //Comentado em testes maiores
	switch(opt)
	{
		case 0:
			start_t = clock();
			bubbleSort(a, TAM, &atribuicaoCont, &compaCont);
			end_t = clock();
			strcpy(nomeAlgoritmo, "Bubble Sort");
			break;
		case 1:
			start_t = clock();
			selectionSort(a, TAM, &atribuicaoCont, &compaCont);
			end_t = clock();
			strcpy(nomeAlgoritmo, "Selection Sort");
			break;
		default:
			start_t = clock();
			insertionSort(a, TAM, &atribuicaoCont, &compaCont);
			end_t = clock();
			strcpy(nomeAlgoritmo, "Insertion Sort");
			break;	
	}
	double duration = ((double) (end_t - start_t)) / CLOCKS_PER_SEC; //Em segundos
	duration = duration * 1000.0; //Em mili segundos
	fprintf(file, "%s, %d, %.3f, %d, %d\n", nomeAlgoritmo, TAM, duration, compaCont, atribuicaoCont);		
	printf("Tempo Usado(%s): %.3f ms", nomeAlgoritmo, duration);
	//mostrarVetor(TAM, a); //Comentado em testes maiores
	

	fclose(file);
	free(v);
	free(a);
	return 0;
}

void copiarVetor(int N, int *V, int* temp_V)
{
	int i;
	for(i = 0; i < N; i++)
	{
		temp_V[i] = V[i];
	}
}

int * preencherVetor(int N)
{
	int i;
	int *v = (int *) malloc(sizeof(int) * N);
	for(i = 0; i < N; i++)
	{
		v[i] = rand() % 100;
	}
	return v;
}

void mostrarVetor(int N, int *V)
{
	int i = 0;
	printf("\n\n____________________Vetor (%d)____________________\n", N);
	for(i = 0; i < N; i++)
	{
		printf("%d ", V[i]);
	}
	printf("\n");
}

void bubbleSort(int *V, int N, unsigned int * atribuicaoCont, unsigned int *comparacaoCont)
{
	int i, continua, aux, fim = N;
	do
	{
		continua = 0;
		for(i = 0; i < fim - 1; i++)
		{
			*comparacaoCont+=1; //Comparação
			if(V[i] > V[i+1])
			{
				aux = V[i];
				V[i] = V[i+1];
				V[i+1] = aux;
				*atribuicaoCont+=3;	//Troca
				continua = i;
			}
		}
		fim--;
	} while(continua != 0);
	printf("\nBubble Sort: Houve %u comparações e %u atribuições\n", *comparacaoCont, *atribuicaoCont);
}

void selectionSort(int *V, int N, unsigned int * atribuicaoCont, unsigned int *comparacaoCont)
{
	int i, j, menor, troca;
	for(i = 0; i < N-1; i++)
	{
		menor = i;
		for(j = i+1; j < N; j++)
		{
			*comparacaoCont+=1; //Comparação
			if(V[j]< V[menor])
				menor = j;	
		}
		*comparacaoCont+=1; //Comparação
		if(i != menor)
		{
			troca = V[i];
			V[i] = V[menor];
			V[menor] = troca;
			*atribuicaoCont+=3; //Troca
		}
	}
	printf("\nSelection Sort: Houve %u comparações e %u atribuições\n", *comparacaoCont, *atribuicaoCont);
}

void insertionSort(int *V, int N, unsigned int * atribuicaoCont, unsigned int *comparacaoCont)
{
	int i, j, atual;
	for(i = 1; i < N; i++)
	{
		atual = V[i];
		for(j = i; (j > 0) && (atual < V[j-1]); j--)
		{
			*comparacaoCont+=1; //Comparação no for
			*atribuicaoCont+=1; //Deslocamento
			V[j] = V[j-1];
		}
		*atribuicaoCont+=1; //Deslocamento
		V[j] = atual;
	}
	printf("\nInsertion Sort: Houve %u comparações e %u atribuições\n", *comparacaoCont, *atribuicaoCont);
}

