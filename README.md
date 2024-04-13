A Busca por Caminhos Mágicos
No reino encantado de Xulambis, situado entre as antigas florestas de Mysthollow e os prados
místicos de Luminae, encontra-se um segredo conhecido por poucos: uma rede de caminhos mágicos
que conectam os dois reinos. Esses caminhos, envoltos em mistério e guardados por poderosos
encantamentos, oferecem aos viajantes um atalho através da vasta natureza selvagem.
Sua tarefa, como um bravo aventureiro, é descobrir os k caminhos mágicos mais curtos de
Mysthollow para Luminae:. Mas cuidado, pois esses caminhos não estão isentos de desafios. Eles
se torcem e viram através de densas florestas, sobre rios cintilantes e sobre montanhas cobertas
de névoa. E para aumentar a complexidade, um caminho pode levá-lo a revisitar a mesma cidade
mágica várias vezes, cada visita revelando novas maravilhas e perigos. Mas não tema, pois sua
busca não é sem recompensa. Para cada caminho que você descobrir, desbloqueará um fragmento
do conhecimento antigo e ganhará a admiração dos seres mágicos que habitam estas terras.
Lembre-se, pode haver vários caminhos com a mesma potência mágica, e cada um deve ser
considerado. Apenas os aventureiros mais astutos e determinados terão sucesso em desvendar os
segredos desses caminhos místicos e completar sua busca.
Embarque nesta jornada mágica, bravo aventureiro, e que a orientação dos antigos ilumine seu
caminho enquanto você busca os k caminhos mágicos mais curtos de Mysthollow para Luminae:!
Input
A primeira linha de entrada contém três inteiros n, m e k: o número de cidades, o número de
voos e o parâmetro k. As cidades são numeradas de 1 a n. A cidade 1 é Mysthollow, e a cidade n
é Luminae.
Após isso, a entrada possui m linhas descrevendo os voos. Cada linha contém três inteiros a,
b e c: um voo começa na cidade a, termina na cidade b, e seu preço é c. Todos os voos são voos
de apenas uma direção.
Você pode assumir que há pelo menos k rotas distintas de Mysthollow para Luminae.
Output
Imprima k inteiros: os preços das k rotas mais baratas, ordenadas de acordo com seus preços.
Restrições
2 ≤ n ≤ 105
1 ≤ m ≤ 2 · 105
1 ≤ a, b ≤ n
1 ≤ c ≤ 109
1 ≤ k ≤ 10
Exemplo
Entrada:
4 6 3
1 2 1
1 3 3
2 3 2
1
2 4 6
3 2 8
3 4 1
Saída:
4 4 7
Elabore um programa com as seguintes características:
1. O programa deve ser implementado em módulos. Deve ainda ser definido um arquivo de
protótipos e definições contendo as estruturas de dados e protótipos das funções dos vários
módulos. A compilação do programa deve utilizar o utilitário Make.
2. Todas as estruturas de dados devem ser alocadas dinamicamente, assim como devem ser
desalocadas após o processamento. As rotinas de teste de colisão também devem ser imple-
mentadas usando estruturas de alocação dinâmica.
3. O programa deve receber dois parâmetros pela linha de comando, utilizando a primitiva
getopt:
(a) -i arquivo de entrada
(b) -o arquivo de saída
O programa implementado deve ser avaliado para várias arquivos de entrada utilizando as
funções getrusage e gettimeofday. Deve-se também distinguir entre os tempos de computação
e tempos de entrada e saída. Comente sobre os tempos de usuário e os tempos de sistema e sua
relação com os tempos de relógio.
Avaliação
Deverão ser entregues:
• listagem das rotinas;
• descrição breve dos algoritmos e das estruturas de dados utilizadas;
• análise da complexidade das rotinas;
• análise dos resultados obtidos.
Distribuição dos pontos:
• execução (E)
execução correta: 80%
• estilo de programação
código bem estruturado: 10%
código legível: 10%
• documentação (D)
comentários explicativos: 40%
análise de complexidade: 30%
análise de resultados: 


1) Montar grafo ponderado
1.1 Implementação do TAD