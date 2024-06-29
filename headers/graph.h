#ifndef BUSCA_K_CAMINHOS_GRAFO_H
#define BUSCA_K_CAMINHOS_GRAFO_H

// Structure to represent a node in the graph
typedef struct No {
    int destino;
    int peso;
    struct No* proximo;
}No;

// Structure to represent the adjacency list
typedef struct Graph {
    int numDeVertices;
    struct No** head;
} Grafo;

// Function prototypes
struct No* createNode(int dest, int cost);
void addEdge(struct Graph* graph, int src, int dest, int cost);
void criaGrafoVazio(Grafo* grafo, int numDeVertices);
void imprimeGrafo(Grafo* grafo, int numDeVertices);
void populaGrafo(Grafo* grafo, int edges[][3], int m);
void liberaGrafo(Grafo* grafo);
#endif //BUSCA_K_CAMINHOS_GRAFO_H
