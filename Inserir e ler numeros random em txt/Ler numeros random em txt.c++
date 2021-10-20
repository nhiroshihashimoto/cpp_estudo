#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//g++ -o l.exe le.c++ -std=c++11

int main () {
  string line, linha;
  std::size_t encontrou, encontrou2;
  
  ifstream myfile ("data.txt");
  if (myfile.is_open())
  {
	  float n=0;
    while ( getline (myfile,line) )
    {
		
      n=stof(line);
      cout<<"\n"<<n;
      
    }
    myfile.close();
  }
  else cout << "Nao foi possivel abrir o arquivo"; 

  return 0;
}
