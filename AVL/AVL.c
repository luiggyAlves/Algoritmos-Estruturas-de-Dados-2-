#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
// Árvore AVL é uma árvore de busca binária balanceada
    // Como a busca da árvore binária descarta metade da subárvore a cada nó passado, a eficiência da busca em árvores binárias depende do balanceamento da árvore, uma árvore degenerada, por exemplo, em vez de ter custo O(logN) possui custo O(N), para resolver esse problema, precisamos balancear a árvore, ou seja, fazer com que a diferença das alturas da subárvore da direita para a subárvore da esquerda (chamada fator de balanceamento) seja de no máximo 1(1 ou -1) 
    // A AVL executa o balanceamento por meio de rotações (simples ou duplas) na árvore nos momentos de inserção ou remoção, o objetivo das rotações (e elas são acionadas mediante) é acertar o fator de balanceamento, assim, o calculo do fator de balanceamento deve ser realizado para cada nó da árvore
struct NO{
    int info;
    int alt; // dirá a altura da subárvore do nó, facilitará o processo
    struct NO* esq;
    struct NO* dir;
};

// Com exceção da inserção e remoção,onde o balanceamento ocorre, as outras funções são implementadas de forma identica à da ABP
ArvAVL* cria_ArvAVL()(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin)); 
    if(raiz) *raiz = NULL; 
    return raiz;
}

void libera_NO(struct NO* no){
    if(!no) return; 
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}
void libera_ArvAVL(ArvAVL* raiz){
    if(!raiz) return;
    libera_NO(*raiz);
    free(raiz);
}

int consultaArvAVL(ArvAVL* raiz, int valorBuscado){
    if(!raiz) return 0; // Não dá pra buscar numa árvore vazia
    struct NO* atual = *raiz;
    while(atual){
            if(valorBuscado==atual->info) return 1;
            else if(valorBuscado > atual->info) atual = atual->dir;
            else atual = atual->esq;
    }
    return 0;
    }

int estaVazia_ArvAVL(ArvAVL* raiz){
    if(!raiz) return 1; 
    if(!(*raiz)) return 1; 
    return 0;  
}

int totalNO_ArvBin(ArvBin *raiz){
    if(!raiz || !(*raiz)) return 0;
    int total_esq = totalNO_ArvBin(&((*raiz)->esq));
    int total_dir = totalNO_ArvBin(&((*raiz)->dir));
    return (total_esq + total_dir + 1);
}

int altura_ArvAVL(ArvAVL* raiz){
    if(!raiz || !(*raiz)) return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if(alt_esq > alt_dir) return (alt_esq + 1);
    else return (alt_dir +1);
}
void preOrdem_ArvAVL(ArvAVL* raiz){
    if(!raiz || !(*raiz)) return;
    printf("%d\n", (*raiz)->info);
    preOrdem_ArvBin(&((*raiz)->esq));
    preOrdem_ArvBin(&((*raiz)->dir));
}
void emOrdem_ArvAVL(ArvAVL* raiz){
    if(!raiz || !(*raiz)) return;
    emOrdem_ArvBin(&((*raiz)->esq));
    printf("%d\n", (*raiz)->info);
    emOrdem_ArvBin(&((*raiz)->dir));
}

void posOrdem_ArvAVL(ArvAVL* raiz){
    if(!raiz || !(*raiz)) return;
    posOrdem_ArvBin(&((*raiz)->esq));
    posOrdem_ArvBin(&((*raiz)->dir));
    printf("%d\n", (*raiz)->info);
}   
