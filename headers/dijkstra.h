#ifndef BUSCA_K_CAMINHOS_DIJKSTRA_K_SHORTEST_H
#define BUSCA_K_CAMINHOS_DIJKSTRA_K_SHORTEST_H

#include "graph.h"
#include "heap.h"

void inicializaDijkstra(int numDeVertices, int k);
void encontraKMenoresCaminhos(int numDeVertices, int k, Grafo* grafo, Heap* heap, char* arquivoSaida);
void imprimeKMenoresCaminhos(int numDeVertices, int k, char* arquivoSaida);
#endif //BUSCA_K_CAMINHOS_DIJKSTRA_K_SHORTEST_H
