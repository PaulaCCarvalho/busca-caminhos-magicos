#include <stdio.h>
#include "graph.c"

TipoApontador Aux;
int i;
TipoValorVertice V1, V2, Adj;
TipoPeso Peso;
TipoGrafo Grafo;
TipoValorVertice NVertices;
short NArestas;
short FimListaAdj;

int main() {
    printf("Leitura do grafo\n");
    printf("No. vertices : ");
    scanf("%d", &NVertices);
    getchar();
    printf("No. arestas :");
    scanf("%d", &NArestas);
    getchar();
    Grafo.NumVertices = NVertices;
    Grafo.NumArestas = 0;
    FGVazio(&Grafo);
    for (i = 0; i <= NArestas - 1; i++) {
        printf("Insere V1 V2 Peso: ");
        scanf("%d %d %d", &V1, &V2, &Peso);
        getchar();
        Grafo.NumArestas++;
        InsereAresta(&V1, &V2, &Peso, &Grafo);
    }
    ImprimeGrafo(&Grafo);
    getchar();
    printf("Insere V1 V2 Peso :");
    scanf("%d %d %d", &V1, &V2, &Peso);
    getchar();
    if (ExisteAresta(V1, V2, &Grafo))
        printf("Aresta ja existe\n");
    else {
        Grafo.NumArestas++;
        InsereAresta(&V1, &V2, &Peso, &Grafo);
    }
    ImprimeGrafo(&Grafo);
    getchar();
    printf("Lista adjacentes de : ");
    scanf("%d", &V1);
    if (!ListaAdjVazia(&V1, &Grafo)) {
        Aux = PrimeiroListaAdj(&V1, &Grafo);
        FimListaAdj = FALSE;
        while (!FimListaAdj) {
            ProxAdj(&V1, &Grafo, &Adj, &Peso, &Aux, &FimListaAdj);
            printf("%d (%d)", Adj, Peso);
        }
        putchar('\n ');
        getchar();
    }
    printf("Retira aresta V1--V2:");
    scanf(" %d %d", &V1, &V2);
    getchar();

    return 0;
}
