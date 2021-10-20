#include<iostream>
#include<stdlib.h>
#define tam 15

using namespace std;

main(){
	int vetor[tam];
	int i;
	
	for (i=0;i<tam;i++){
		cout<<"Insira o vetor " <<i<< " : "<<endl;
		cin>>vetor[i];
		}
			for(i=14;i>=0;i--){
				//cout<<"Os valores inseridos sao :" <<vetor[i]<<endl;
				cout<<" | "<<vetor[i]<< " | ";
				}
	

	
	system("PAUSE");
}
