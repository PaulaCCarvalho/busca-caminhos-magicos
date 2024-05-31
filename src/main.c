#include <stdio.h>
#include "graph.c"
#include "heap.c"
TipoApontador Aux;
int i;
TipoValorVertice V1, V2, Adj;
TipoPeso Peso;
TipoGrafo Grafo;
TipoValorVertice NVertices;
short NArestas;
int TEMP, nCidades,Destino, k;
TipoValorVertice Raiz, N;
TipoPeso PesoMinimo;
TipoVetor KMinWays;

TipoPeso PesoKMin[MAXNUMVERTICES + 1];
TipoValorVertice PosKMin[MAXNUMVERTICES + 1];

void Dijkstra(TipoGrafo *Grafo, TipoValorVertice *Raiz, TipoValorVertice *N, TipoPeso *pesoMenorCaminho) {
    TipoPeso P[MAXNUMVERTICES + 1];
    TipoValorVertice Pos[MAXNUMVERTICES + 1];
    long Antecessor[MAXNUMVERTICES + 1];
    short Itensheap[MAXNUMVERTICES + 1];
    TipoVetor A;
    TipoValorVertice u, v;
    TipoItem temp;

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

    while (n >= 1) {
        /* enquanto heap nao vazio */
        temp = RetiraMinInd(A, P, Pos);
        u = temp.Chave;
        Itensheap[u] = FALSE;

        if (!ListaAdjVazia(&u, Grafo)) {
            Aux = PrimeiroListaAdj(&u, Grafo);
            FimListaAdj = FALSE;

            while (!FimListaAdj) {
                ProxAdj(&u, Grafo, &v, &Peso, &Aux, &FimListaAdj);

                if (P[v] > (P[u] + Peso)) {
                    P[v] = P[u] + Peso;
                    Antecessor[v] = u;
                    DiminuiChaveInd(Pos[v], P[v], A, P, Pos);
                }
            }
        }
    }

    *pesoMenorCaminho = P[*N];
    TipoItem novoElemento;
    novoElemento.Chave = *pesoMenorCaminho;
    InsereMinHeap(novoElemento, KMinWays, PesoKMin, PosKMin);
}

int main() {
    printf("No. vertices:");
    scanf("%d%*[^\n]", &NVertices);
    Destino = NVertices;
    getchar();
    printf("No. arestas:");
    scanf("%d%*[^\n]", &NArestas);
    getchar();
    printf("k:");
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
    N = NVertices -1;
    ImprimeGrafo(&Grafo);

    Dijkstra(&Grafo, &Raiz, &N, &PesoMinimo);

    if (PesoMinimo != INFINITO) {
        printf("Peso mínimo entre Raiz %d e N %d: %d\n", Raiz, N, PesoMinimo);
    } else {
        printf("Não existe caminho entre Raiz %d e N %d.\n", Raiz, N);
    }

    return 0;
}
