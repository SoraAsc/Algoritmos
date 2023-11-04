#include <stdbool.h>

typedef struct stack Stack;

Stack* Create_Stack();

bool Empty_Stack(Stack * pilha);

bool Full_Stack(Stack *pilha);

int Size_Stack(Stack* pilha);

void Push_Stack(Stack *pilha, int valor);

// Esse aqui acessa e remove o valor.
int Pop_Stack(Stack *pilha);

//// Esse aqui só acessa o valor.
int Peek_Stack(Stack *pilha);

void Destroy_Stack(Stack* pilha);





