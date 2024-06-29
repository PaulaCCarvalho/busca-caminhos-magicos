#ifndef BUSCA_K_CAMINHOS_MIN_HEAP_H
#define BUSCA_K_CAMINHOS_MIN_HEAP_H
// Structure to represent a pair of integers
typedef struct {
    int primeiro;
    int segundo;
} Par;

typedef struct {
    Par* pq;
    int pqSize;
    int capacity;
} Heap;

void criaHeap(Heap* heap, int initialCapacity);
void insertMinHeap(Heap* heap, int distance, int node);
Par extractMinHeap(Heap* heap);
void minHeapify(Heap* heap, int idx);
void liberaHeap(Heap* heap);
#endif //BUSCA_K_CAMINHOS_MIN_HEAP_H
