#include "../headers/graph.h"
#include <stdio.h>
#include <stdlib.h>

void criaGrafoVazio(Grafo* grafo, int numDeVertices) {
    grafo->numDeVertices = numDeVertices;
    grafo->head = (struct No**)calloc(numDeVertices + 1, sizeof(struct No*));
    if (grafo->head == NULL) {
        printf("Erro: Memória insuficiente para criar o grafo.\n");
        exit(EXIT_FAILURE);
    }
}


struct No* criarNo(int destino, int peso) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->destino = destino;
    novoNo->peso = peso;
    novoNo->proximo = NULL;
    return novoNo;
}

void insereAresta(Grafo* grafo, int origem, int destino, int peso) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->destino = destino;
    novoNo->peso = peso;
    novoNo->proximo = NULL;

    // Inserir o novo nó no início da lista de adjacência de origem
    if (grafo->head[origem] == NULL) {
        grafo->head[origem] = novoNo;
    } else {
        novoNo->proximo = grafo->head[origem];
        grafo->head[origem] = novoNo;
    }
}


void imprimeGrafo(Grafo* grafo, int numDeVertices) {
    for (int i = 1; i <= numDeVertices; i++) {
        printf("Vértice %d: ", i);
        struct No* atual = grafo->head[i];
        while (atual != NULL) {
            printf("%d (%d) -> ", atual->destino, atual->peso);
            atual = atual->proximo;
        }
        printf("\n");
    }
}

void liberaGrafo(Grafo* grafo) {
    for (int i = 1; i <= grafo->numDeVertices; i++) {
        struct No* atual = grafo->head[i];
        while (atual != NULL) {
            struct No* proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }
    free(grafo->head);
    grafo->head = NULL;
}