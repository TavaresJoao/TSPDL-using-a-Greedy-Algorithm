#include "headers.h"

#include<iostream>
#include<ifstream>
#include<ofstream>

using namespace std;

int import(char *inFile, char *outFile)
{
  ifstream myinput;
  ofstream myoutput;

  myinput.open(inFile);
  // std::ios::app is the open mode "append" meaningi new data will be written
  // to the end of the file
  myoutput.open(outFile, app);

  if( !myinput.is_open() || !myoutput.is_open() )
    return 1; // ERROR

  // segue o baile
  // 1o Passo Aquisição de dados
}
