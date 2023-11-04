#include <stdbool.h>

typedef struct node Node;
typedef struct heap Heap;

// Cria e devolve a Heap.
Heap* createHeap(int initialCapacity);

// Parecido com o create Heap, porém esse cria um Heap a partir de uma array
Heap* buildHeap(int* array, int n);

// Adiciona um elemento na heap. (true = adicionou | false - Nao)
bool insertHeap(Heap* heap, int* value);

// Remove o primeiro elemento da heap. (true = removou | false - Nao)
bool deleteHeap(Heap* heap, int* removedValue);

// Vê o elemento no topo da heap. (true = recuperou | false - Nao)
bool peekHeap(Heap* heap, int* removedValue);

// Mostra todos os elementos na heap, em forma de array.
void showHeap(Heap* heap);

// Retorna o tamanho atual do heap.
int sizeHeap(Heap* heap);

// Verifica se a heap está cheia. (true = cheia | false = Nao)
bool fullHeap(Heap* heap);

// Verifica se a heap está vazia. (true = vazia | false = Nao)
bool emptyHeap(Heap* heap);

// Limpa a heap da memória.
bool freeHeap(Heap* heap);

static bool reheapUp(Heap* heap, int index);

static bool reheapDown(Heap* heap, int index);
