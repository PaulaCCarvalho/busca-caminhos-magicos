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


// Function to create a new node
struct No* createNode(int dest, int cost) {
    struct No* newNode = (struct No*)malloc(sizeof(struct No));
    newNode->destino = dest;
    newNode->peso = cost;
    newNode->proximo = NULL;
    return newNode;
}

void addEdge(Grafo* grafo, int src, int dest, int cost) {
    // Criar um novo nó
    struct No* newNode = (struct No*)malloc(sizeof(struct No));
    newNode->destino = dest;
    newNode->peso = cost;
    newNode->proximo = NULL;

    // Inserir o novo nó no início da lista de adjacência de src
    if (grafo->head[src] == NULL) {
        grafo->head[src] = newNode;
    } else {
        newNode->proximo = grafo->head[src];
        grafo->head[src] = newNode;
    }
}


void imprimeGrafo(Grafo* grafo, int numDeVertices) {
    for (int i = 1; i <= numDeVertices; i++) {
        printf("Vértice %d: ", i);
        struct No* curr = grafo->head[i];
        while (curr != NULL) {
            printf("%d (%d) -> ", curr->destino, curr->peso);
            curr = curr->proximo;
        }
        printf("\n");
    }
}

void populaGrafo(Grafo* grafo, int edges[][3], int m) {
// Storing edges
    for (int i = 0; i < m; i++) {
        addEdge(grafo, edges[i][0], edges[i][1], edges[i][2]);
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