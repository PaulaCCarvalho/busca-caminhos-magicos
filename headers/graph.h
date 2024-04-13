#ifndef BUSCA_CAMINHOS_MAGICOS_GRAPH_H
#define BUSCA_CAMINHOS_MAGICOS_GRAPH_H

#define TRUE 1
#define FALSE 0
#define MAXNUMVERTICES 100
#define MAXNUMARESTAS 4500
#define MAXTAM (MAXNUMVERTICES + MAXNUMARESTAS * 2)

typedef int TipoValorVertice;
typedef int TipoPeso;
typedef int TipoTam;

typedef struct TipoGrafo {
    TipoTam Cab[MAXTAM + 1];
    TipoTam Prox[MAXTAM + 1];
    TipoTam Peso[MAXTAM + 1];
    TipoTam ProxDisponivel;
    int NumVertices;
    int NumArestas;
} TipoGrafo;

typedef int TipoApontador;

void FGVazio(TipoGrafo *Grafo);

void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo);

short ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2, TipoGrafo *Grafo);

int ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo);

TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo);

void ProxAdj(TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox,
             short *FimListaAdj);

void RetiraAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo);

void ImprimeGrafo(TipoGrafo *Grafo);

#endif //BUSCA_CAMINHOS_MAGICOS_GRAPH_H
