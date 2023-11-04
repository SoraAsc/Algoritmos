#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "TAD_Heap.h"

typedef struct node 
{
	int prioridade; // Define o primeiro a sair, quanto maior a prioridade. (também é o valor)
	unsigned long ordemChegada; // Caso a prioridade de dois ou mais elementos sejam iguais, a ordem de chegada define quem sai primeiro, ou seja quem tem a ordem menor 
} Node;

struct heap
{
	int tamanho;
	int capacidadeAtual;
	Node* heapElementos;
	unsigned long contadorChegada; // Mantem um contador mostrando o ultimo a chegar
};

//const capacidadeInicial = 10;

Heap* createHeap(int currentCapacity)
{
	Heap* h;
	h = (Heap*) malloc(sizeof(Heap));
	if(h != NULL)
	{
		// Garantindo que a capacidade vai ser uma potencia de 2, ou seja uma arvore completa
		h->capacidadeAtual = (int) pow(2, ceil(log2(currentCapacity))) - 1;
		h->capacidadeAtual = h->capacidadeAtual <= 0 ? 1 : h->capacidadeAtual;
		
		h->heapElementos = (Node*) malloc(sizeof(Node) * h->capacidadeAtual);
		h->tamanho = 0;	
		h->contadorChegada = 1;
	} 
	return h;
}

Heap* buildHeap(int* array, int n)
{
	Heap* heap = createHeap(n);
	int i;
	for(i = 0; i < n; i++)	
		insertHeap(heap, &array[i]);
	return heap;
}

int parentIndex(int i)
{
	return (i - 1) / 2;
}

int leftChild(int i)
{
	return 2*i + 1;
}

int rightChild(int i)
{
	return 2*i + 2;
}

void trade(Node* noA, Node* noB)
{
	// Endereço continua o mesmo, só muda os valores.
	Node temp = *noA;
	*noA = *noB;
	*noB = temp;
}

float key(Node* no)
{
	// Limita o numero de casas decimais da prioridade para apenas 3.
	// 0.001 / ordem de chegada, garante que nao importa o numero, a ordem de chegada acabara sendo apenas um fator de desempate
	// para numeros com no maximo 3 casas decimais.
	return (int)(no->prioridade * 1000.0) / 1000.0 + (0.001 / no->ordemChegada);
}


// Verifica se o noA tem mais prioriedade que o no B
bool verificaMaiorPrioriedade(Node noA, Node noB)
{
//	if((noA.prioridade > noB.prioridade) || (noA.prioridade == noB.prioridade && noA.ordemChegada < noB.ordemChegada) ) return true;
	if(key(&noA) > key(&noB)) return true;
	return false;
}

bool reheapUp(Heap* heap, int novoNoIndex)
{
	Node* novoNo = &heap->heapElementos[novoNoIndex];
	Node* noPai = &heap->heapElementos[parentIndex(novoNoIndex)];
	if(verificaMaiorPrioriedade(*novoNo, *noPai))
	{
		trade(noPai, novoNo);
		reheapUp(heap, parentIndex(novoNoIndex));
	}
	return true;
}

// Heap - A estrutura heap
// i - O indice do elemento a ser trocado.
bool reheapDown(Heap* heap, int i)
{
	int indexFilhoEsq = leftChild(i);
	int indexFilhoDir = rightChild(i);
	int novoI = i;
	if(indexFilhoEsq < heap->tamanho && verificaMaiorPrioriedade(heap->heapElementos[indexFilhoEsq], heap->heapElementos[novoI]))
	{
		novoI = indexFilhoEsq;
	} 
	if(indexFilhoDir < heap->tamanho && verificaMaiorPrioriedade(heap->heapElementos[indexFilhoDir], heap->heapElementos[novoI]))
	{
		novoI = indexFilhoDir;
	}
	if(novoI != i)
	{
		trade(&heap->heapElementos[novoI], &heap->heapElementos[i]);
		reheapDown(heap, novoI);
	}
	return true;
}

bool insertHeap(Heap* heap, int* value)
{
	if(fullHeap(heap)) return false;
	
	int i = heap->tamanho;
	heap->heapElementos[i].prioridade = *value;
	heap->heapElementos[i].ordemChegada = heap->contadorChegada;
	heap->contadorChegada += 1;
	heap->tamanho++;
	return reheapUp(heap, i);
}

bool deleteHeap(Heap* heap, int* removedValue)
{
	if(emptyHeap(heap)) return false;
	*removedValue = heap->heapElementos[0].prioridade;
	heap->heapElementos[0] = heap->heapElementos[heap->tamanho - 1];
	heap->tamanho -= 1;
	return reheapDown(heap, 0);
}

bool peekHeap(Heap * heap, int* removedValue)
{
	if(emptyHeap(heap)) return false;
	*removedValue = heap->heapElementos[0].prioridade;
	return true;
}

void showHeap(Heap* heap)
{
	int i;
	printf("[");
	for(i = 0; i < heap->tamanho; i++)
		printf("%d_%lu%s", heap->heapElementos[i].prioridade,heap->heapElementos[i].ordemChegada, (heap->tamanho == i+1 ? "" : ", ") );
	printf("]");
}

bool freeHeap(Heap* heap)
{
	free(heap->heapElementos);
	free(heap);
}

int sizeHeap(Heap* heap)
{
	return heap->tamanho;
}

bool fullHeap(Heap* heap)
{
	return heap->capacidadeAtual == heap->tamanho ? true : false;
}

bool emptyHeap(Heap* heap)
{
	return heap->tamanho == 0 ? true : false;
}
