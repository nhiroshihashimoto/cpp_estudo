#include<iostream>
#include<stdlib.h>

using namespace std;

main(){
	int tam;
	int i;
	
	cout<<"Informe o tamanho do vetor: "<<endl;
	cin>>tam;
	
	int vetor[(tam)];
	
	
	for(i=0;i<tam;i++){
		cout<<"Insira o vetor de numero "<<i+1<<" ."<<endl;
		cin>>vetor[i];
	}
	
	for(i=0;i<tam;i++){
		cout<<"Valor "<<i+1<<" : "<<vetor[i]<<endl;
	}
		system("PAUSE");
}
