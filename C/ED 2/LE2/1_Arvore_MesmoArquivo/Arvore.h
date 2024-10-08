//�rvore de Busca Bin�ria
// o tipo �rvore bin�ria � definido como um ponteiro a uma estrutura n�.
typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin* raiz);
int insere_ArBin(ArvBin* raiz, int valor);
int remove_ArvBin(ArvBin* raiz, int valor);
int estaVazia_ArvBin(ArvBin* raiz);
int altura_ArvBin(ArvBin* raiz);
int totalNO_ArvBin(ArvBin* raiz);
int consulta_ArvBin(ArvBin* raiz, int valor);
void emOrdem_ArvBin(ArvBin* raiz);

//�rvore AVL
// o tipo �rvore bin�ria � definido como um ponteiro a uma estrutura n�.
typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL* raiz);
int insere_ArvAVL(ArvAVL* raiz, int valor);
int remove_ArvAVL(ArvAVL* raiz, int valor);
int estaVazia_ArvAVL(ArvAVL* raiz);
int altura_ArvAVL(ArvAVL* raiz);
int alt_NO(struct NO* no);
int totalNO_ArvAVL(ArvAVL* raiz);
int consulta_ArvAVL(ArvAVL* raiz, int valor);
void emOrdem_ArvAVL(ArvAVL* raiz);
void preOrdem_ArvAVL(ArvAVL* raiz);
static void preOrdem_ArvAVLRecursive(ArvAVL* raiz, int alturaArvore);
static void print_tab_spaces(int n);

