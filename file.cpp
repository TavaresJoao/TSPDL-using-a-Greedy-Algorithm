#include "headers.h"

/*
* inputFile_type represents the shape of input instance file
* type 0: KroA100_50 KroA100_75  KroA_200_50 KroA_200_75 pcb442_50 pcb442_75
* type 1: bayg29_10 bayg29_25 bayg29_50 burma14_10 burma14_25 burma14_50
*         fri26_10 fri26_25 fri26_50 gr17_10 gr17_25 gr17_50 gr21_10 gr21_25
*         gr21_50 gr48_10 gr48_25 gr48_50 ulysses16_10 ulysses16_25
*         ulysses16_50 ulysses22_10 ulysses22_25 ulysses22_50
*/
TSPDL* import_data(string inFile, int inputFile_type)
{
  ifstream myinput;

  TSPDL *tspdl = create_TSPDL();

  myinput.open(inFile);

  if( !myinput.is_open() )
    return NULL; // ERROR

  // --> segue o baile
  int i, j;

  if(inputFile_type == 0)
  {
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
  }
  else if(inputFile_type ==1)
  {
    string line;

    // 4 linhas inúteis
    getline(myinput, line);
    getline(myinput, line);
    getline(myinput, line);
    getline(myinput, line);

    // na 5 linha tem-se o N
    myinput >> line;
    myinput >> tspdl->N;
    getline(myinput, line); // pegar o resto da linha

    tspdl->setPorts = create_PortSet(tspdl->N);

    // 6 linhas inúteis
    getline(myinput, line);
    getline(myinput, line);
    getline(myinput, line);
    getline(myinput, line);
    getline(myinput, line);
    getline(myinput, line);

    // próximas 3 linhas para definir os nóscanf
    getline(myinput, line);
    getline(myinput, line);
    getline(myinput, line);

    // próximas N + 2 linhas para a matriz de custos
    getline(myinput, line);

    tspdl->c = create_Matrix(tspdl->N);

    for(i=0; i<tspdl->N; i++)
    {
      for(j=0; j<tspdl->N; j++)
      {
        myinput >> tspdl->c[i][j];
      }
      getline(myinput, line); // pegar o resto da linha
    }

    getline(myinput, line);

    // próximas 3 linhas para ProsX
    getline(myinput, line);
    getline(myinput, line);
    getline(myinput, line);

    // próximas 3 linhas para ProsY
    getline(myinput, line);
    getline(myinput, line);
    getline(myinput, line);

    // próximas 3 linhas para demanda
    getline(myinput, line);

    for(i=0; i<tspdl->N; i++)
    {
      myinput >> tspdl->setPorts[i].demand;
    }
    getline(myinput, line); // pegar o resto da linha

    getline(myinput, line);

    // próximas 3 linhas para o limite do calado
    getline(myinput, line);

    for(i=0; i<tspdl->N; i++)
    {
      myinput >> tspdl->setPorts[i].draft;
    }
    getline(myinput, line); // pegar o resto da linha

    getline(myinput, line);
  }

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

  vector<string> mydir;
  mydir = split(inFile, '/');
  // the output format is: input_file_name solution exection_time_in_seconds
  myoutput << mydir.at(mydir.size()-1) << "\t\t\t" << route.second << "\t\t\t" << prog_time << endl;

  myoutput.close();
  return 0;
}

const vector<string> split(const string& s, const char& delimiter)
{
  string buff{""};
  vector<string> v;

  for(auto n:s)
  {
    if( n != delimiter )
      buff += n;
    else
    {
      if( buff != "" )
      {
        v.push_back(buff);
        buff="";
      }
    }
  }
  if(buff != "")
    v.push_back(buff);

  return v;
}
