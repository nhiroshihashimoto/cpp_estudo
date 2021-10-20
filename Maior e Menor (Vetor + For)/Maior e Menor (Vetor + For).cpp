#include<iostream>
#include<stdlib.h>
#define tam 5

using namespace std;

main(){
	int vetor[tam];
	int i;
	cout<<"Insira 5 numeros para identificar qual o maior e o menor."<<endl;
		//Codigo para maior e menor.
	for (i=0;i<tam;i++){
		cout<<"Insira o numero " <<i+1<< " :"<<endl;
		cin>>vetor[i];
		}
	
	int maior=vetor[0];
	int menor=vetor[0];
	
		for(i=0;i<tam;i++){
			if(vetor[i]>maior){
			maior=vetor[i]; 
			}
			}
			
		for(i=0;i<tam;i++){
			if(vetor[i]<menor){
			menor=vetor[i]; 
			}
			}
		
			cout<<"O numero maior digitado e: "<<maior<<endl;
			cout<<"O numero menor inserido e: "<<menor<<endl;

	
	system("PAUSE");
}
