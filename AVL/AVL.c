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

// Funções auxiliares: serão usadas para agilizar a tarefa do cálculo de balanceamento de uma árvore

// retornar a altura de uma subárvore, considerando o nó dado como a raiz
int alt_NO(struct NO* no){
    if(!no) return -1
    return no->alt;
}

// retornar o fator de balanceamento de um nó
int fatorBalanceamento_NO(struct NO* no){
    return alt_NO(no->esq) - alt_NO(no->dir);
}

// retornar o maior dentre dois valores
int maior(int x, int y){
    if (x>y) return x;
    return y;
}


// ROTAÇÕES
    // Rotações simples ocorrem quando o nó pai desbalanceado, seu filho e seu neto estão no mesmo sentido de inclinação (são todos nós da subárvore da direita, por exemplo)
    // Rotações duplas ocorrem quando o nó pai desbalanceado e seu filho, estão inclinados no sentido inverso ao neto (o pai e filho são da subárvore da direita e o neto é de alguma subárvore esquerda, por exemplo), fazer uma rotação dupla é equivalente a fazer duas rotações simples 
    // As rotações são aplicadas no ancestral mais próximo do nó inserido cujo fator passou a -2 ou +2
    // Como todas as funções de rotação apenas atualizam ponteiros, a complexidade de todas é O(1)

// Rotação LL ou rotação simples à direita 
    // Ocorre quando um novo nó é inserido (chamaremos de C) na subárvore da esquerda do filho esquerdo do nó A (nó qualquer), que passa a ficar desbalanceado, precisamos fazer uma rotação à direita para balancear, o filho de A, nó intermediário B, passará a ocupar a posição de A, assim, A se torna a subárvore direita de B e a árvore volta a ficar balanceada

void RotacaoLL(ArvAVL *A){
    struct NO* B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    // A altura de A, quantidade de "degraus" de nós descendentes que ele tem, é a maior quantidade de descendentes de seus filhos + 1, pois conta a própria árvore
    (*A)->alt = maior(altura_NO((*A)->esq), altura_NO((*A)->dir))+1;
    // A altura de B, quantidade de "degraus" de nós descendentes que ele tem é igual à altura da maior de suas subárvores + 1, pois conta o próprio Nó B;
    B->alt = maior(altura_NO(B->esq), (*A)->alt)+1;
    *A=B; 
}

// Rotação RR ou rotação simples à esquerda
    // Semelhantemente à rotação simples à direita (LL), a rotação simples à esquerda ocorre quando algum nó C é inserido na subárvore da direita de outro nó, que o torna desbalanceado (chamaremos o nó desbalanceado de A), assim, o nó intermediário B vira a "raiz", sendo C sua subárvore da direita e A sua subárvore da esquerda
    // Note que no caso das duas rotações simples, os nós A, B e C ficam como se fosse uma lista, ou inclinada para a direita, ou inclinada para a esquerda
    // rotação, basicamente a subarvore da direia de A vira a subarvore da esquerda de B, porque garantidamente é maior que A, por estar na subárvore direita de A, a subarvore esquerda de B vira A. Assim, B ocupa a posição intermediária, fazendo o balanceamento, onde sua subárvore direita é C e sua subárvore esquerda é A
void RotacaoRR(ArvAVL* A){
    struct NO* B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->alt = maior(alturaNO((*A)->esq), alturaNO((*A)->dir))+1;
    B->alt = maior(alturaNO(B->dir), (*A)->alt);
    (*A) = B;
}


// ROTAÇÃO LR ou rotação dupla à direita
    // Ocorre quando um novo nó C é inserido na subárvore direita do filho esquerdo de A (chamaremos de B), sendo A o nó desbalanceado, fica como se fosse um ziguezague, por isso, precisamos fazer uma rotação dupla. Ao fazer a primeira rotação (RR), considerando B como o desbalanceado, B vira subárvore esquerda de C. Ao fazer a segunda rotação, considerando A como o desbalanceado (LL), A vira subárvore direita de C
    // A rotação dupla pode ser implementada simplesmente com duas chamadas para rotações simples
void RotacaoLR(ArvAVL* A){
    RotacaoRR(&(A*)->esq);
    RotacaoLL(A);
}

// Rotação RL ou rotação dupla à esquerda
    // Ocorre quando o novo nó é inserido na subárvore da esquerda do filho direito de A, também fica um ziguezague, so que invertido, como se fosse um angulo inferior a 90 graus
    // Nesse caso, o nó C (inserido ou cujo filho foi inserido) passa a ter como filho da esquerda o nó A e como filho da direita o nó B, pois primeiro ocorre uma rotação LL em A, fazendo B virar o filho à direita de C e depois uma RR em A, fazendo A virar filho à esquerda de C
void RotacaoLR(ArvAVL* A){
    RotacaoLL(&(A*)->dir);
    RotacaoRR(A);
}

