#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

// Basicamente o tipo nó só guarda o seu dado (info) e os ponteiros para o seu filho da esquerda e da direita
struct NO{
    int info;
    struct NO* esq;
    struct NO* dir;
}

// Criando uma árvore binária
ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin)); // ArvBin* raiz aponta para um endereço de memória onde um ponteiro está armazenado, estamos alocando esse ponteiro nessa função
    if(raiz) *raiz = NULL; // fazemos o ponteiro que alocamos apontar para NULL
    return raiz;
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
        else ant->esq = novo

    } 
    return 1;

}