typedef struct stack Stack;


// Cria e devolve o endereço da Pilha.
Stack* CreateStack();

// Verifica se a pilha está vazia.
int EmptyStack(Stack* pilha);

// Verifica se a pilha está cheia.
int FullStack(Stack * pilha);

// Retorna o tamanho atual da pilha.
int SizeStack(Stack* pilha);

// Adiciona um elemento no topo da Pilha.
void PushStack(Stack *pilha, void* valor);

// Acessa e remove o valor no topo da Pilha.
void* PopStack(Stack* pilha);

// Similar ao anterior, porém só acesso o valor no topo da pilha sem removê-lo.
void* PeekStack(Stack* pilha);

// Destroi/Apaga todos os endereçamentos da pilha junto com seus links/nó.
Stack* DestroyStack(Stack* pilha);


