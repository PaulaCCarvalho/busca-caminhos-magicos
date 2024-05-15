#ifndef BUSCA_CAMINHOS_MAGICOS_LIMITS_H
#define BUSCA_CAMINHOS_MAGICOS_LIMITS_H
///////////////////////////////////////////////////////////
// Valores mínimos e máximos de vários tipos-de-dados.
///////////////////////////////////////////////////////////

#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   4500
#define FALSE           0
#define TRUE            1
#define INFINITO       INT_MAX

// Valor mínimo e valor mácimo do tipo-de-dados int.
// Tipicamente, os valores são -2^{31} e 2^{31}-1
// respectivamente.

#define INT_MIN  (-2147483648)
#define INT_MAX   (2147483647)


// Valor máximo do tipo-de-dados unsigned int. Tipicamente
// 2^{32}-1.


#define UINT_MAX  (4294967295)


// Valores mínimo (-2^{15}) e máximo (2^{15}-1) do tipo-de-
// -dados short int.

#define SHRT_MIN      (-32768)
#define SHRT_MAX       (32767)


// Valores mínimo e máximo do tipo-de-dados long int. Em
// máquinas de 64 bits os valores são -2^{63} e 2^{63}-1
// respecivamente. Em máquinas de 32 bits os valores são
// -2^{31} e 2^{31}-1.

#define LONG_MIN (-9223372036854775808L)
#define LONG_MAX  (9223372036854775807L)
#endif //BUSCA_CAMINHOS_MAGICOS_LIMITS_H
