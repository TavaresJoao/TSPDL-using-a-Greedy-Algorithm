#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

typedef struct
{
  int demand;       // demand associated to the port
  int draft;        // the draft limit of the port
  int was_visited;  // if the port was visited before
}port;

typedef struct
{
  int N;            // number of ports
  port **setPorts;  // Set of Ports, V = {0,1,...,n}
  int **c;          // Cost cij (associated to (i,j))
}TSPDL;

// allocation functions
int** create_Matrix(int n);
int* create_Vector(int n);
port* create_Port();
port** create_PortSet(int n);
TSPDL* create_TSPDL();
void initialize_TSPDL(TSPDL *tspdl, int n);
void free_Vector(int *vector);
void free_Matrix(int **matrix, int n);
void free_Port(port *porto);
void free_PortSet(port **portSet, int n);
void free_TSPDL(TSPDL *tspdl);

// getfile functions
int import(char *inFile, char *outFile);

// greedy functions
int greedy_algorithm(TSPDL *tspdl, int L);
int getNext(TSPDL *tspdl, int Li, int current);

#endif //ARQUIVOS_H_INCLUDED
