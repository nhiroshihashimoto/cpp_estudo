#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream arquivo;
  string entrada;

  int linhas = 1;
  cout<<"\n Insira as quantidades de linhas totais: ";
  cin>>linhas;

  arquivo.open ("data.csv");

  for(int x=1; x<=linhas;x++) {
    cout<<"\n Insira na linha " << x << ": ";
    cin>>entrada;
    arquivo << x << ";" << entrada << "\n";
  }

  cout<<"\n Arquivo salvo";

  arquivo.close();

  return 0;
}
