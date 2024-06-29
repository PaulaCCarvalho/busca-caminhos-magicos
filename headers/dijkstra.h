#ifndef BUSCA_K_CAMINHOS_DIJKSTRA_K_SHORTEST_H
#define BUSCA_K_CAMINHOS_DIJKSTRA_K_SHORTEST_H

#include "grafo.h"
#include "min_heap.h"

void inicializaDijkstra(int n, int k);
void encontraKMenoresCaminhos(int n, int m, int k, Grafo* graph, Heap* heap,  char* outputFile);
void imprimeKMenoresCaminhos(int n, int k, char* outputFile);
#endif //BUSCA_K_CAMINHOS_DIJKSTRA_K_SHORTEST_H
