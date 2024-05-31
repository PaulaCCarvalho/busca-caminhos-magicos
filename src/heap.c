#include "../headers/heap.h"
#include <stdio.h>

void RefazInd(TipoIndice Esq, TipoIndice Dir, TipoItem *A, TipoPeso *P,
              TipoValorVertice *Pos)

{ TipoIndice i = Esq;  int j;  TipoItem x;
    j = i * 2;  x = A[i];
    while (j <= Dir)
    { if (j < Dir)
        { if (P[A[j].Chave] > P[A[j+1].Chave]) j++;
        }
        if (P[x.Chave] <= P[A[j].Chave])  goto L999;
        A[i] = A[j]; Pos[A[j].Chave] = i;
        i = j;   j = i * 2;
    }
    L999:  A[i] = x;  Pos[x.Chave] = i;
}

void Constroi(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos)

{ TipoIndice Esq;
    Esq = n / 2 + 1;
    while (Esq > 1)
    { Esq--;
        RefazInd(Esq, n, A, P, Pos);
    }
}

TipoItem RetiraMinInd(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos)
{ TipoItem Result;
    if (n < 1)
    { printf("Erro: heap vazio\n");
        return Result;
    }
    Result = A[1];
    A[1] = A[n]; Pos[A[n].Chave] = 1;
    n--;
    RefazInd(1, n, A, P, Pos);
    return Result;
}

void InsereMinHeap(TipoItem novoElemento, TipoItem *A, TipoPeso *P, TipoValorVertice *Pos) {
    // Aumenta o tamanho da heap (se necessário)
    n++;

    // Insere o novo elemento na última posição (folha)
    A[n] = novoElemento;
    Pos[novoElemento.Chave] = n;

    // Define a chave inicial como INT_MAX para forçar o "afundamento"
    P[novoElemento.Chave] = INT_MAX;

    // Reajusta a heap para manter a propriedade de min heap
    DiminuiChaveInd(n, P[novoElemento.Chave], A, P, Pos);
}
void DiminuiChaveInd(TipoIndice i, TipoPeso ChaveNova, TipoItem *A,
                     TipoPeso *P,  TipoValorVertice *Pos)
{ TipoItem x;
    if (ChaveNova > P[A[i].Chave])
    { printf("Erro: ChaveNova maior que a chave atual\n");
        return;
    }
    P[A[i].Chave] = ChaveNova;
    while (i > 1 && P[A[i / 2].Chave] > P[A[i].Chave])
    { x = A[i / 2];
        A[i / 2] = A[i];
        Pos[A[i].Chave] = i / 2;
        A[i] = x;
        Pos[x.Chave] = i;
        i /= 2;
    }
}