#include <stdio.h>
#include "graph.c"
#include "heap.c"

// Define a struct to store path information
typedef struct Path {
    TipoValorVertice vertices[MAXNUMVERTICES]; // Array to store path vertices
    int length; // Path length
    TipoPeso weight; // Path weight
} Path;

TipoApontador Aux;
TipoValorVertice V1, V2, Adj;
TipoPeso Peso;
TipoGrafo Grafo;
TipoValorVertice NVertices;
short NArestas;
int k;
TipoValorVertice Raiz, Luminae;
TipoPeso PesoMinimo;


// Function to print a path
void printPath(Path* path) {
    printf("Path: ");
    for (int i = 0; i < path->length; i++) {
        printf("%d ", path->vertices[i] + 1); // Print vertex numbers (1-based)
    }
    printf("Weight: %d\n", path->weight);
}

// Function to reconstruct the path from a vertex to the source using predecessor information
void ReconstructPath(TipoValorVertice u, long Antecessor[], Path* path) {
    if (u == -1) {
        return;
    }
    // Recursively reconstruct the path from the predecessor
    ReconstructPath(Antecessor[u], Antecessor, path);
    // Add the current vertex to the path
    path->vertices[path->length] = u;
    path->length++;
}

void DijkstraKPaths(TipoGrafo *Grafo, TipoValorVertice *Raiz, TipoValorVertice *Luminae, int k, Path* paths) {
    TipoPeso P[MAXNUMVERTICES + 1];
    TipoValorVertice Pos[MAXNUMVERTICES + 1];
    long Antecessor[MAXNUMVERTICES + 1];
    short Itensheap[MAXNUMVERTICES + 1];
    TipoVetor A;
    TipoValorVertice u, v;
    TipoItem temp;


    // Initialize path array
    for (int i = 0; i < k; i++) {
        paths[i].length = 0;
        paths[i].weight = INFINITO;
    }

    // Initialize numPathsFound outside the loop
    int numPathsFound = 0;

    for (u = 0; u <= Grafo->NumVertices; u++) {
        /* Constroi o heap com todos os valores igual a INFINITO */
        Antecessor[u] = -1;
        P[u] = INFINITO;
        A[u+1].Chave = u;
        /* Heap a ser construido */
        Itensheap[u] = TRUE;
        Pos[u] = u + 1;
    }

    n = Grafo->NumVertices;
    P[*(Raiz)] = 0;
    Constroi(A, P, Pos);
    while (n >= 1 && numPathsFound <= k) {
        /* enquanto heap nao vazio e o numero de caminhos encontrados for menor que k */
        temp = RetiraMinInd(A, P, Pos);
        u = temp.Chave;
        Itensheap[u] = FALSE;
        printf(("\no u agora é %d\n"), u);

        if (!ListaAdjVazia(&u, Grafo)) {
            Aux = PrimeiroListaAdj(&u, Grafo);
            FimListaAdj = FALSE;

            while (!FimListaAdj) {
                ProxAdj(&u, Grafo, &v, &Peso, &Aux, &FimListaAdj);

                if (P[v] > (P[u] + Peso)) {
                    P[v] = P[u] + Peso;
                    Antecessor[v] = u;
                    DiminuiChaveInd(Pos[v], P[v], A, P, Pos);

                    // Update paths array only if the current vertex is Luminae (destination)
                    printf(("\no v antes do if agora é %d\n"), v);
              //      if (v == *Luminae) {
                        // Update paths array if the new path is shorter
                        paths[numPathsFound].length = 0;
                        ReconstructPath(v, Antecessor, &paths[numPathsFound]);
                        numPathsFound++;
/*
                        // Maintain a min-heap of k shortest paths based on weight
                        if (numPathsFound > k) {
                            // Remove the path with the highest weight from the paths array
                            paths[k - 1].weight = INFINITO;
                        }
*/
                        // Store weight during path reconstruction
                        paths[numPathsFound - 1].weight = P[v];
                    }
                }
            //}
        }
    }
}

int main() {
    printf("No. vertices:");
    scanf("%d%*[^\n]", &NVertices);
    Luminae = NVertices -1;
    getchar();
    printf("No. arestas:");
    scanf("%d%*[^\n]", &NArestas);
    getchar();
    printf("k:");
    //esse será o número de caminhos mínimos cujos pesos deverão ser armazenados em uma fila de prioridade
    scanf("%d%*[^\n]", &k);
    getchar();
    Grafo.NumVertices = NVertices;
    Grafo.NumArestas = 0;
    FGVazio(&Grafo);

    for (i = 0; i < NArestas; i++) {
        printf("Insere V1 -- V2 -- Peso:");
        scanf("%d%d%d%*[^\n]", &V1, &V2, &Peso);
        getchar();
        Grafo.NumArestas++;
        TipoValorVertice tempV1 = V1 - 1;
        TipoValorVertice tempV2 = V2 - 1;

        InsereAresta(&tempV1, &tempV2, &Peso, &Grafo);
    }

    Raiz = 0;
    ImprimeGrafo(&Grafo);
    // Define an array to store k shortest paths
    Path paths[k];

    DijkstraKPaths(&Grafo, &Raiz, &Luminae, k, paths);
    int numPathsFound = 0;
    for (int i = 0; i < k; i++) {
        if (paths[i].weight != INFINITO) {
            numPathsFound++;
            printPath(&paths[i]);
        }
    }

    if (numPathsFound == 0) {
        printf("Não existem %d caminhos mínimos entre Raiz %d e Luminae %d.\n", k, Raiz, Luminae);
    }

    return 0;
}
