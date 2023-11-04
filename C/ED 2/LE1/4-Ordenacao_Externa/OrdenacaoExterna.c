# include <stdio.h>
# include <stdlib.h>
# include <time.h>

#define N 10000 // N é o tamanho máximo de dados na memória
#define M 1500000 // M é a quantidade de números no arquivo teste.

struct arquivo{
	FILE *f;
	int pos, MAX, *buffer; 
};

void salvaArquivo(char *nome, int *V, int tamanho, int mudaLinha);
void Sort(int *V, int inicio, int fim);
void preencherBuffer(struct arquivo* arq, int T);
void quickSort(int *V, int inicio, int fim);


void salvaArquivo(char *nome, int *V, int tamanho, int mudaLinha){
	int i;
	FILE *f = fopen(nome, "a");
	for(i = 0; i < tamanho - 1; i++){
		fprintf(f, "%d\n", V[i]);
	}
	if(mudaLinha == 0)
		fprintf(f, "%d", V[tamanho-1]);
	else
		fprintf(f, "%d\n", V[tamanho-1]);
	fclose(f);
}

void preencherBuffer(struct arquivo* arq, int T){
	int i;
	if(arq->f == NULL)
		return;
	arq->pos = 0;
	arq->MAX = 0;
	for(i=0; i < T; i++){
		if(!feof(arq->f)){
			fscanf(arq->f, "%d", &arq->buffer[arq->MAX]);
			arq->MAX++;
		}else{
			fclose(arq->f);
			arq->f = NULL;
			break;
		}
	}
}

void merge(char *nome, int K, int T){
	char novo[20];
	int i;
	int *saida = (int*)malloc(T*sizeof(int));
	struct arquivo* arq;
	arq = (struct arquivo*)malloc(K*sizeof(struct arquivo));
	for(i = 0; i < K; i++){
		sprintf(novo, "Temp%d.txt", i+1);
		arq[i].f = fopen(novo, "r");
		arq[i].buffer = (int*)malloc(T*sizeof(int));
		preencherBuffer(&arq[i], T);
	}
	int menor, quantidadeSaida = 0;
	while(procuraMenor(arq, K, T, &menor) == 1){
		saida[quantidadeSaida] = menor;
		quantidadeSaida++;
		if(quantidadeSaida == T){
			salvaArquivo(nome, saida, T, 1);
			quantidadeSaida = 0;
		}
	}
	if(quantidadeSaida != 0)
		salvaArquivo(nome, saida, quantidadeSaida, 1);
	
	for(i = 0; i < K; i++)
		free(arq[i].buffer);
	free(arq);
	free(saida);
}

int procuraMenor(struct arquivo* arq, int K, int T, int* menor){
	int i, idx = -1;
	for(i=0; i < K; i++){
		if(arq[i].pos < arq[i].MAX){
			if(idx == -1)
				idx = i;
			else{
				if(arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos])
					idx = i;
			}
		}
	}
	if(idx != -1){
		*menor = arq[idx].buffer[arq[idx].pos];
		arq[idx].pos++;
		if(arq[idx].pos == arq[idx].MAX)
			preencherBuffer(&arq[idx], T);
		return 1;
	}else
		return 0;
}

void criaArquivo(char *nome){ // É pra gerar um arquivo
	int i;
	FILE *f = fopen(nome,"w");
	srand(time(NULL));
	for(i = 1; i < M; i++){
		fprintf(f, "%d\n", rand());
	}
	fprintf(f, "%d", rand());
	fclose(f);
}

int criarArquivosOrdenados(char *nome){
	int V[N], K = 0, total = 0;
	char novo[20];
	FILE *f = fopen(nome, "r");
	while(!feof(f)){
		fscanf(f, "%d", &V[total]);
		total++;
		if(total == N){
			K++;
			sprintf(novo, "Temp%d.txt", K);
			quickSort(V, 0, N-1);
			salvaArquivo(novo, V, total, 0);
			total = 0;
		}
	}
	if(total > 0){
		K++;
		sprintf(novo,"Temp%d.txt", K);
		quickSort(V, 0, total);
		//quickSort(V, total, sizeof(int));
		//quickSort(V,total,sizeof(int),compara);
		salvaArquivo(novo, V, total, 0);
	}
	fclose(f);
	return K;	
}


void mergeSortExterno(char *nome){
	char novo[20];
	int K = criarArquivosOrdenados(nome);
	int i, T = N / (K + 1); //N = 100, e T é o tamanho dos buffers
	remove(nome);
	merge(nome, K, T); // K eh a quantidade de ordenações e K+1 a quantidade de buffers
	for(i = 0; i < K; i++)
	{	
		sprintf(novo,"Temp%d.txt", i + 1);
		remove(novo);
	}
}

void quickSort(int *V, int inicio, int fim) {
	int pivo;
	if(fim > inicio) {
		pivo = particiona(V, inicio, fim);
		quickSort(V, inicio, pivo - 1);
		quickSort(V, pivo  + 1, fim);
	}
}

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

int main(){
	if(N > M)
	{
		printf("\nErro: O numero de divisoes, precisa ser menor ou igual que o tamanho do vetor a ser criado\n");
		system("pause");
		return 400;
	}
	criaArquivo("dados.txt");
	mergeSortExterno("dados.txt"); // Chamando a função para ordenar o arquivo
	system("pause");
	return 0;
}


