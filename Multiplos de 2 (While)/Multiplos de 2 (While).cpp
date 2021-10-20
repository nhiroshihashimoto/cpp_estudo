#include<iostream>
#include<stdlib.h>

using namespace std;

main(){
	int soma=0,cont=0;
	
	while(cont<50){
		soma=soma+cont;
		cont=cont+2;
		cout<<"cont: "<<cont<<endl<<"soma: "<<soma<<endl;
	}
	
	system("PAUSE");
}
