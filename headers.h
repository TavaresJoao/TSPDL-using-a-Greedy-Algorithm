#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<utility>
#include<ctime>
#include<vector>

using namespace std;

typedef struct
{
  int demand;       // demand associated to the port
  int draft;        // the draft limit of the port
  int was_visited;  // if the port was visited before
}Port;

typedef struct
{
  int N;            // number of ports
  Port *setPorts;  // Set of Ports, V = {0,1,...,n}
  int **c;          // Cost cij (associated to (i,j))
}TSPDL;

// allocation functions
int** create_Matrix(int n);
int* create_Vector(int n);
void initialize_Port(Port porto);
Port* create_PortSet(int n);
TSPDL* create_TSPDL();
void initialize_TSPDL(TSPDL *tspdl, int n);
void free_Vector(int *vector);
void free_Matrix(int **matrix, int n);
void free_PortSet(Port *portSet);
void free_TSPDL(TSPDL *tspdl);

// file functions
TSPDL* import_data(string inFile, int inputFile_type);
int export_data(string outFile, string inFile, pair<int*, int> route, double prog_time);
const vector<string> split(const string& s, const char& delimiter);

// greedy functions
pair<int*,int> greedy_algorithm(TSPDL *tspdl, int L);
int getNext(TSPDL *tspdl, int Li, int current);

// TSPDL functions
int make_greedy_trade(string inFile, string outFile, int inputFile_type);

#endif //ARQUIVOS_H_INCLUDED
