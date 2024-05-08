#include <stdio.h>
#include "graph.c"
#include "max_heap.c"

TipoApontador Aux;
int i;
TipoValorVertice V1, V2, Adj;
TipoPeso Peso;
TipoGrafo Grafo;
TipoValorVertice NVertices;
short NArestas;
short FimListaAdj;

int main() {

    TipoItem TEMP;
    n = 7;
    for (i = 1; i <= n; i++)
        scanf("%d", &A[i].Chave);
    /* Teste: 20 15 18 10 12 9 13 */
    printf("Desordenado: ");
    Imprime(A, &n);

    printf("Constroi   : ");
    Constroi(A, &n);
    Imprime(A, &n);

    printf("Aumenta chave posicao 6 para 25: ");
    AumentaChave(6, 25, A);
    Imprime(A, &n);

    x.Chave = 13;
    printf("Insere%3d: ", x.Chave);
    Insere(&x, A, &n);
    Imprime(A, &n);

    TEMP = Max(A);
    printf("Max:%3d\n", TEMP.Chave);

    x = RetiraMax(A, &n);
    printf("Retira%3d: ", x.Chave);
    Imprime(A, &n);

    return 0;
}

/*
    Código da main para teste do Grafo
     printf("Leitura do grafo\n");
    printf("No. vertices : ");
    scanf("%d", &NVertices);
    getchar();
    printf("No. arestas :");
    scanf("%hd", &NArestas);
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
*/
