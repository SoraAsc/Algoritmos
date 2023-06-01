#include <stdbool.h>

typedef struct queue Queue;

Queue* Create_Queue();

bool Empty_Queue(Queue * fila);

bool Full_Queue(Queue *fila);

int Size_Queue(Queue* fila);

void Enqueue(Queue *fila, int valor);

// Esse aqui acessa e remove o valor.
int Dequeue(Queue *fila);

//// Esse aqui só acessa o valor.
int Peek_Queue(Queue *fila);

//// Esse aqui só acessa o valor.
int Rear_Queue(Queue *fila);

void Destroy_Queue(Queue* fila);






