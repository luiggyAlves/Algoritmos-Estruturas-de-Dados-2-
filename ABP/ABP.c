#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

// Basicamente o tipo nó só guarda o seu dado (info) e os ponteiros para o seu filho da esquerda e da direita
struct NO{
    int info;
    struct NO* esq;
    struct NO* dir;
};

// Criando uma árvore binária
ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin)); // ArvBin* raiz aponta para um endereço de memória onde um ponteiro está armazenado, estamos alocando esse ponteiro nessa função
    if(raiz) *raiz = NULL; // fazemos o ponteiro que alocamos apontar para NULL
    return raiz;
}

// Destruindo uma árvore binária
    // Para liberar uma ABP precisamos percorrer toda ela e ir liberando a memória alocada começando do nó folha até o nó raiz, pois dessa forma nunca perderemos nenhuma referencia, isso é feito recursivamente , percorremos a árvore partindo da raiz até chegar no seu nó folha, ao chegar nele, a função retornará e liberará sua subárvore esquerda e direita e assim ocorrerá até a raiz, toda essa lógica é implementa pela função libera_NO, sendo a função libera_ArvBin responsável apenas por chamar a função libera_NO a partir da raiz e liberar a raiz ao final 
void libera_NO(struct NO* no){
    if(!no) return; 
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}
void libera_ArvBin(ArvBin* raiz){
    if(!raiz) return;
    libera_NO(*raiz);
    free(raiz);
}

// Inserindo um nó na árvore 
    // 1 - Alocar um novo nó 
    // 2.1 - Se a árvore estiver vazia(raiz aponta para NULL) o nó inserido vira Raiz
    // 2.2 - Se a árvore não estiver vaiza, percorrer a árvore a partir da raiz sempre seguindo as regras de inserção, se for menor vai pra esquerda, se for maior vai pra direita, repetimos isso até chegar em um nó folha, se for menor que o nó folha inserimos na esquerda, se for maior, inserimos na direita
int insere_ArvBin(ArvBin* raiz, int valorInserido){
    // Alocar um novo nó
    struct NO* novo = (struct NO*) malloc(sizeof(struct NO));
    novo->info = valorInserido;
    novo->esq = NULL;
    novo->dir = NULL;
    // Se a árvore estiver vazia, o nó inserido vira a raiz
    if(!raiz) *raiz = novo;
    // Se a árvore não estiver vazia, percorrer até encontrar o local de inserção
    else{
        struct NO* atual = *raiz; // nó atual será usado para percorrermos a árvore
        struct NO* ant = NULL; // nó ant será usado para guardarmos o pai do atual, que será muito útil quando formos inserir um elemento, uma vez que sempre será preciso saber o pai para inserir um elemento
        // Um nó folha não tem nenhum dos filhos, então percorreremos enquanto o nó atual possuir pelo menos um dos filhos
        while (atual != NULL){
            ant = atual;
            // Evitar que valores repetidos sejam inseridos
            if(valorInserido == atual->info){
                free(novo);
                return 0;
            }
            else if(novo->info > atual->info) atual = atual->dir;
            else atual = atual->esq;
        }
        if(novo->info>ant->info) ant->dir = novo;
        else ant->esq = novo;
    } 
    return 1;
}

// Removendo um nó da árvore
    // Consideravelmente mais complexo que inserir um nó na árvore, pois temos três casos distintos que precisamos cobrir 
        // 1 - O elemento a ser removido é um nó folha, nesse caso, a remoção é simples 
        // 2 - O elemento a ser removido é a raiz ou a árvore está vazia, a remoção também é simples 
        // 3 - O elemento a ser removido é um nó interno, assim, precisamos reconfigurar toda a árvore para que ela continue seguindo as restrições da árvore binária de pesquisa, nesse caso, a remoção é extremamente mais complexa que os anteriores 
    // Utilizaremos duas funções:
        // removeArvBin : procura o nó a ser removido e cobre o caso 2, quando o removido é a raiz ou a árvore está vazia;
        // remove_atual: cobre os casos 1 e 3, removendo nós folhas ou internos 

// Essa função recebe como parâmetro o ponteiro do nó da árvore que deve ser removido e indica qual deve ser seu substituto
struct NO* remove_atual(struct NO* atual){
    // Caso 1: O nó a ser removido (atual) não possui filho a esquerda
        // Nesse caso, a função substitui o nó atual pelo filho da direita: copia o nó atual para um nó auxiliar (no2), libera atual e retorna no2 como substituto. Com esse caso, tratamos nós folha (vira NULL) e nós que não possuem a subárvore à esquerda
    struct NO *no1, *no2;
    if(atual->esq == NULL) {
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    // Caso 2: O nó a ser removido possui os dois filhos 
        // Nesse caso, procuraremos o filho mais à direita da subárvore da esquerda, pois garantimos que ele é menor que ele é menor que todos os elementos da subárvore à direita do nó atual e maior que todos os elementos da subárvore à esquerda, dessa forma, conseguimos manter a mesma configuração
            // Para isso, utilizamos o no1 como pai do no2, no2 percorre até o elemento mais à direita da subárvore da esquerda 
        // Chegando no elemento mais à direita, se o pai dele for o atual, basta fazer a substituição direta das subárvores, se forem diferentes, no1 (o pai do elemento mais à direita) recebe como subarvore da esquerda, a subarvore esquerda de no2, no2 recebe as duas subarvores de atual, pois será seu substituto.
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }   
    if(no1!=atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
        no2->dir = atual->dir;
    
    // Por fim, a função libera atual e retorna no2 como seu substituto, a orquestração de linkar no2 ao pai de atual, será feita pela função remove_ArvBin
        free(atual);
        return no2;
}

int remove_ArvBin(ArvBin* raiz, int valorRemovido){
    if(!raiz) return 0; // Não tem como remover elementos de uma árvore vazia
    struct NO* ant = NULL;
    struct NO* atual = *raiz; // atual recebe o nó para o qual raiz aponta, pois ele irá percorrer, a partir da raiz, toda a árvore para encontrar o local de remoção
    while(atual!=NULL){
        // Encontrou o elemento que será removido
        if(valorRemovido == atual->info){
            // Se esse elemento for a raiz, removemos a raiz diretamente, sem usar o ant, pois a raiz não possui nenhum nó pai
            if(atual == *raiz) *raiz = remove_atual(atual);
            else{
                // se o elemento não for a raiz, verificamos se é o da direita ou da esquerda de ant e usamos a função remove_atual, pois precisamos fazer o link do nó substituido com o nó pai, que a função remove_atual não faz
                if(ant->dir == atual) ant->dir = remove_atual(atual);
                else ant->esq = remove_atual(atual);
            }
            return 1;
        }
        // Se ainda não encontrarmos o valor a ser removido, ant recebe atual, atual aplica as regras da ABP para verificar se deve ir para a direita ou esquerda e faz essa movimentação
        ant = atual;
        if(valorRemovido > atual->info) atual = atual->dir;
        else atual = atual->esq;
    }
    return 0;
}

// Buscando na árvore 
    // A busca é o processo mais simples, pois basta percorrer a árvore usando a lógica da ABP até se encontrar o elemento ou testificar-se que o elemento não está presente na árvore 
    int consulta_ArvBin(ArvBin *raiz, int valorBuscado){
        if(!raiz) return 0; // Não dá pra buscar numa árvore vazia
        struct NO* atual = *raiz;
        while(atual){
            if(valorBuscado==atual->info) return 1;
            else if(valorBuscado > atual->info) atual = atual->dir;
            else atual = atual->esq;
        }
        return 0;
    }


// Fornecendo informações básicas sobre a árvore
    // Verificaremos se uma árvore está vazia, a altura de uma árvore e o percurso da árvore (posOrdem, preOrdem ou emOrdem), que nos mostrará todos os elementos da árvore e também veremos quantos nós a árvore tem
int estaVaiza_ArvBin(ArvBin *raiz){
    if(!raiz) return 1; // Se raiz não foi iniciada, (o ponteiro para ponteiro não aponta para nada), a árvore está vazia
    if(!(*raiz)) return 1; // Se raiz foi iniciada, o ponteiro para ponteiro aponta para *raiz, mas *raiz não aponta para nada, a árvore está vazia
    return 0;  // Caso contrário, a árvore não está vazia
}

int totalNO_ArvBin(ArvBin *raiz){
    if(!raiz || !(*raiz)) return 0;// caso de parada, quando chegar num no folha
    // as chamadas recursivas descem ate encontrar um no folha, quando encontram um no folha, retornam um valor, que é atribuido às variaveis dos nós pais, esse processo é feito para cada nó, sempre passando +1 para o nó pai, com o intuito de contabilizar o nó, ao final temos a função que retorna a quantidade de nós da árvore
    int total_esq = totalNO_ArvBin(&((*raiz)->esq));
    int total_dir = totalNO_ArvBin(&((*raiz)->dir));
    return (total_esq + total_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if(!raiz || !(*raiz)) return 0;
    // Cada nó pai verifica a altura de suas subárvores, sempre retornando a maior, isso se repete até chegar à raiz, assim, teremos a altura da árvore, que é a quantidade de nós da maior subárvore da árvore
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if(alt_esq > alt_dir) return (alt_esq + 1);
    else return (alt_dir +1);
}

// Percorrendo a árvore binária;
    // pré ordem: visita a raiz, o filho da esquerda e o filho da direita, nessa ordem até chegar ao final: raiz fica no começo
    // em ordem: visita o filho da esquerda, a raiz e o filho da direita, sempre começando do nó folha mais à esquerda, devido à chamada recursiva, os elementos são mostrados na ordem estabelecida 
    // pós ordem: visita a esquerda, a direita e por fim a raiz, raiz aparece no "meio", considerando a árvore balanceada

void preOrdem_ArvBin(ArvBin* raiz){
    if(!raiz || !(*raiz)) return;
    printf("%d\n", (*raiz)->info);
    preOrdem_ArvBin(&((*raiz)->esq));
    preOrdem_ArvBin(&((*raiz)->dir));
}

void emOrdem_ArvBin(ArvBin* raiz){
    if(!raiz || !(*raiz)) return;
    emOrdem_ArvBin(&((*raiz)->esq));
    printf("%d\n", (*raiz)->info);
    emOrdem_ArvBin(&((*raiz)->dir));
}

void posOrdem_ArvBin(ArvBin* raiz){
    if(!raiz || !(*raiz)) return;
    posOrdem_ArvBin(&((*raiz)->esq));
    posOrdem_ArvBin(&((*raiz)->dir));
    printf("%d\n", (*raiz)->info);
}   