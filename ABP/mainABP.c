#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

int main(){

    int passou = 0;
    int falhou = 0;

    /* ══════════════════════════════════════════
       cria_ArvBin
       ══════════════════════════════════════════ */
    printf("\n=== cria_ArvBin ===\n");

    ArvBin* arvore = cria_ArvBin();

    if(arvore != NULL){
        printf("[OK] cria_ArvBin retorna um ponteiro valido\n");
        passou++;
    } else {
        printf("[FALHOU] cria_ArvBin retornou NULL\n");
        falhou++;
    }

    if(estaVazia_ArvBin(arvore) == 1){
        printf("[OK] arvore recem criada esta vazia\n");
        passou++;
    } else {
        printf("[FALHOU] arvore recem criada deveria estar vazia\n");
        falhou++;
    }

    if(altura_ArvBin(arvore) == 0){
        printf("[OK] altura da arvore vazia e 0\n");
        passou++;
    } else {
        printf("[FALHOU] altura da arvore vazia deveria ser 0\n");
        falhou++;
    }

    if(totalNO_ArvBin(arvore) == 0){
        printf("[OK] total de nos da arvore vazia e 0\n");
        passou++;
    } else {
        printf("[FALHOU] total de nos da arvore vazia deveria ser 0\n");
        falhou++;
    }

    libera_ArvBin(arvore);

    /* ══════════════════════════════════════════
       insere_ArvBin
       ══════════════════════════════════════════ */
    printf("\n=== insere_ArvBin ===\n");

    arvore = cria_ArvBin();

    int retorno = insere_ArvBin(arvore, 50);
    if(retorno == 1){
        printf("[OK] insere na arvore vazia e retorna 1\n");
        passou++;
    } else {
        printf("[FALHOU] inserir na arvore vazia deveria retornar 1\n");
        falhou++;
    }

    if(estaVazia_ArvBin(arvore) == 0){
        printf("[OK] arvore deixa de estar vazia apos insercao\n");
        passou++;
    } else {
        printf("[FALHOU] arvore nao deveria estar vazia apos insercao\n");
        falhou++;
    }

    retorno = insere_ArvBin(arvore, 30);
    if(retorno == 1){
        printf("[OK] insere elemento menor que a raiz e retorna 1\n");
        passou++;
    } else {
        printf("[FALHOU] inserir elemento menor deveria retornar 1\n");
        falhou++;
    }

    retorno = insere_ArvBin(arvore, 70);
    if(retorno == 1){
        printf("[OK] insere elemento maior que a raiz e retorna 1\n");
        passou++;
    } else {
        printf("[FALHOU] inserir elemento maior deveria retornar 1\n");
        falhou++;
    }

    retorno = insere_ArvBin(arvore, 50);
    if(retorno == 0){
        printf("[OK] inserir duplicata retorna 0\n");
        passou++;
    } else {
        printf("[FALHOU] inserir duplicata deveria retornar 0\n");
        falhou++;
    }

    if(totalNO_ArvBin(arvore) == 3){
        printf("[OK] total de nos nao aumenta com duplicata\n");
        passou++;
    } else {
        printf("[FALHOU] total de nos nao deveria ter aumentado com duplicata\n");
        falhou++;
    }

    insere_ArvBin(arvore, 20);
    insere_ArvBin(arvore, 40);
    insere_ArvBin(arvore, 60);
    insere_ArvBin(arvore, 80);

    if(totalNO_ArvBin(arvore) == 7){
        printf("[OK] total de nos correto apos 7 insercoes unicas\n");
        passou++;
    } else {
        printf("[FALHOU] total de nos deveria ser 7 apos 7 insercoes unicas\n");
        falhou++;
    }

    libera_ArvBin(arvore);

    /* ══════════════════════════════════════════
       consulta_ArvBin
       ══════════════════════════════════════════

       Arvore usada nos testes abaixo:

               50
              /  \
            30    70
           /  \  /  \
         20  40 60   80
    */
    printf("\n=== consulta_ArvBin ===\n");

    ArvBin* arvoreVazia = cria_ArvBin();
    if(consulta_ArvBin(arvoreVazia, 10) == 0){
        printf("[OK] busca em arvore vazia retorna 0\n");
        passou++;
    } else {
        printf("[FALHOU] busca em arvore vazia deveria retornar 0\n");
        falhou++;
    }
    libera_ArvBin(arvoreVazia);

    arvore = cria_ArvBin();
    insere_ArvBin(arvore, 50);
    insere_ArvBin(arvore, 30);
    insere_ArvBin(arvore, 70);
    insere_ArvBin(arvore, 20);
    insere_ArvBin(arvore, 40);
    insere_ArvBin(arvore, 60);
    insere_ArvBin(arvore, 80);

    if(consulta_ArvBin(arvore, 50) == 1){
        printf("[OK] encontra a raiz (50)\n");
        passou++;
    } else {
        printf("[FALHOU] deveria encontrar a raiz (50)\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 30) == 1){
        printf("[OK] encontra no a esquerda da raiz (30)\n");
        passou++;
    } else {
        printf("[FALHOU] deveria encontrar no a esquerda da raiz (30)\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 70) == 1){
        printf("[OK] encontra no a direita da raiz (70)\n");
        passou++;
    } else {
        printf("[FALHOU] deveria encontrar no a direita da raiz (70)\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 20) == 1){
        printf("[OK] encontra folha mais a esquerda (20)\n");
        passou++;
    } else {
        printf("[FALHOU] deveria encontrar folha mais a esquerda (20)\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 80) == 1){
        printf("[OK] encontra folha mais a direita (80)\n");
        passou++;
    } else {
        printf("[FALHOU] deveria encontrar folha mais a direita (80)\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 5) == 0){
        printf("[OK] nao encontra valor menor que o minimo (5)\n");
        passou++;
    } else {
        printf("[FALHOU] nao deveria encontrar valor ausente (5)\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 100) == 0){
        printf("[OK] nao encontra valor maior que o maximo (100)\n");
        passou++;
    } else {
        printf("[FALHOU] nao deveria encontrar valor ausente (100)\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 45) == 0){
        printf("[OK] nao encontra valor intermediario ausente (45)\n");
        passou++;
    } else {
        printf("[FALHOU] nao deveria encontrar valor intermediario ausente (45)\n");
        falhou++;
    }

    libera_ArvBin(arvore);

    /* ══════════════════════════════════════════
       remove_ArvBin
       ══════════════════════════════════════════ */
    printf("\n=== remove_ArvBin ===\n");

    /* Remocao em arvore vazia */
    arvoreVazia = cria_ArvBin();
    if(remove_ArvBin(arvoreVazia, 10) == 0){
        printf("[OK] remover em arvore vazia retorna 0\n");
        passou++;
    } else {
        printf("[FALHOU] remover em arvore vazia deveria retornar 0\n");
        falhou++;
    }
    libera_ArvBin(arvoreVazia);

    /* Remocao de elemento inexistente */
    arvore = cria_ArvBin();
    insere_ArvBin(arvore, 50);
    insere_ArvBin(arvore, 30);
    insere_ArvBin(arvore, 70);
    insere_ArvBin(arvore, 20);
    insere_ArvBin(arvore, 40);
    insere_ArvBin(arvore, 60);
    insere_ArvBin(arvore, 80);

    if(remove_ArvBin(arvore, 99) == 0){
        printf("[OK] remover elemento ausente retorna 0\n");
        passou++;
    } else {
        printf("[FALHOU] remover elemento ausente deveria retornar 0\n");
        falhou++;
    }

    if(totalNO_ArvBin(arvore) == 7){
        printf("[OK] total nao muda apos tentativa de remocao de elemento ausente\n");
        passou++;
    } else {
        printf("[FALHOU] total nao deveria mudar ao tentar remover elemento ausente\n");
        falhou++;
    }

    /* Remocao de no folha */
    retorno = remove_ArvBin(arvore, 20);
    if(retorno == 1){
        printf("[OK] remover no folha retorna 1\n");
        passou++;
    } else {
        printf("[FALHOU] remover no folha deveria retornar 1\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 20) == 0){
        printf("[OK] folha removida nao e mais encontrada\n");
        passou++;
    } else {
        printf("[FALHOU] folha removida nao deveria ser encontrada\n");
        falhou++;
    }

    if(totalNO_ArvBin(arvore) == 6){
        printf("[OK] total diminui para 6 apos remocao de folha\n");
        passou++;
    } else {
        printf("[FALHOU] total deveria ser 6 apos remocao de folha\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 30) == 1){
        printf("[OK] pai da folha removida permanece na arvore (30)\n");
        passou++;
    } else {
        printf("[FALHOU] pai da folha removida deveria permanecer na arvore (30)\n");
        falhou++;
    }

    libera_ArvBin(arvore);

    /* Remocao de no com apenas filho a direita */
    arvore = cria_ArvBin();
    insere_ArvBin(arvore, 50);
    insere_ArvBin(arvore, 30);
    insere_ArvBin(arvore, 40); /* 30 tem so filho a direita */

    retorno = remove_ArvBin(arvore, 30);
    if(retorno == 1){
        printf("[OK] remover no com filho so a direita retorna 1\n");
        passou++;
    } else {
        printf("[FALHOU] remover no com filho so a direita deveria retornar 1\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 30) == 0){
        printf("[OK] no removido nao e mais encontrado\n");
        passou++;
    } else {
        printf("[FALHOU] no removido nao deveria ser encontrado\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 40) == 1){
        printf("[OK] filho a direita permanece na arvore (40)\n");
        passou++;
    } else {
        printf("[FALHOU] filho a direita deveria permanecer na arvore (40)\n");
        falhou++;
    }

    libera_ArvBin(arvore);

    /* Remocao de no interno com dois filhos */
    arvore = cria_ArvBin();
    insere_ArvBin(arvore, 50);
    insere_ArvBin(arvore, 30);
    insere_ArvBin(arvore, 70);
    insere_ArvBin(arvore, 20);
    insere_ArvBin(arvore, 40);
    insere_ArvBin(arvore, 60);
    insere_ArvBin(arvore, 80);

    retorno = remove_ArvBin(arvore, 30);
    if(retorno == 1){
        printf("[OK] remover no interno com dois filhos retorna 1\n");
        passou++;
    } else {
        printf("[FALHOU] remover no interno com dois filhos deveria retornar 1\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 30) == 0){
        printf("[OK] no interno removido nao e mais encontrado (30)\n");
        passou++;
    } else {
        printf("[FALHOU] no interno removido nao deveria ser encontrado (30)\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 20) == 1 && consulta_ArvBin(arvore, 40) == 1){
        printf("[OK] filhos do no removido permanecem na arvore (20 e 40)\n");
        passou++;
    } else {
        printf("[FALHOU] filhos do no removido deveriam permanecer na arvore (20 e 40)\n");
        falhou++;
    }

    if(totalNO_ArvBin(arvore) == 6){
        printf("[OK] total reduz para 6 apos remocao de no interno\n");
        passou++;
    } else {
        printf("[FALHOU] total deveria ser 6 apos remocao de no interno\n");
        falhou++;
    }

    libera_ArvBin(arvore);

    /* Remocao da raiz */
    arvore = cria_ArvBin();
    insere_ArvBin(arvore, 50);
    insere_ArvBin(arvore, 30);
    insere_ArvBin(arvore, 70);
    insere_ArvBin(arvore, 20);
    insere_ArvBin(arvore, 40);
    insere_ArvBin(arvore, 60);
    insere_ArvBin(arvore, 80);

    retorno = remove_ArvBin(arvore, 50);
    if(retorno == 1){
        printf("[OK] remover a raiz retorna 1\n");
        passou++;
    } else {
        printf("[FALHOU] remover a raiz deveria retornar 1\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 50) == 0){
        printf("[OK] raiz removida nao e mais encontrada\n");
        passou++;
    } else {
        printf("[FALHOU] raiz removida nao deveria ser encontrada\n");
        falhou++;
    }

    if(totalNO_ArvBin(arvore) == 6){
        printf("[OK] arvore continua com 6 nos apos remocao da raiz\n");
        passou++;
    } else {
        printf("[FALHOU] arvore deveria ter 6 nos apos remocao da raiz\n");
        falhou++;
    }

    if(estaVazia_ArvBin(arvore) == 0){
        printf("[OK] arvore nao ficou vazia apos remocao da raiz\n");
        passou++;
    } else {
        printf("[FALHOU] arvore nao deveria ficar vazia apos remocao da raiz\n");
        falhou++;
    }

    libera_ArvBin(arvore);

    /* Remocao ate esvaziar */
    arvore = cria_ArvBin();
    insere_ArvBin(arvore, 10);
    remove_ArvBin(arvore, 10);

    if(estaVazia_ArvBin(arvore) == 1){
        printf("[OK] arvore fica vazia ao remover o unico elemento\n");
        passou++;
    } else {
        printf("[FALHOU] arvore deveria ficar vazia ao remover o unico elemento\n");
        falhou++;
    }

    libera_ArvBin(arvore);

    /* ══════════════════════════════════════════
       estaVazia_ArvBin
       ══════════════════════════════════════════ */
    printf("\n=== estaVazia_ArvBin ===\n");

    arvore = cria_ArvBin();

    if(estaVazia_ArvBin(arvore) == 1){
        printf("[OK] arvore recem criada esta vazia\n");
        passou++;
    } else {
        printf("[FALHOU] arvore recem criada deveria estar vazia\n");
        falhou++;
    }

    insere_ArvBin(arvore, 42);
    if(estaVazia_ArvBin(arvore) == 0){
        printf("[OK] arvore com elemento nao esta vazia\n");
        passou++;
    } else {
        printf("[FALHOU] arvore com elemento nao deveria estar vazia\n");
        falhou++;
    }

    remove_ArvBin(arvore, 42);
    if(estaVazia_ArvBin(arvore) == 1){
        printf("[OK] arvore volta a estar vazia apos remover o unico elemento\n");
        passou++;
    } else {
        printf("[FALHOU] arvore deveria voltar a estar vazia apos remover o unico elemento\n");
        falhou++;
    }

    libera_ArvBin(arvore);

    /* ══════════════════════════════════════════
       altura_ArvBin
       ══════════════════════════════════════════ */
    printf("\n=== altura_ArvBin ===\n");

    arvore = cria_ArvBin();

    if(altura_ArvBin(arvore) == 0){
        printf("[OK] altura de arvore vazia e 0\n");
        passou++;
    } else {
        printf("[FALHOU] altura de arvore vazia deveria ser 0\n");
        falhou++;
    }

    insere_ArvBin(arvore, 50);
    if(altura_ArvBin(arvore) == 1){
        printf("[OK] altura com so a raiz e 1\n");
        passou++;
    } else {
        printf("[FALHOU] altura com so a raiz deveria ser 1\n");
        falhou++;
    }

    insere_ArvBin(arvore, 30);
    if(altura_ArvBin(arvore) == 2){
        printf("[OK] altura com raiz e um filho e 2\n");
        passou++;
    } else {
        printf("[FALHOU] altura com raiz e um filho deveria ser 2\n");
        falhou++;
    }

    insere_ArvBin(arvore, 70);
    if(altura_ArvBin(arvore) == 2){
        printf("[OK] altura com raiz e dois filhos ainda e 2\n");
        passou++;
    } else {
        printf("[FALHOU] altura com raiz e dois filhos deveria ser 2\n");
        falhou++;
    }

    insere_ArvBin(arvore, 20);
    insere_ArvBin(arvore, 40);
    insere_ArvBin(arvore, 60);
    insere_ArvBin(arvore, 80);
    if(altura_ArvBin(arvore) == 3){
        printf("[OK] altura da arvore com 3 niveis e 3\n");
        passou++;
    } else {
        printf("[FALHOU] altura da arvore com 3 niveis deveria ser 3\n");
        falhou++;
    }

    libera_ArvBin(arvore);

    /* Arvore degenerada (todos inseridos em ordem crescente) */
    arvore = cria_ArvBin();
    insere_ArvBin(arvore, 10);
    insere_ArvBin(arvore, 20);
    insere_ArvBin(arvore, 30);
    insere_ArvBin(arvore, 40);

    if(altura_ArvBin(arvore) == 4){
        printf("[OK] altura de arvore degenerada com 4 nos e 4\n");
        passou++;
    } else {
        printf("[FALHOU] altura de arvore degenerada com 4 nos deveria ser 4\n");
        falhou++;
    }

    libera_ArvBin(arvore);

    /* ══════════════════════════════════════════
       totalNO_ArvBin
       ══════════════════════════════════════════ */
    printf("\n=== totalNO_ArvBin ===\n");

    arvore = cria_ArvBin();

    if(totalNO_ArvBin(arvore) == 0){
        printf("[OK] total de nos em arvore vazia e 0\n");
        passou++;
    } else {
        printf("[FALHOU] total de nos em arvore vazia deveria ser 0\n");
        falhou++;
    }

    insere_ArvBin(arvore, 50);
    if(totalNO_ArvBin(arvore) == 1){
        printf("[OK] total com 1 elemento e 1\n");
        passou++;
    } else {
        printf("[FALHOU] total com 1 elemento deveria ser 1\n");
        falhou++;
    }

    insere_ArvBin(arvore, 30);
    insere_ArvBin(arvore, 70);
    if(totalNO_ArvBin(arvore) == 3){
        printf("[OK] total com 3 elementos e 3\n");
        passou++;
    } else {
        printf("[FALHOU] total com 3 elementos deveria ser 3\n");
        falhou++;
    }

    insere_ArvBin(arvore, 20);
    insere_ArvBin(arvore, 40);
    insere_ArvBin(arvore, 60);
    insere_ArvBin(arvore, 80);
    if(totalNO_ArvBin(arvore) == 7){
        printf("[OK] total com 7 elementos e 7\n");
        passou++;
    } else {
        printf("[FALHOU] total com 7 elementos deveria ser 7\n");
        falhou++;
    }

    remove_ArvBin(arvore, 20);
    if(totalNO_ArvBin(arvore) == 6){
        printf("[OK] total diminui para 6 apos uma remocao\n");
        passou++;
    } else {
        printf("[FALHOU] total deveria diminuir para 6 apos uma remocao\n");
        falhou++;
    }

    libera_ArvBin(arvore);

    /* ══════════════════════════════════════════
       preOrdem_ArvBin / emOrdem_ArvBin / posOrdem_ArvBin

       Arvore:        50
                     /  \
                   30    70
                  /  \  /  \
                20  40 60   80

       preOrdem esperada : 50 30 20 40 70 60 80
       emOrdem esperada  : 20 30 40 50 60 70 80
       posOrdem esperada : 20 40 30 60 80 70 50
       ══════════════════════════════════════════ */
    printf("\n=== Percursos ===\n");

    arvore = cria_ArvBin();
    insere_ArvBin(arvore, 50);
    insere_ArvBin(arvore, 30);
    insere_ArvBin(arvore, 70);
    insere_ArvBin(arvore, 20);
    insere_ArvBin(arvore, 40);
    insere_ArvBin(arvore, 60);
    insere_ArvBin(arvore, 80);

    printf("preOrdem  (esperado: 50 30 20 40 70 60 80): ");
    preOrdem_ArvBin(arvore);

    printf("emOrdem   (esperado: 20 30 40 50 60 70 80): ");
    emOrdem_ArvBin(arvore);

    printf("posOrdem  (esperado: 20 40 30 60 80 70 50): ");
    posOrdem_ArvBin(arvore);

    libera_ArvBin(arvore);

    /* Percursos em arvore vazia nao devem travar */
    arvoreVazia = cria_ArvBin();
    preOrdem_ArvBin(arvoreVazia);
    emOrdem_ArvBin(arvoreVazia);
    posOrdem_ArvBin(arvoreVazia);
    printf("[OK] percursos em arvore vazia nao travam\n");
    passou++;
    libera_ArvBin(arvoreVazia);

    /* ══════════════════════════════════════════
       libera_ArvBin
       ══════════════════════════════════════════ */
    printf("\n=== libera_ArvBin ===\n");

    arvoreVazia = cria_ArvBin();
    libera_ArvBin(arvoreVazia);
    printf("[OK] liberar arvore vazia nao trava\n");
    passou++;

    arvore = cria_ArvBin();
    insere_ArvBin(arvore, 50);
    insere_ArvBin(arvore, 30);
    insere_ArvBin(arvore, 70);
    insere_ArvBin(arvore, 20);
    insere_ArvBin(arvore, 40);
    insere_ArvBin(arvore, 60);
    insere_ArvBin(arvore, 80);
    libera_ArvBin(arvore);
    printf("[OK] liberar arvore com varios nos nao trava\n");
    passou++;

    arvore = cria_ArvBin();
    insere_ArvBin(arvore, 50);
    insere_ArvBin(arvore, 30);
    insere_ArvBin(arvore, 70);
    insere_ArvBin(arvore, 20);
    insere_ArvBin(arvore, 40);
    insere_ArvBin(arvore, 60);
    insere_ArvBin(arvore, 80);
    remove_ArvBin(arvore, 20);
    remove_ArvBin(arvore, 50);
    libera_ArvBin(arvore);
    printf("[OK] liberar arvore parcialmente removida nao trava\n");
    passou++;

    /* ══════════════════════════════════════════
       Cenarios de borda
       ══════════════════════════════════════════ */
    printf("\n=== Cenarios de borda ===\n");

    /* Inserir e remover todos os elementos */
    arvore = cria_ArvBin();
    insere_ArvBin(arvore, 50);
    insere_ArvBin(arvore, 30);
    insere_ArvBin(arvore, 70);
    insere_ArvBin(arvore, 20);
    insere_ArvBin(arvore, 40);
    insere_ArvBin(arvore, 60);
    insere_ArvBin(arvore, 80);
    remove_ArvBin(arvore, 50);
    remove_ArvBin(arvore, 30);
    remove_ArvBin(arvore, 70);
    remove_ArvBin(arvore, 20);
    remove_ArvBin(arvore, 40);
    remove_ArvBin(arvore, 60);
    remove_ArvBin(arvore, 80);

    if(estaVazia_ArvBin(arvore) == 1){
        printf("[OK] arvore fica vazia apos remover todos os nos inseridos\n");
        passou++;
    } else {
        printf("[FALHOU] arvore deveria estar vazia apos remover todos os nos\n");
        falhou++;
    }

    libera_ArvBin(arvore);

    /* Arvore degenerada crescente */
    arvore = cria_ArvBin();
    insere_ArvBin(arvore, 1);
    insere_ArvBin(arvore, 2);
    insere_ArvBin(arvore, 3);
    insere_ArvBin(arvore, 4);
    insere_ArvBin(arvore, 5);

    if(totalNO_ArvBin(arvore) == 5){
        printf("[OK] total correto em arvore degenerada crescente (5)\n");
        passou++;
    } else {
        printf("[FALHOU] total deveria ser 5 em arvore degenerada crescente\n");
        falhou++;
    }

    if(altura_ArvBin(arvore) == 5){
        printf("[OK] altura correta em arvore degenerada crescente (5)\n");
        passou++;
    } else {
        printf("[FALHOU] altura deveria ser 5 em arvore degenerada crescente\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 3) == 1){
        printf("[OK] consulta funciona em arvore degenerada (valor presente: 3)\n");
        passou++;
    } else {
        printf("[FALHOU] deveria encontrar valor 3 em arvore degenerada\n");
        falhou++;
    }

    if(consulta_ArvBin(arvore, 9) == 0){
        printf("[OK] consulta funciona em arvore degenerada (valor ausente: 9)\n");
        passou++;
    } else {
        printf("[FALHOU] nao deveria encontrar valor 9 em arvore degenerada\n");
        falhou++;
    }

    libera_ArvBin(arvore);

    /* Insercoes repetidas do mesmo valor */
    arvore = cria_ArvBin();
    insere_ArvBin(arvore, 10);
    insere_ArvBin(arvore, 10);
    insere_ArvBin(arvore, 10);
    insere_ArvBin(arvore, 10);
    insere_ArvBin(arvore, 10);

    if(totalNO_ArvBin(arvore) == 1){
        printf("[OK] insercoes repetidas do mesmo valor nao aumentam o total\n");
        passou++;
    } else {
        printf("[FALHOU] total deveria ser 1 mesmo apos varias insercoes do mesmo valor\n");
        falhou++;
    }

    libera_ArvBin(arvore);

  
    printf("  Total : %d\n", passou + falhou);
    printf("  Passou: %d\n", passou);
    printf("  Falhou: %d\n", falhou);

    return (falhou == 0) ? 0 : 1;
}