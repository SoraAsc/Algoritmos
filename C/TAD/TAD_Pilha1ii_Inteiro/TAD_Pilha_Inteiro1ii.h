typedef struct stack Stack;

// Cria e devolve o endere�o da Pilha.
Stack* CreateStack();

// Verifica se a pilha est� vazia.
int EmptyStack(Stack* pilha);

// Verifica se a pilha est� cheia.
int FullStack(Stack * pilha);

// Retorna o tamanho atual da pilha.
int SizeStack(Stack* pilha);

// Adiciona um elemento(inteiro) no topo da Pilha.
void PushStack(Stack *pilha, int valor);

// Acessa e remove o valor no topo da Pilha.
int PopStack(Stack* pilha);

// Similar ao anterior, por�m s� acesso o valor no topo da pilha sem remov�-lo.
int PeekStack(Stack* pilha);

// Destroi/Apaga todos os endere�amentos da pilha junto com seus links/n�.
Stack* DestroyStack(Stack* pilha);

