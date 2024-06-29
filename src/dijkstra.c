#include "../headers/dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int **distancias;

// Função para comparar dois pares para ordenação no heap mínimo
int comparaPares(const void* a, const void* b) {
    return ((Par*)a)->primeiro - ((Par*)b)->primeiro;
}

// Função para encontrar os k menores caminhos usando Dijkstra
void encontraKMenoresCaminhos(int n, int m, int k, Grafo* graph, Heap* heap, char* outputFile) {
    // Inicialização das estruturas
    distancias = (int **)malloc((n + 1) * sizeof(int *));
    if (distancias == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para distancias.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i <= n; i++) {
        distancias[i] = (int *)malloc(k * sizeof(int));
        if (distancias[i] == NULL) {
            fprintf(stderr, "Erro: Falha ao alocar memória para distancias[%d].\n", i);
            exit(EXIT_FAILURE);
        }
        for (int j = 0; j < k; j++) {
            distancias[i][j] = INT_MAX; // Inicializar com valor máximo
        }
    }

    // Inicialização da fila de prioridade (heap mínimo)
    insertMinHeap(heap, 0, 1); // Inserir nó inicial com distância 0
    distancias[1][0] = 0;

    // Processamento do algoritmo de Dijkstra
    while (heap->pqSize > 0) {
        Par minPair = extractMinHeap(heap);
        int u = minPair.segundo;
        int d = minPair.primeiro;

        if (distancias[u][k - 1] < d) continue;

        struct No *iter = graph->head[u];
        while (iter != NULL) {
            int dest = iter->destino;
            int cost = iter->peso;

            if (distancias[dest] == NULL) {
                distancias[dest] = (int *)malloc(k * sizeof(int));
                if (distancias[dest] == NULL) {
                    fprintf(stderr, "Erro: Falha ao alocar memória para distancias[%d].\n", dest);
                    exit(EXIT_FAILURE);
                }
                for (int j = 0; j < k; j++) {
                    distancias[dest][j] = INT_MAX; // Inicializar com valor máximo
                }
            }

            if (d + cost < distancias[dest][k - 1]) {
                distancias[dest][k - 1] = d + cost;

                // Ordenar as k menores distâncias do vértice dest
                qsort(distancias[dest], k, sizeof(int), comparaPares);

                if (heap->pqSize < n * k) {
                    insertMinHeap(heap, d + cost, dest);
                }
            }
            iter = iter->proximo;
        }
    }

    // Escrever as k menores distâncias no arquivo de saída
    FILE *fp_out = fopen(outputFile, "w");
    if (fp_out == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo de saída '%s'.\n", outputFile);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < k; i++) {
        fprintf(fp_out, "%d ", distancias[n][i]);
        printf("%d ", distancias[n][i]);
    }
    fprintf(fp_out, "\n");

    fclose(fp_out);
    printf("Dados processados e salvos em '%s'.\n", outputFile);

    // Liberação de memória
    for (int i = 1; i <= n; i++) {
        free(distancias[i]);
    }
    free(distancias);
}
