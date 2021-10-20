#include<iostream>
#include<stdlib.h>
#define tam 5

using namespace std;

main(){
	int vetor[tam];
	int numero;
	int i=0;
	cout<<"Somente os 5 primeiros numeros impares fornecidos serao armazenados."<<endl;
	
	while(i<tam){
	cout<<"Informe um numero impar: ";
	cin>>numero;
		if(numero%2!=0){
		vetor[i]=numero;
		i++;
		}
}
	for(i=0;i<tam;i++){
	cout<<"Numero "<<i+1<<" : "<<vetor[i]<<endl;
	}
	
		system("PAUSE");
}
