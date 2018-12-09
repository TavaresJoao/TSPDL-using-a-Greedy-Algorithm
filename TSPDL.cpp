#include "headers.h"

int make_greedy_trade(string inFile, string outFile, int inputFile_type)
{
  TSPDL *myproblem = import_data(inFile, inputFile_type);
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
  pair<vector<int>, int> trade = greedy_algorithm(myproblem, L0);
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
    free_TSPDL(myproblem);

    cout << "Problem opening the output file" << endl;
    return 1; // ERROR
  }

  free_TSPDL(myproblem);
  return 0;
}

int make_random_trade(string inFile, string outFile, int inputFile_type)
{
  TSPDL *myproblem = import_data(inFile, inputFile_type);
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
  pair<vector<int>, int> trade = random_algorithm(myproblem, L0);
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
    free_TSPDL(myproblem);

    cout << "Problem opening the output file" << endl;
    return 1; // ERROR
  }

  free_TSPDL(myproblem);
  return 0;
}

int make_local_search(string inFile, string outFile, int inputFile_type)
{
  TSPDL *myproblem = import_data(inFile, inputFile_type);
  if(myproblem == NULL)
  {
    cout << "Problem opening the input file" << endl;
    return 1; // ERROR
  }

  int i, L0=0;
  for(i=0; i<myproblem->N; i++)
    L0 += myproblem->setPorts[i].demand;

  pair<vector<int>, int> S0 = random_algorithm(myproblem, L0);

  // Testes
  cout << "Solução inicial" << endl << "Custo total: " << S0.second << endl << "Rota: ";
  for(i=0; S0.first.begin()+i<S0.first.end(); i++)
    cout << S0.first[i] << " ";
  cout << endl;
  // END Testes

  for(i=0; i<myproblem->N; i++)
    myproblem->setPorts[i].was_visited=0;

  pair<vector<int>, int> trade = sophistication_2opt(myproblem, L0, S0);

  // Testes
  cout << "Solução refinada" << endl << "Custo total: " << trade.second << endl << "Rota: ";
  for(i=0; trade.first.begin()+i<trade.first.end(); i++)
    cout << trade.first[i] << " ";
  cout << endl;
  // END Testes

  free_TSPDL(myproblem);
  return 0;
}
