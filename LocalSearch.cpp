#include "headers.h"

// O refinamento pela busca local recebe como parâmetros o problema TSPDL
// e uma solução inicial
pair<vector<int>, int> sophistication_2opt(TSPDL *tspdl, int L0, pair<vector<int>, int> initial_solution)
{
  cout << "Here :: sophistication_2opt" << endl;
  int j, i, melhor, aux_melhor, Lj=L0, aux;
  pair<vector<int>, int> local_best = initial_solution;

  local_best.second = 0;
  tspdl->setPorts[0].was_visited=1;
  for(j=1; local_best.first.begin()+j<local_best.first.end(); j++)
  {
    melhor=local_best.first[j];
    aux_melhor = j;

    for(i=j+1; local_best.first.begin()+i<local_best.first.end(); i++)
    {
      /*  se o custo para ir ao porto i é menor do que ir ao melhor
          e o porto i não foi visitado
          e o calado o porto i é maior do que a carga
      */
      if( tspdl->c[local_best.first[j-1]][local_best.first[i]] < tspdl->c[local_best.first[j-1]][melhor] &&
          tspdl->setPorts[local_best.first[i]].was_visited==0 &&
          tspdl->setPorts[local_best.first[i]].draft >= Lj)
      {
        melhor = local_best.first[i]; // o melhor recebe i
        aux_melhor = i;
      }
    }

    aux = local_best.first[j];
    local_best.first[j] = melhor;
    local_best.first[aux_melhor] = aux;

    Lj -= tspdl->setPorts[melhor].demand;
    tspdl->setPorts[melhor].was_visited=1;
    local_best.second += tspdl->c[local_best.first[j-1]][melhor];
  }
  local_best.second += tspdl->c[local_best.first[j-1]][0];

  return local_best;
}
