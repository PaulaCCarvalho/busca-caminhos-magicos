//
// Created by seph on 08/05/24.
//

#ifndef BUSCA_CAMINHOS_MAGICOS_MAX_HEAP_H
#define BUSCA_CAMINHOS_MAGICOS_MAX_HEAP_H

#define MAXTAM 20

typedef int TipoChave;
typedef struct TipoItem {
    TipoChave Chave;
    /* outros componentes */
} TipoItem;
typedef int TipoIndice;
typedef TipoItem TipoVetor[MAXTAM + 1];

TipoVetor A, B;
TipoIndice i, n;
TipoItem x;
void Refaz(TipoIndice Esq, TipoIndice Dir, TipoItem *A);
void Constroi(TipoItem *A, TipoIndice *n);
TipoItem Max(TipoItem *A);
TipoItem RetiraMax(TipoItem *A, TipoIndice *n);

void AumentaChave(TipoIndice i, TipoChave ChaveNova, TipoItem *A);
void Insere(TipoItem *x, TipoItem *A, TipoIndice *n);
void Imprime(TipoItem *V, TipoIndice *n);


#endif //BUSCA_CAMINHOS_MAGICOS_MAX_HEAP_H
