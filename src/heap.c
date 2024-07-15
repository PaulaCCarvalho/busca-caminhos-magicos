#include "../headers/heap.h"
#include <stdio.h>
#include <stdlib.h>

void criaHeap(Heap* heap, int capacidadeInicial) {
    // Inicializa o heap com capacidade inicial
    heap->capacidade = capacidadeInicial;
    heap->fila = (Elemento *)malloc(capacidadeInicial * sizeof(Elemento));
    if (heap->fila == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para o heap.\n");
        exit(EXIT_FAILURE);
    }
    heap->tamanho = 0; // Inicializa o tamanho do heap como zero
}

void inserirMinHeap(Heap* heap, int distancia, int vertice) {
    if (heap->tamanho == heap->capacidade) {
        // Redimensiona o heap para o dobro da capacidade atual
        heap->capacidade *= 2;
        heap->fila = (Elemento *)realloc(heap->fila, heap->capacidade * sizeof(Elemento));
        if (heap->fila == NULL) {
            fprintf(stderr, "Erro: Falha ao realocar memória para o heap.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Insere o novo elemento no final do heap
    heap->fila[heap->tamanho].distancia = distancia;
    heap->fila[heap->tamanho].vertice = vertice;
    heap->tamanho++;

    // Ajusta o heap mínimo
    int idx = heap->tamanho - 1;
    ajustarMinHeap(heap, idx);
}

Elemento extrairMinHeap(Heap* heap) {
    Elemento menorElemento = heap->fila[0];
    heap->fila[0] = heap->fila[heap->tamanho - 1];
    heap->tamanho--;

    // Reduz o tamanho do heap se estiver muito grande
   if (heap->tamanho > 0 && heap->tamanho <= heap->capacidade / 4) {
        heap->capacidade /= 2;
        heap->fila = (FilaPrioridade *)realloc(heap->fila, heap->capacidade * sizeof(FilaPrioridade));
        if (heap->fila == NULL) {
            fprintf(stderr, "Erro: Falha ao realocar memória para o heap.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Executa o ajuste de heap mínimo a partir da raiz
    ajustarMinHeap(heap, 0);

    return menorElemento;
}

void ajustarMinHeap(Heap *heap, int indice) {
    while (1) {
        int esquerda = 2 * indice + 1;
        int direita = 2 * indice + 2;
        int menor = indice;
        if (esquerda < heap->tamanho && heap->fila[esquerda].distancia < heap->fila[menor].distancia)
            menor = esquerda;
        if (direita < heap->tamanho && heap->fila[direita].distancia < heap->fila[menor].distancia)
            menor = direita;
        if (menor != indice) {
            // Troca os elementos
            Elemento tmp = heap->fila[indice];
            heap->fila[indice] = heap->fila[menor];
            heap->fila[menor] = tmp;
            indice = menor;
        } else break;
    }
}

void liberaHeap(Heap* heap) {
    // Libera a memória alocada para o heap
    free(heap->fila);
    heap->fila = NULL;
    heap->tamanho = 0;
    heap->capacidade = 0;
}
