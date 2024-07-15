#include <stdio.h>
#include <stdlib.h>
#include "../headers/dijkstra.h"
#include <sys/resource.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    char *arquivoEntrada = NULL, *arquivoSaida = NULL;
    int opt, V1, V2, peso, k= 0, numVertices =0, numArestas = 0;
    struct rusage r_usage;
    struct timeval inicioRelogio, finalRelogio;
    struct timeval inicioCPU, finalCPU;

    // Pega o tempo de relógio no início
    gettimeofday(&inicioRelogio, NULL);

    // Pega o tempo de CPU no início
    getrusage(RUSAGE_SELF, &r_usage);
    inicioCPU = r_usage.ru_utime;

    //Inicio da execução do programa

    // Processando os argumentos de linha de comando
    while ((opt = getopt(argc, argv, "i:o:")) != -1) {
        switch (opt) {
            case 'i':
                arquivoEntrada = optarg;
                break;
            case 'o':
                arquivoSaida = optarg;
                break;
            default:
                fprintf(stderr, "Uso: %s -i <arquivo_entrada> -o <arquivo_saida>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Verificando se foram fornecidos arquivos de entrada e saída
    if (arquivoEntrada == NULL || arquivoSaida == NULL) {
        fprintf(stderr, "Você deve fornecer tanto o arquivo de entrada quanto o arquivo de saída.\n");
        exit(EXIT_FAILURE);
    }

    // Abra o arquivo de entrada para leitura
    FILE *fp_in = fopen(arquivoEntrada, "r");
    if (fp_in == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo de entrada '%s'.\n", arquivoEntrada);
        exit(EXIT_FAILURE);
    }

    // Leitura dos três primeiros valores (número de vértices, número de arestas, k)
    fscanf(fp_in, "%d %d %d", &numVertices, &numArestas, &k);

    Grafo grafo;
    criaGrafoVazio(&grafo, numVertices);
    Heap heap;
    criaHeap(&heap, k);

    while (fscanf(fp_in, "%d %d %d", &V1, &V2, &peso) == 3) {
        insereAresta(&grafo, V1, V2, peso);
    }

    // Fechar o arquivo de entrada após a leitura
    fclose(fp_in);

    imprimeGrafo(&grafo, numVertices);
    // Abre o arquivo de saída para escrita
    FILE *fp_out = fopen(arquivoSaida, "w");
    if (fp_out == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo de saída '%s'.\n", arquivoSaida);
        exit(EXIT_FAILURE);
    }

    encontraKMenoresCaminhos(numVertices, k, &grafo, &heap, arquivoSaida);

    //Libera estruturas alocadas
    liberaGrafo(&grafo);
    liberaHeap(&heap);

    /* Final da execução */
    // Pega o tempo de relógio no final
    gettimeofday(&finalRelogio, NULL);

    // Pega o tempo de CPU no final
    getrusage(RUSAGE_SELF, &r_usage);
    finalCPU = r_usage.ru_utime;

    // Calcula a diferença de tempo de relógio em segundos e microsegundos
    double wall_time_used = (finalRelogio.tv_sec - inicioRelogio.tv_sec) + (finalRelogio.tv_usec - inicioRelogio.tv_usec) / 1e6;

    // Calcula a diferença de tempo de CPU em segundos e microsegundos
    double cpu_time_used = (finalCPU.tv_sec - inicioCPU.tv_sec) + (finalCPU.tv_usec - inicioCPU.tv_usec) / 1e6;

    printf("Tempo de relógio: %f segundos\n", wall_time_used);
    printf("Tempo de CPU: %f segundos\n", cpu_time_used);

    return 0;
}
