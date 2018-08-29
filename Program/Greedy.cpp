#include "headers.h"

#define INFINITE 99999

int greedy_algorithm(TSPDL *tspdl, int L)
{
  // Li é a carga do navio ao entrar no porto i
  // i porto de origem
  // j porto de destino
  int i=0, j, Li=L, cont=0;

  int *trade;
  trade = create_Vector(tspdl->N);

  trade[cont++]=i;
  while(Li!=0)
  {
    j = getNext(tspdl, Li, i);

    tspdl[i]->was_visited = 1;
    Li -= tspdl[i]->demand;

    i=j;

    trade[cont++]=i;
  }
}

// Função para pegar a melhor opção do próximo porto
int getNext(TSPDL *tspdl, int Li, int current)
{
  int i, j=0, menor=INFINITE;

  for(i=0; tspdl->N; i++)
  {
    // condições
    // 1 -  o custo cij deve ser o menor possível
    // 2 -  carga do navio ao entrar no porto deve ser menor que o limite
    //      do calado do porto
    // 3 -  o porto não pode ter sido visitado anteriormente
    // 4 - o navio não pode voltar para o mesmo porto
    if( tspdl->c[current][i] < menor && Li <= lspdl->setPorts[i]->draft
        && tspdl->setPorts[i]->was_visited ==0 && current != i)
    {
      menor = tspdl->c[current][i];
      j = i;
    }
  }

  return j;
}
