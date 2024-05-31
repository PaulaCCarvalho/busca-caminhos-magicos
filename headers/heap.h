#ifndef BUSCA_CAMINHOS_MAGICOS_HEAP_H
#define BUSCA_CAMINHOS_MAGICOS_HEAP_H
#include "limits.h"

typedef int TipoValorVertice;
typedef int TipoPeso;
typedef TipoValorVertice TipoApontador;
typedef int TipoIndice;
typedef struct TipoItem {
    TipoPeso Chave;
} TipoItem;
TipoIndice n;   /*Tamanho do heap*/
typedef TipoItem TipoVetor[MAXNUMVERTICES + 1];

void RefazInd(TipoIndice Esq, TipoIndice Dir, TipoItem *A, TipoPeso *P,
              TipoValorVertice *Pos);

void Constroi(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos);

TipoItem RetiraMinInd(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos);

void InsereMinHeap(TipoItem novoElemento, TipoItem *A, TipoPeso *P, TipoValorVertice *Pos);

void DiminuiChaveInd(TipoIndice i, TipoPeso ChaveNova, TipoItem *A,
                     TipoPeso *P,  TipoValorVertice *Pos);

#endif //BUSCA_CAMINHOS_MAGICOS_HEAP_H
