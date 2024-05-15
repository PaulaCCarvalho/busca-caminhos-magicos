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
int TEMP;
TipoValorVertice Raiz;


void Dijkstra(TipoGrafo *Grafo, TipoValorVertice *Raiz) {
    TipoPeso P[MAXNUMVERTICES + 1];
    TipoValorVertice Pos[MAXNUMVERTICES + 1];
    long Antecessor[MAXNUMVERTICES + 1];
    int Itensheap[MAXNUMVERTICES + 1];
    TipoVetor A;
    TipoValorVertice u, v;
    TipoItem temp;
    TipoApontador Aux;
    int FimListaAdj;
    for (u = 0; u <= Grafo->NumVertices; u++) { /*Constroi o heap com todos os valores igual a INFINITO*/
        Antecessor[u] = -1;
        P[u] = INFINITO;
        A[u + 1].Chave = u;   /*Heap a ser construido*/
        Itensheap[u] = TRUE;
        Pos[u] = u + 1;
    }
    n = Grafo->NumVertices;
    P[*(Raiz)] = 0;
    Constroi(A, P, Pos);
    while (n >= 1) { /*enquanto heap nao vazio*/
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
                    printf("Caminho: v[%d] v[%ld] d[%d]",
                           v, Antecessor[v], P[v]);
                    scanf("%*[^\n]");
                    getchar();
                }
            }
        }
    }
}


int main() {
    printf("No. vertices:");
    scanf("%d%*[^\n]", &NVertices);
    getchar();
    printf("No. arestas:");
    scanf("%d%*[^\n]", &NArestas);
    getchar();
    Grafo.NumVertices = NVertices;
    Grafo.NumArestas = 0;
    FGVazio(&Grafo);

    for (i = 0; i <= NArestas - 1; i++)
    { printf("Insere V1 -- V2 -- Peso:");
        scanf("%d%d%d%*[^\n]", &V1, &V2, &Peso);
        getchar();
        Grafo.NumArestas++;
        InsereAresta(&V1, &V2, &Peso, &Grafo);   /* 1 chamada g-direcionado    */
        /*InsereAresta(V2, V1, Peso, Grafo);*/
        /* 2 chamadas g-naodirecionado*/
    }
    ImprimeGrafo(&Grafo);
    printf("Raiz:");
    scanf("%d%*[^\n]", &TEMP);
    getchar();
    Raiz = TEMP;
    Dijkstra(&Grafo, &Raiz);
    return 0;
}
