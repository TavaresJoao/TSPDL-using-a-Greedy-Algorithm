#include "headers.h"

int** create_Matrix(int n)
{
  int **matrix;

  matrix = (int**) malloc(n*sizeof(int*));
  for(int i=0; i<n; i++)
    matrix[i] = (int*) malloc(n*sizeof(int));

  return matrix;
}

int* create_Vector(int n)
{
  int *vector;

  vector = (int*) malloc(n*sizeof(int));

  return vector;
}

port* create_Port()
{
  port *porto;

  porto = (port*) malloc(sizeof(port));

  porto->demand=0;
  porto->draft=0;
  porto->was_visited=0;

  return(porto);
}

port** create_PortSet(int n)
{
  port **port_set;

  port_set = (port**) malloc(n*sizeof(port*));
  for(int i=0; i<n; i++)
    port_set[i] = create_Port();

  return port_set;
}

TSPDL* create_TSPDL()
{
  TSPDL *tspdl;

  tspdl = (TSPDL*) malloc(sizeof(TSPDL));

  return tspdl;
}

void initialize_TSPDL(TSPDL *tspdl, int n)
{
  // setar a quantidade de portos
  tspdl->N = n;

  // alocar os portos
  tspdl->setPorts = create_PortSet(n);

  // alocar a matriz de custos
  tspdl->c = create_Matrix(n);
}

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

void free_Port(port *porto)
{
  free(porto);
}

void free_PortSet(port **portSet, int n)
{
  for(int i=0; i<n; i++)
    free_port(portSet[i]);

  free(portSet);
}

void free_TSPDL(TSPDL *tspdl)
{
  free_PortSet(tspdl->setPorts);
  free_Matrix(tspdl->c);

  free(tspdl);
}
