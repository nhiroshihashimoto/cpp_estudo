#include<iostream>
using namespace std;

struct Nodo {
	int info;
	struct Nodo *prox;
	};

struct ListaSimplesEnc {
	struct Nodo *prim;
	};

void criarLista (struct ListaSimplesEnc *pList) {
	pList -> prim = NULL;
	}
	
void mostrarLista (struct ListaSimplesEnc *pList){
	struct Nodo *p;
		for (p = pList -> prim; p != NULL; p = p->prox) {
		cout << p->info << endl;
		}

	cout << endl;
	}

void inserirIni (struct ListaSimplesEnc *pList, int v){
	struct Nodo *novo;
	novo =  new Nodo;
	novo -> info = v;
	novo -> prox = pList -> prim;
	pList -> prim = novo;
	}

void removerIni (struct ListaSimplesEnc *pList){
	struct Nodo *pAux = pList -> prim;
	pList -> prim = pList -> prim -> prox;
	delete(pAux);
	}

void inserirOrd (struct ListaSimplesEnc *pList, int v){
	struct Nodo *novo;
	novo =  new  Nodo;
	novo -> info = v;
	struct Nodo *pAtu, *pAnt;
	pAnt = NULL;
	pAtu = pList -> prim;
		while ( pAtu != NULL && pAtu->info < v){
		pAnt = pAtu;
		pAtu = pAtu -> prox;
		}

novo -> prox = pAtu -> prox;
pAnt -> prox = novo;
}
	
int estaVazia(struct ListaSimplesEnc *pList) {
return (pList->prim == NULL);
}

int main () {
struct ListaSimplesEnc minhaLista;
int valor, op;
criarLista(&minhaLista);
	while( op!=6 ){
	cout << "1 - Inserir elemento no inicio\n";
	cout << "2 - Inserir elemento em ordem (so se a lista estiver ordenada)\n";
	cout << "3 - Remover elemento no inicio\n";
	cout << "4 - Remover elemento\n";
	cout << "5 - Mostrar lista\n";
	cout << "6 - Sair\n";
	cout << "Opcao?\n";
	cin >> op ;
	
		switch( op ){
			
		case 1: // inserir elemento no inicio
			cout << "Valor: ";
			cin >> valor ;
			inserirIni(&minhaLista, valor);
			break;
		case 2: // inserir elemento ordenado
			cout << "Valor: " ;
			cin >> valor ;
			inserirOrd(&minhaLista, valor);
			break;
		case 3: // remover o primeiro
			removerIni(&minhaLista);
			break;
		case 4: // remover determinado elemento
			break;
		case 5: // mostrar lista
			if (estaVazia(&minhaLista)) {
			cout << "Lista vazia" << endl;
			}
			else {
			mostrarLista(&minhaLista);
			}
		break;
		case 6: // abandonar o programa
		exit(0);
		}
	}
	return 0;
}

