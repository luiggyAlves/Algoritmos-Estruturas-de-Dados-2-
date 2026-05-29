typedef struct NO* ArvAVL

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL* raiz);
int insere_ArvAVL(ArvAVL* raiz, int valorInserido);
int remove_ArvAVL(ArvAVL* raiz, int valorRemovido);
int estaVazia_ArvAVL(ArvAVL* raiz);
int altura_ArvAVL(ArvAVL* raiz);
int totalNO_ArvAVL(ArvAVL* raiz);
int consultaArvAVL(ArvAVL* raiz, int valorBuscado);
void preOrdem_ArvAVL(ArvAVL* raiz);
void posOrdem_ArvAVL(ArvAVL* raiz);
void emOrdem_ArvAVL (ArvAVL* raiz);

