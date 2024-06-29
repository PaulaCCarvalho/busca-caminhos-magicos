#include "../headers/min_heap.h"
#include <stdio.h>
#include <stdlib.h>

void criaHeap(Heap* heap, int initialCapacity) {
    // Inicializa o heap com capacidade inicial
    heap->capacity = initialCapacity;
    heap->pq = (Par *)malloc(initialCapacity * sizeof(Par));
    if (heap->pq == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para o heap.\n");
        exit(EXIT_FAILURE);
    }
    heap->pqSize = 0; // Inicializa o tamanho do heap como zero
}

void insertMinHeap(Heap* heap, int distance, int node) {
    // Verifica se há espaço suficiente no heap
    if (heap->pqSize == heap->capacity) {
        // Redimensiona o heap para o dobro da capacidade atual
        heap->capacity *= 2;
        heap->pq = (Par *)realloc(heap->pq, heap->capacity * sizeof(Par));
        if (heap->pq == NULL) {
            fprintf(stderr, "Erro: Falha ao realocar memória para o heap.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Insere o novo elemento no final do heap
    heap->pq[heap->pqSize].primeiro = distance;
    heap->pq[heap->pqSize].segundo = node;
    heap->pqSize++;

    // Ajusta o heap mínimo
    int idx = heap->pqSize - 1;
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap->pq[parent].primeiro > heap->pq[idx].primeiro) {
            // Troca os elementos
            Par tmp = heap->pq[parent];
            heap->pq[parent] = heap->pq[idx];
            heap->pq[idx] = tmp;
            idx = parent;
        } else break;
    }
}

Par extractMinHeap(Heap* heap) {
    Par minElement = heap->pq[0];
    heap->pq[0] = heap->pq[heap->pqSize - 1];
    heap->pqSize--;

    // Reduz o tamanho do heap se estiver muito grande
    if (heap->pqSize > 0 && heap->pqSize <= heap->capacity / 4) {
        heap->capacity /= 2;
        heap->pq = (Par *)realloc(heap->pq, heap->capacity * sizeof(Par));
        if (heap->pq == NULL) {
            fprintf(stderr, "Erro: Falha ao realocar memória para o heap.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Executa o ajuste de heap mínimo a partir da raiz
    minHeapify(heap, 0);

    return minElement;
}

void minHeapify(Heap *heap, int idx) {
    while (1) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;
        if (left < heap->pqSize && heap->pq[left].primeiro < heap->pq[smallest].primeiro)
            smallest = left;
        if (right < heap->pqSize && heap->pq[right].primeiro < heap->pq[smallest].primeiro)
            smallest = right;
        if (smallest != idx) {
            // Troca os elementos
            Par tmp = heap->pq[idx];
            heap->pq[idx] = heap->pq[smallest];
            heap->pq[smallest] = tmp;
            idx = smallest;
        } else break;
    }
}

void liberaHeap(Heap* heap) {
    // Libera a memória alocada para o heap
    free(heap->pq);
    heap->pq = NULL;
    heap->pqSize = 0;
    heap->capacity = 0;
}
