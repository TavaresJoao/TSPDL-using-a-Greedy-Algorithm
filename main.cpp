#include "headers.h"

int main(int argc, char *argv[])
{
  if(argc == 4)
  {
    return make_greedy_trade(argv[1], argv[2], stoi(argv[3]));
  }

  return 0;
}
