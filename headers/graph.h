#ifndef BUSCA_K_CAMINHOS_GRAFO_H
#define BUSCA_K_CAMINHOS_GRAFO_H

typedef struct No {
    int destino;
    int peso;
    struct No* proximo;
}No;

typedef struct Grafo {
    int numDeVertices;
    struct No** head;
} Grafo;

struct No* criarNo(int destino, int peso);
void insereAresta(Grafo *grafo, int origem, int destino, int peso);
void criaGrafoVazio(Grafo* grafo, int numDeVertices);
void imprimeGrafo(Grafo* grafo, int numDeVertices);
void liberaGrafo(Grafo* grafo);
#endif //BUSCA_K_CAMINHOS_GRAFO_H
