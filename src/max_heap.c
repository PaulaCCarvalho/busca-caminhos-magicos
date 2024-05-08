#include "../headers/max_heap.h"
#include <stdio.h>
#include "limits.h"

void Refaz(TipoIndice Esq, TipoIndice Dir, TipoItem *A)
{ TipoIndice i = Esq;
    int j;
    TipoItem x;
    j = i * 2;
    x = A[i];
    while (j <= Dir)
    { if (j < Dir)
        { if (A[j].Chave < A[j+1].Chave)
                j++;
        }
        if (x.Chave >= A[j].Chave) goto L999;
        A[i] = A[j];
        i = j; j = i * 2;
    }
    L999: A[i] = x;
}
void Constroi(TipoItem *A, TipoIndice *n)
{ TipoIndice Esq;
    Esq = *n / 2 + 1;
    while (Esq > 1)
    { Esq--;
        Refaz(Esq, *n, A);
    }
}

TipoItem Max(TipoItem *A)
{ return (A[1]); }

TipoItem RetiraMax(TipoItem *A, TipoIndice *n)
{ TipoItem Maximo;
    if (*n < 1)
        printf("Erro: heap vazio\n");
    else { Maximo = A[1];  A[1] = A[*n];  (*n)--;
        Refaz(1, *n, A);
    }
    return Maximo;
}

void AumentaChave(TipoIndice i, TipoChave ChaveNova, TipoItem *A)
{ TipoItem x;
    if (ChaveNova < A[i].Chave)
    { printf("Erro: ChaveNova menor que a chave atual\n");
        return;
    }
    A[i].Chave = ChaveNova;
    while (i > 1 && A[i / 2].Chave < A[i].Chave)
    { x = A[i / 2];  A[i / 2] = A[i];  A[i] = x;
        i /= 2;
    }
}

void Insere(TipoItem *x, TipoItem *A, TipoIndice *n)
{(*n)++;
    A[*n] = *x;  A[*n].Chave = INT_MIN;
    AumentaChave(*n, x->Chave, A);
}

void Imprime(TipoItem *V, TipoIndice *n)
{ for (i = 1; i <= *n; i++)
        printf("%d ", V[i].Chave);
    putchar('\n');
}