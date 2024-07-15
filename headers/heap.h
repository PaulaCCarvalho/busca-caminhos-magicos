#ifndef BUSCA_K_CAMINHOS_MIN_HEAP_H
#define BUSCA_K_CAMINHOS_MIN_HEAP_H

typedef struct {
    int distancia;
    int vertice;
} FilaPrioridade;

typedef struct {
    FilaPrioridade* fila;
    int tamanho;
    int capacidade;
} Heap;

void criaHeap(Heap* heap, int capacidadeInicial);
void inserirMinHeap(Heap* heap, int distancia, int vertice);
FilaPrioridade extrairMinHeap(Heap* heap);
void ajustarMinHeap(Heap* heap, int indice);
void liberaHeap(Heap* heap);
#endif //BUSCA_K_CAMINHOS_MIN_HEAP_H
