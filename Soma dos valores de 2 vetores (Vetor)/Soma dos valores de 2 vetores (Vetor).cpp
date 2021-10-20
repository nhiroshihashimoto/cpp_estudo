#include<iostream>
#include<stdlib.h>
#define tam 2

using namespace std;

main(){
	int vetor1[tam];
	int vetor2[tam];
	int vetor3[tam];
	int i;
	int num=1;
	
	for (i=0;i<tam;i++){
		cout<<"Insira o valor para o primeiro vetor do numero " <<num<< " : "<<endl;
		cin>>vetor1[i];
		num++;
		}

num=1;

	for (i=0;i<tam;i++){
		cout<<"Insira o valor para o segundo vetor do numero " <<num<< " : "<<endl;
		cin>>vetor2[i];
		num++;
		}
		
		for(i=0;i<tam;i++){
		vetor3[i]=vetor1[i]+vetor2[i];
		}
		
		num=1;
		
	for(i=0;i<tam;i++){
				//cout<<"Os valores inseridos sao :" <<vetor[i]<<endl;
				cout<<"Resultado "<<num<<": | "<<vetor3[i]<<endl;
				num++;
				}
	
	system("PAUSE");
}
