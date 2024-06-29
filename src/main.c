#include <stdio.h>
#include <stdlib.h>
#include "../headers/dijkstra_k_shortest.h"
#include <sys/resource.h>
#include <unistd.h>
#include <getopt.h>

int verticeOrigem, verticeDestino, peso;
const unsigned long LOTS = 50000000;
struct rusage start, end;
unsigned long i;
double diff;
int opt;
char *inputFile = NULL;
char *outputFile = NULL;
int numVertices = 0;
int numArestas = 0;
int k = 0;
int V1, V2, peso;

int main(int argc, char *argv[]) {
    // getrusage(RUSAGE_SELF, &start);

    // Processando os argumentos de linha de comando
    while ((opt = getopt(argc, argv, "i:o:")) != -1) {
        switch (opt) {
            case 'i':
                inputFile = optarg;
                break;
            case 'o':
                outputFile = optarg;
                break;
            default:
                fprintf(stderr, "Uso: %s -i <arquivo_entrada> -o <arquivo_saida>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Verificando se foram fornecidos arquivos de entrada e saída
    if (inputFile == NULL || outputFile == NULL) {
        fprintf(stderr, "Você deve fornecer tanto o arquivo de entrada quanto o arquivo de saída.\n");
        exit(EXIT_FAILURE);
    }

    // Abra o arquivo de entrada para leitura
    FILE *fp_in = fopen(inputFile, "r");
    if (fp_in == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo de entrada '%s'.\n", inputFile);
        exit(EXIT_FAILURE);
    }

    // Leitura dos três primeiros valores (número de vértices, número de arestas, k)
    fscanf(fp_in, "%d %d %d", &numVertices, &numArestas, &k);

    Grafo grafo;
    criaGrafoVazio(&grafo, numVertices);
    Heap heap;
    criaHeap(&heap, k);

    while (fscanf(fp_in, "%d %d %d", &V1, &V2, &peso) == 3) {
        addEdge(&grafo, V1, V2, peso);
    }

    // Fechar o arquivo de entrada após a leitura
    fclose(fp_in);

    // Abre o arquivo de saída para escrita
    FILE *fp_out = fopen(outputFile, "w");
    if (fp_out == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo de saída '%s'.\n", outputFile);
        exit(EXIT_FAILURE);
    }

    //imprimeGrafo(&grafo, numVertices);
    encontraKMenoresCaminhos(numVertices, numArestas, k, &grafo, &heap, outputFile);
//    imprimeGrafo(&grafo, numVertices);

    liberaGrafo(&grafo);
    liberaHeap(&heap);
    //getrusage(RUSAGE_SELF, &end);

    //diff = end.ru_utime.tv_sec+end.ru_utime.tv_usec*1e-6 -
    //      (start.ru_utime.tv_sec+start.ru_utime.tv_usec*1e-6);

    //printf("%lu of that took %f seconds (%f sec/act) to accomplish.\n",
    //       LOTS, diff, (diff/(double)LOTS));
    return 0;
}
