#include "headers.h"

// Cria uma matriz n x n
int** create_Matrix(int n)
{
  int **matrix;

  matrix = (int**) malloc(n*sizeof(int*));
  for(int i=0; i<n; i++)
    matrix[i] = (int*) malloc(n*sizeof(int));

  return matrix;
}

// Cria um vetor de tamnho n
int* create_Vector(int n)
{
  int *vector;

  vector = (int*) malloc(n*sizeof(int));

  return vector;
}

// Seta as variáveis de porto em 0
void initialize_Port(Port porto)
{
  porto.demand=0;
  porto.draft=0;
  porto.was_visited=0;
}

// Cria um conjunto de portos
Port* create_PortSet(int n)
{
  Port *port_set;

  port_set = (Port*) malloc(n*sizeof(Port));

  for(int i=0; i<n; i++)
    initialize_Port(port_set[i]);

  return port_set;
}

// Aloca espaço para a estrutura TSPDL
TSPDL* create_TSPDL()
{
  TSPDL *tspdl;

  tspdl = (TSPDL*) malloc(sizeof(TSPDL));

  return tspdl;
}

// Aloca as variáveis de TSPDL com n portos
void initialize_TSPDL(TSPDL *tspdl, int n)
{
  // setar a quantidade de portos
  tspdl->N = n;

  // alocar os portos
  tspdl->setPorts = create_PortSet(n);

  // alocar a matriz de custos
  tspdl->c = create_Matrix(n);
}

// Funções para desalocar memória

void free_Vector(int *vector)
{
  free(vector);
}

void free_Matrix(int **matrix, int n)
{
  for(int i=0; i<n; i++)
    free_Vector(matrix[i]);

  free(matrix);
}

void free_PortSet(Port *portSet)
{
  free(portSet);
}

void free_TSPDL(TSPDL *tspdl)
{
  free_PortSet(tspdl->setPorts);
  free_Matrix(tspdl->c, tspdl->N);

  free(tspdl);
}
