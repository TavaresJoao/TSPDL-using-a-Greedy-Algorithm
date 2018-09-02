#include "headers.h"

int make_greedy_trade(string inFile, string outFile)
{
  TSPDL *myproblem = import_data(inFile);
  if(myproblem == NULL)
  {
    cout << "Problem opening the input file" << endl;
    return 1; // ERROR
  }

  int i, L0=0;
  for(i=0; i<myproblem->N; i++)
    L0 += myproblem->setPorts[i].demand;

  clock_t t;
  t = clock();
  pair<int*,int> trade = greedy_algorithm(myproblem, L0);
  t = clock()-t;

  //testes
  /*
  cout << "Custo total: " << trade.second << endl << "Rota: ";
  for(i=0; i<myproblem->N; i++)
    cout << trade.first[i] << " ";
  cout << endl << "Tempo: " << (double)t/CLOCKS_PER_SEC << "s" << endl;
  */

  if( export_data(outFile, inFile, trade, (double)t/CLOCKS_PER_SEC) )
  {
    free_Vector(trade.first);
    free_TSPDL(myproblem);

    cout << "Problem opening the output file" << endl;
    return 1; // ERROR
  }

  free_Vector(trade.first);
  free_TSPDL(myproblem);
  return 0;
}
