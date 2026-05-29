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
