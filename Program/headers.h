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

#endif //ARQUIVOS_H_INCLUDED
