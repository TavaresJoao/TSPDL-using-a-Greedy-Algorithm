#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>

using namespace std;

int main()
{
  string dir;
  getline(cin, dir); // ler o diretório do arquivo

  ifstream myfile;

  myfile.open(dir);
  if(myfile.is_open())
  {
    cout << "The file is open" << endl;
    myfile.close();
  }
  else
    cout << "Unable to open the file" << endl;

  return 0;
}
