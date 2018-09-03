#include "headers.h"

#define INFINITE 99999

//o guloso retorna a rota e o custo da rota
pair<int*,int> greedy_algorithm(TSPDL *tspdl, int L0)
{
  // Li é a carga do navio ao entrar no porto i
  // i porto de origem
  // j porto de destino
  //cout << "Start greedy_algorithm" << endl;
  int i=0, j, Li=L0, cont=0;
  pair<int*,int> rota;// first-route; second-cost

  rota.second = 0;
  rota.first = create_Vector(tspdl->N);

  rota.first[cont++]=i;
  while(Li!=0)
  {
    //cout << "Porto atual: " << i <<  '\t' << "Carga atual: " << Li << endl;
    j = getNext(tspdl, Li, i);

    tspdl->setPorts[i].was_visited = 1;
    Li -= tspdl->setPorts[j].demand;

    rota.second += tspdl->c[i][j];

    i=j;

    rota.first[cont++]=i;
  }
  rota.second += tspdl->c[i][0];

  return rota;
}

/* Função para pegar a melhor opção do próximo porto
*   tspdl - é a estrutura com os portos, suas respectivas demandas e calados
*   Li - é carga no navio
*   current - é o porto atual
*/
int getNext(TSPDL *tspdl, int Li, int current)
{
  int i, j, menor=INFINITE;

  for(i=0; i<tspdl->N; i++)
  {
    // condições
    // 1 -  o custo cij deve ser o menor possível
    // 2 -  carga do navio ao entrar no porto deve ser menor que o limite
    //      do calado do porto
    // 3 -  o porto não pode ter sido visitado anteriormente
    // 4 - o navio não pode voltar para o mesmo porto
    if( tspdl->c[current][i] < menor && Li <= tspdl->setPorts[i].draft
        && tspdl->setPorts[i].was_visited == 0 && current != i)
    {
      menor = tspdl->c[current][i];
      j = i;
    }
  }

  return j;
}
