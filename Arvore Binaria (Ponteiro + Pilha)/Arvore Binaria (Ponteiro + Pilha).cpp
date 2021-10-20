#include <iostream>
#include <conio.h>
#include <locale.h>

using namespace std;

//Definindo o regristro que representara cada elemento da arvore binaria

struct ARVORE{
	int num;
	ARVORE *esq, *dir;
};

//Definindo o registro que representara cada elemento da arvore binaria na pilha

struct PILHA{
	ARVORE *num;
	PILHA *prox;
};

int inserir(){
	
}

int main() {
	std:setlocale(LC_ALL, "Portuguese"); //Define a linguagem do console de aplicacao para portugues.
	//a arvore esta vazia, logo o ponteiro raiz tem o valor null
	ARVORE *raiz = NULL;
	//o ponteiro aux e um ponteiro auxiliar
	ARVORE *aux;
	//o ponteiro novo e um ponteiro auxiliar
	ARVORE *novo;
	//o ponteiro topo representa o topo da pilha
	PILHA *topo;
	//o ponteiro aux_pilha e um ponteiro auxiliar da pilha
	PILHA *aux_pilha;
	//apresentando o menu de opcaes
	int op, achou, numero;
	do{
			cout << "\nDigite o numero a ser inserido na arvore: ";
			novo = new ARVORE(); //cria arvore
			cin >> novo->num;
			novo->dir = NULL;
			novo->esq = NULL;
			if (raiz == NULL)
				raiz = novo;
			else{
				aux=raiz;
				achou=0;
				while (achou==0){
					if(novo->num < aux->num){
						if (aux->esq==NULL){
							aux->esq=novo;
							achou=1;
						}
						else aux = aux->esq;
					}
					else if (novo->num>=aux->num){
						if (aux->dir==NULL){
							aux->dir=novo;
							achou=1;
						}
						else aux = aux->dir;
					}
				} 
		}
	cout << "\n Insira um numero para adicionar na arvore.\n";
	cout << "\n Insira 0 para finalizar insercao!!\n";
	cin >> op;
		
	getch();
	} while (op !=0);
	// mostra itens na arvore ordenado;
		if (raiz == NULL){ 
					//a arvore esta vazia
					cout << "\narvore vazia!!\n";
				}
				else{
					//a arvore contem elementos e estes serao mostrados em ordem
					cout << "\nListando todos os elementos da arvore em ordem:\n";
					aux = raiz;
					//a pilha, uma estrutura auxiliar esta vazia
					topo = NULL;
					do{
						//caminha na arvore pelo ramo da esquerda ate NULL
						//colocando cada elemento visitado em uma PILHA
							while (aux!=NULL){
								aux_pilha = new PILHA();
								aux_pilha->num = aux;
								aux_pilha->prox = topo;
								topo = aux_pilha;
								aux=aux->esq;
							}
							if (topo !=NULL){
								aux_pilha=topo;
								cout << aux_pilha->num->num<< "  ";
								aux = topo->num->dir;
								topo = topo->prox;
							}
					} while (topo !=NULL || aux !=NULL);
				}
}

