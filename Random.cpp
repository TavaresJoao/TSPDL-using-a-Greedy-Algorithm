#include "headers.h"

pair<vector<int>, int> random_algorithm(TSPDL *tspdl, int L0)
{
  // Li é a carga do navio ao entrar no porto i
  // i porto de origem
  // j porto de destino
  //cout << "Start greedy_algorithm" << endl;
  int i=0, j, Li=L0;

  pair<vector<int>, int> rota;// first: route; second: cost
  rota.second = 0;
  rota.first.push_back(i);

  while(Li!=0)
  {
    //cout << "Porto atual: " << i <<  '\t' << "Carga atual: " << Li << endl;
    j = getNext_random(tspdl, Li, i);

    tspdl->setPorts[i].was_visited = 1;
    Li -= tspdl->setPorts[j].demand;

    rota.second += tspdl->c[i][j];

    i=j;

    rota.first.push_back(i);
  }
  rota.second += tspdl->c[i][0];

  return rota;
}

/* Função para pegar a melhor opção do próximo porto
*   tspdl - é a estrutura com os portos, suas respectivas demandas e calados
*   Li - é carga no navio
*   current - é o porto atual
*/
int getNext_random(TSPDL *tspdl, int Li, int current)
{
  // condições
  // 1 -  o custo cij deve ser o menor possível
  // 2 -  carga do navio ao entrar no porto deve ser menor que o limite
  //      do calado do porto
  // 3 -  o porto não pode ter sido visitado anteriormente
  // 4 - o navio não pode voltar para o mesmo porto

  int i, j, menor;

  srand( time(NULL) );
  int p1 = rand()%(tspdl->N);

  while(  !(Li <= tspdl->setPorts[p1].draft && tspdl->setPorts[p1].was_visited==0
          && p1!=current))
    p1 = rand()%(tspdl->N);

  return p1;

  /*
  int p2 = rand()%(tspdl->N);
  int p3 = rand()%(tspdl->N);

  if( (tspdl->c[current][p1] <= tspdl->c[current][p2]
      && tspdl->c[current][p1] <= tspdl->c[current][p3])
    && Li <= tspdl->setPorts[p1].draft && tspdl->setPorts[p1].was_visited==0
    && p1!=current)
  {
    return p1;
  }
  else if( (tspdl->c[current][p2] <= tspdl->c[current][p1]
      && tspdl->c[current][p2] <= tspdl->c[current][p3])
    && Li <= tspdl->setPorts[p2].draft && tspdl->setPorts[p2].was_visited==0
    && p2!=current)
  {
    return p2;
  }
  else if( (tspdl->c[current][p3] <= tspdl->c[current][p1]
      && tspdl->c[current][p3] <= tspdl->c[current][p2])
    && Li <= tspdl->setPorts[p3].draft && tspdl->setPorts[p3].was_visited==0
    && p3!=current)
  {
    return p3;
  }
  else
  {
    menor=INFINITE;
    for(i=0; i<tspdl->N; i++)
    {
      if( tspdl->c[current][i] < menor && Li <= tspdl->setPorts[i].draft
          && tspdl->setPorts[i].was_visited == 0 && current != i)
      {
        menor = tspdl->c[current][i];
        j = i;
      }
    }

    return j;
  }
  */
}
