#include "../headers/dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Função para comparar dois pares para ordenação no heap mínimo
int comparaPares(const void* a, const void* b) {
    return ((Elemento*)a)->distancia - ((Elemento*)b)->distancia;
}

void imprimeKMenoresCaminhos(int **distancias, int numDeVertices, int k, char* arquivoSaida) {
    // Escrever as k menores distâncias no arquivo de saída
    FILE *fp_out = fopen(arquivoSaida, "w");
    if (fp_out == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo de saída '%s'.\n", arquivoSaida);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < k; i++) {
        fprintf(fp_out, "%d ", distancias[numDeVertices][i]);
        printf("%d ", distancias[numDeVertices][i]);
    }
    fprintf(fp_out, "\n");

    fclose(fp_out);
    printf("Dados processados e salvos em '%s'.\n", arquivoSaida);
}

// Função para encontrar os k menores caminhos usando Dijkstra
void encontraKMenoresCaminhos(int numDeVertices, int k, Grafo* grafo, Heap* heap, char* arquivoSaida) {
    int **distancias;
    // Inicialização das estruturas
    distancias = (int **)malloc((numDeVertices + 1) * sizeof(int *));
    if (distancias == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para distancias.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i <= numDeVertices; i++) {
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
    inserirMinHeap(heap, 0, 1); // Inserir nó inicial com distância 0
    distancias[1][0] = 0;

    // Processamento do algoritmo de Dijkstra
    while (heap->tamanho > 0) {
        Elemento menorElemento = extrairMinHeap(heap);
        int u = menorElemento.vertice;
        int d = menorElemento.distancia;

        if (distancias[u][k - 1] < d) continue;

        struct No *atual = grafo->head[u];
        while (atual != NULL) {
                int destino = atual->destino;
                int peso = atual->peso;

                if (distancias[destino] == NULL) {
                    distancias[destino] = (int *) malloc(k * sizeof(int));
                    if (distancias[destino] == NULL) {
                        fprintf(stderr, "Erro: Falha ao alocar memória para distancias[%d].\n", destino);
                        exit(EXIT_FAILURE);
                    }
                    for (int j = 0; j < k; j++) {
                        distancias[destino][j] = INT_MAX; // Inicializar com valor máximo
                    }
                }

                if (d + peso < distancias[destino][k - 1]) {
                    distancias[destino][k - 1] = d + peso;

                    // Ordenar as k menores distâncias do vértice destino
                    qsort(distancias[destino], k, sizeof(int), comparaPares);

                    if (heap->tamanho < numDeVertices * k) {
                        inserirMinHeap(heap, d + peso, destino);
                    }
                }

                atual = atual->proximo;
        }
    }

    imprimeKMenoresCaminhos(distancias, numDeVertices, k, arquivoSaida);

    // Liberação de memória
    for (int i = 1; i <= numDeVertices; i++) {
        free(distancias[i]);
    }
    free(distancias);
}


