#include<iostream>
#include<stdlib.h>
#define tam 5

using namespace std;

main(){
	float vetor[tam];
	int i;
	int num=1;
	
	cout<<"Insira as notas de 5 alunos de uma turma para saber a media."<<endl;
	
	
	for(i=0;i<tam;i++){
		cout<<"Insira a nota "<<num<<endl;
		cin>>vetor[i];
		num++;
	}
	
	num=1;
	
	for(i=0;i<tam;i++){
		cout<<"Nota "<<num<<" : "<<vetor[i]<<endl;
		num++;
	}
	
	num=1;

	float media=0;
	
	for(i=0;i<tam;i++){
		media=media+vetor[i];
	}
	
	media=media/5;
	
	cout<<"A media e: "<<media<<endl;
		
	system("PAUSE");
}
