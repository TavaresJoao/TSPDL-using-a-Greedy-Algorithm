#include "headers.h"

int main(int argc, char *argv[])
{
  if(argc == 2)
  {
    return make_greedy_trade(argv[0], argv[1]);
  }

  return 0;
}
