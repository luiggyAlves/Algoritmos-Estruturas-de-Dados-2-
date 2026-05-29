// Estamos definido ArvBin como NO* ou seja, um ponteiro para NO*, pois quando fizermos ArvBin *raiz, já estaremos fazendo um ponteiro para ponteiro do NO, NO** indiretamente, permitindo editar diretamente o ponteiro raiz
// Precisamos que raiz seja do tipo NO**, pois ela aponta para um nó, e não é um em si, assim, quando quisermos aloca o primeiro nó, o objetivo será mudar para onde o raiz aponta, pois essa será nossa referencia de inicio, e não o conteudo do raiz em si, é o equivalente a se ter um tipoArv com um campo *raiz, só serve para guardar a referência para o primeiro nó
typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin *raiz, int valorInserido);
int remove_ArvBin(ArvBin *raiz, int valorRemovido);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, int valorBuscado);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);