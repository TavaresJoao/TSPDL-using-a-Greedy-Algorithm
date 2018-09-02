#include "headers.h"

TSPDL* import_data(string inFile)
{
  ifstream myinput;

  TSPDL *tspdl = create_TSPDL();

  myinput.open(inFile);

  if( !myinput.is_open() )
    return NULL; // ERROR

  // --> segue o baile
  int i, j;

  // 1o passo: Aquisição do N
  myinput >> tspdl->N;

  // 2o passo: setar a matriz de custos
  tspdl->c = create_Matrix(tspdl->N);

  for(i=0; i<tspdl->N; i++)
    for(j=0; j<tspdl->N; j++)
      myinput >> tspdl->c[i][j];

  // 3o passo: setar o conjunto de portos
  tspdl->setPorts = create_PortSet(tspdl->N);

  for(i=0; i<tspdl->N; i++)
    myinput >> tspdl->setPorts[i].demand;

  for(i=0; i<tspdl->N; i++)
    myinput >> tspdl->setPorts[i].draft;

  myinput.close();
  return tspdl;
}

// write in a output file the solucions and the execution time (s) of an input instance file
int export_data(string outFile, string inFile, pair<int*, int> route, double prog_time)
{
  ofstream myoutput;
  // std::ios::app is the open mode "append" meaningi new data will be written
  // to the end of the file
  myoutput.open(outFile, ofstream::app);
  if( !myoutput.is_open() )
    return 1;

  // the output format is: input_file_name solution exection_time_in_seconds
  myoutput << inFile << '\t' << route.second << '\t' << prog_time << endl;

  myoutput.close();
  return 0;
}
