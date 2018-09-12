#include "headers.h"

int main(int argc, char *argv[])
{
  /*
    argv[1] == input_file
    argv[2] == output_file
    argv[3] == input_type_file
  */
  if(argc == 4)
  {
    return make_random_trade(argv[1], argv[2], stoi(argv[3]));
  }

  return 0;
}
