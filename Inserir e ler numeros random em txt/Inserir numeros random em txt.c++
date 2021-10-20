#include <iostream>
#include <fstream>
#include<time.h>
#include<cstdlib>

using namespace std;

int main () {
  ofstream arquivo;
  arquivo.open ("data.txt");

  cout<<"\n Insira a quantidade de linhas totais: ";
  int linhas;
  cin>>linhas;

  cout<<"\n Insira o valor maximo dos numeros: ";
  int valMax = 1000;
  cin>>valMax;

  srand (time(NULL));

  for(int x=0; x<linhas; x++) {
    int num = rand() % valMax;
    arquivo << num <<"\n";
  }
  cout<<"Adicionado";

  arquivo.close();

  return 0;
}
