// Sub menu cliente COMPLETO;
// sub menu produto 0% - adptar funcao cliente; 
// Submenu vender 0% - consultar codigo cliente, consultar produto, criar lista de produtos com o cod do cliente;
// Opcao consultar 0% - criar historico e calcular valores de produtos vendidos
// menu principal 25% - falta produto, vender e consultar ;

#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;

//ESCOPO GLOBAL

	int op, escolha;
	float total;
	unsigned int codigo;
	float codigo2;
	int cod_cliente=1;
	int cod_produto=1;
	int cod_venda1=1;
	


	//estrutura lista 
	
			struct Lista_cliente{struct cliente *prim;};	// no com as info do primeiro cliente
			struct Lista_produto{struct produto *prim;};	// no com as info do primeiro produto
			struct Lista_venda{struct venda *prim;};		// no com as info da primeira venda
			struct Lista_item{struct item *prim;};			// no com as info do primeiro item
			
			Lista_cliente dados_cliente;
			Lista_produto dados_produto;
			Lista_venda dados_venda;
			Lista_item dados_item;
			
//Estruturas
		struct cliente{// campos para cliente
			int cod;
			string nome; // info dos clientes
			struct cliente *prox;	};	//ponteiro que aponta para proximo cliente
				
		struct produto{// campos para produto
			int cod;
			string nome;
			int quantidade;
			float valor;
			struct produto *prox;	};	//ponteiro que aponta para o proximo produto
				
		struct venda{// campos para venda
			int cod;
			int cod_cliente;
			string nome_cliente;
			struct venda *prox;		};	//ponteiro que aponta para a proxima venda
				
		struct item{// campos para item
		
			int cod;
			int cod_venda;
			int cod_cliente;
			string nome_cliente;
			int cod_produto;
			string nome_produto;
			int quantidade;
			float valor;
			float total;
			
			struct item *prox;	};		//ponteiro que aponta para o proximo item da venda
		
	
//Listas
	//estrutura para checar se a lista esta vazia
		int List_vazia_cliente (Lista_cliente *pAtual){return pAtual->prim ==  NULL;}
		int List_vazia_produto (Lista_produto *pAtual){return pAtual->prim ==  NULL;}
		int List_vazia_venda (Lista_venda *pAtual){return pAtual->prim ==  NULL;}
		int List_vazia_item (Lista_item *pAtual){return pAtual->prim ==  NULL;}


//Declaramento de fun��es que existem
		void menu_prin();
		void menu2();
		void menu3();
		void menu4();
		void menu_aux();

		
//Funcao limpar tela
		void limpar(){ system ("pause"); system ("cls"); }
		
//CLIENTE
	//Funcao Inserir para cliente
		
		void inserir_cliente(struct Lista_cliente *pAtual, string n){ // cria ponteiro pAtual
			cliente *novo; //Um novo No vazio para ser inserido
			novo = new cliente;
			novo->nome = n;
			novo->cod = cod_cliente;
			novo->prox = pAtual->prim; // O endereco do prox no novo no recebe o endereco de inicio da lista
			pAtual->prim = novo;//O inicio da lista recebe o novo no como inicio
		}//fim void
	
	// Funcao Excluir
		void excluir_cliente(struct Lista_cliente *pAtual){ // cria ponteiro pAtual
     		codigo = 0;
    		cliente *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
    		cliente *atual= pAtual->prim;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
    		cout<<"  Codigo do cliente que deseja  excluir: "<<endl<<"*:";
    		cin>>codigo;
    			
    		//Procurando o cliente na lista.
     		while(atual != NULL && atual->cod != codigo){
						anterior = atual;
    				    atual = atual->prox;
    			}//fim while
			
			//Mensagem caso o cliente nao seja encontrado.
    		if(atual==NULL){
			   	cout<<"\n                           Cliente nao encontrado."<<endl<<endl<<endl; 
    			system("pause");
				menu2();
    		}//fim if
     
    		//Excluindo o primeiro cliente da lista.   
    		if(anterior == NULL){
				cout<<"\n  Conteudo excluido com sucesso."<<endl; 
        		pAtual->prim = atual->prox;
	 		//Excluindo um cliente do meio da lista.
     		}else{
				cout<<"\n  Conteudo excluido com sucesso."<<endl; 
				anterior->prox = atual->prox;
    		}//fim if
     
    		//Desalocando o espaco da memoria.
    		delete atual;
		}//fim void
	
	//Funcao alterar 
	
		void alterar_cliente(struct Lista_cliente *pAtual){
			string nome_substituto; 
		    cliente *atual= pAtual->prim;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
	    	cout<<"  Codigo do Cliente que deseja  alterar: "<<endl<<"*:";
    		cin>>codigo;
	  		//Procurando o cliente na lista.
	    	while(atual != NULL && atual->cod != codigo){
    				    atual = atual->prox;
    			}//fim while
     
   			//Alterando os dados do Cliente.
     		if( atual != NULL){
        		cout<<"\n  Novo nome: "<<endl<<"*:";
        		cin>>nome_substituto; 
        		atual->nome = nome_substituto;
        		cout<<"  Dados alterados com sucesso."<<endl;
			}else{
				cout<<"\n  Cliente nao encontrado."<<endl;
     		}
		}
	// Funcao consultar	

		void Consultar_cliente (struct Lista_cliente *pAtual) {
		 	cliente *p;
			 for (p=pAtual->prim; p!= NULL; p=p->prox) {
				cout<<"\nCodigo do cliente: ";
				cout<< p->cod;
 				cout<<"\nNome: ";
 				cout<< p->nome <<endl;
 				cout<<"----------------------------------------------------";
			}//fim for
			cout<<endl;
		}//fim void


//produto

	//Funcao Inserir Produto
		void inserir_produto(struct Lista_produto *pAtual, string n, int quant, float v){ // cria ponteiro pAtual
			produto *novo; //Um novo No vazio para ser inserido
			novo = new produto;
			novo->nome = n;
			novo->cod = cod_produto;
			novo->quantidade = quant;
			novo->valor = v;
			novo->prox = pAtual->prim;	// O endereco do prox no novo no recebe o endereco de inicio da lista
			pAtual->prim = novo;	//O inicio da lista recebe o novo no como inicio
		}//fim void
	
	// Funcao Excluir

		void excluir_produto(struct Lista_produto *pAtual){ // cria ponteiro pAtual
     		codigo = 0;
    		produto *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
    		produto *atual= pAtual->prim;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
    		cout<<"  Codigo do Produto que deseja  excluir: "<<endl<<"*:";	//Requisitando e lendo o codigo do Produto a ser excluido.
    		cin>>codigo;
    
    		//Procurando o Produto na lista.
     		while(atual != NULL && atual->cod != codigo){
						anterior = atual;
    				    atual = atual->prox;
    			}//fim while
			
			//Mensagem caso o Produto nao seja encontrado.
    		if(atual==NULL){
			   	cout<<"\n                           Produto nao encontrado."<<endl<<endl<<endl; 
    			system("pause");
				menu3();
    		}//fim if
     
    		//Excluindo o primeiro Produto da lista.   
    		if(anterior == NULL){
				cout<<"\n  Conteudo excluido com sucesso."<<endl; 
        		pAtual->prim = atual->prox;
	 		//Excluindo um Produto do meio da lista.
     		}else{
        
				cout<<"\n  Conteudo excluido com sucesso."<<endl; 
				anterior->prox = atual->prox;
    		}//fim if
     
    		//Desalocando o espaco da memoria.
    		delete atual;
		}//fim void
	
	//Funcao alterar 
	
		void alterar_produto(struct Lista_produto *pAtual){
			string nome_substituto;
			int quantidade_substituto;
			float valor_substituto; 
		    produto *atual= pAtual->prim;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
		    //Requisitando e lendo o codigo do Produto a ser alterado.
	    	cout<<" Insira o codigo do Produto que deseja alterar: "<<endl<<"*:";
    		cin>>codigo;
    
	  		//Procurando o Produto na lista.
	    	while(atual != NULL && atual->cod != codigo){
    				    atual = atual->prox;
    			}//fim while
     
   			//Alterando os dados do Produto.
     		if( atual != NULL){

 			cout<<"\nNome do Produto: ";
 			cout<< atual->nome;
 			cout<<" ( Codigo: " << atual->cod<<" )";
 			cout<<"\nQuantidade em estoque: ";
			cout<< atual->quantidade;
			cout<<"\nValor unitario: R$ ";
			cout<< atual->valor;
 			cout<<"\n----------------------------------------------------\n";
     			
					menu_aux();
					if(op == 1){
						cout<<"\n  Alterar nome: "<<endl<<"*:";
        				cin>>nome_substituto; 
        				atual-> nome = nome_substituto;
        		
					}else{
						if(op == 2){
							cout<<"\n  Alterar Quantidade: "<<endl<<"*:";
        					cin>>quantidade_substituto; 
        					atual->quantidade = quantidade_substituto;
						}else{
						
							if(op==3){
								cout<<"\n  Alterar Valor unitario: "<<endl<<"*:";
        						cin>>valor_substituto; 
        						atual->valor = valor_substituto;
							}
						}
				
					}
        		cout<<"  Dado alterado com sucesso."<<endl;
        	}else{
				cout<<"\n  Produto nao encontrado."<<endl;
     		}
		}
	
	// Funcao consultar

		void Consultar_produto (struct Lista_produto *pAtual) {
		 	produto *p;
			 for (p=pAtual->prim; p!= NULL; p=p->prox) {
 				cout<<"\nNome: ";
 				cout<< p->nome;
 				
				cout<<" ( Codigo: " << p->cod<<" )"<<endl;
				
 				cout<<"Quantidade em estoque: ";
				cout<< p->quantidade <<endl;
				cout<<"Valor unitario: R$ ";
				cout<< p->valor <<endl;
 				cout<<"\n----------------------------------------------------"<<endl;
			}//fim for
		}//fim void



//Venda

	//Funcao Inserir Venda	
		
		int cliente_cod_temporario;
		string cliente_nome_temporario;
		int cod_venda_temporario;
		
		void Consultar_cliente2 (struct Lista_cliente *pAtual ) {
				codigo=0;
			    cliente *atual= pAtual->prim;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
		    	
		    	do{
				cout<<"  Insira o codigo do cliente: "<<endl<<"*:";
	    		cin>>codigo;
		  		//Procurando o cliente na lista.
		    	while(atual != NULL && atual->cod != codigo){
	    				    atual = atual->prox;
	    			}//fim while
	    			
	    			if(atual==NULL){
	    				system("cls");
					   	cout<<"\n                           Cliente nao encontrado ou inexistente."<<endl; 
					   	cout<<"\n                              Insira valor 0 para voltar."<<endl<<endl<<endl; 
		    		}
		    	
		    	if(codigo==0){
		    		system("cls");
		    		menu4();
		    	}
		    	
		    	
		    	}while(atual==NULL);
					cout<<endl;
				
				cliente_cod_temporario = atual -> cod;
				cliente_nome_temporario = atual -> nome;
		}
		

		void inserir_venda(struct Lista_venda *pAtual){ // cria ponteiro pList
				venda *novo; //Um novo No vazio para ser inserido
				novo = new venda;
				novo->cod = cod_venda1;
				cod_venda_temporario = novo->cod;
				novo->cod_cliente = cliente_cod_temporario;
				novo->nome_cliente = cliente_nome_temporario;
				// O endereco do prox no novo no recebe o endereco de inicio da lista
				novo->prox = pAtual->prim;
				
				//O inicio da lista recebe o novo no como inicio
				pAtual->prim = novo;
				}//fim void
		

//Lista de itens por venda

//Funcao Inserir item

		int produto_cod_temporario;
		string produto_nome_temporario;
		int produto_quantidade_temporario;
		float produto_valor_temporario;
		float total_venda;
		
		
		void Consultar_produto2 (struct Lista_produto *pAtual ){
				
				codigo=0;
				string nome_substituto; 
			    produto *atual= pAtual->prim;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
			    
			
			    	do{
				    	cout<<"  Insira o codigo do produto: "<<endl<<"*:";
			    		cin>>codigo;
				  		//Procurando o cliente na lista.
				    	while(atual != NULL && atual->cod != codigo){
			    				    atual = atual->prox;
			    		}//fim while
			    		if(atual==NULL){
			    			system("cls");
								   	cout<<"\n                           Produto nao encontrado ou inexistente."<<endl; 
								   	system("pause");
								   	menu4();
					    	}
			    			
	    				}while(atual==NULL);		  
						  		
	    	do{
	    			
	    		cout<<"  Insira a quantidade: "<<endl<<"*:";
	    		cin>>codigo2;
	    			
	    		if(atual->quantidade < codigo2){
	    			cout<<"  Nao possui essa quantidade em estoque.\n\n "<<endl;
	    			system("PAUSE");
	    			}
	    			
	    	}while(atual->quantidade < codigo2);
						cout<<endl;
						
				produto_cod_temporario = atual -> cod;
				produto_nome_temporario = atual -> nome;
				produto_quantidade_temporario = codigo2;
				produto_valor_temporario = atual -> valor;
				
		}
		

		
		void inserir_item(struct Lista_item *pAtual ){ // cria ponteiro pAtual
			item *novo; //Um novo No vazio para ser inserido
			novo = new item;
			
			
			novo->cod_venda = cod_venda1;
			
			novo->cod_cliente = cliente_cod_temporario;
			novo->nome_cliente = cliente_nome_temporario;
			
			novo->cod_produto = produto_cod_temporario;
			novo->nome_produto = produto_nome_temporario;
			novo->quantidade = produto_quantidade_temporario;
			novo->valor = produto_valor_temporario;
			
			novo->total = novo->quantidade*novo->valor;
			
			
			// O endereco do prox no novo no recebe o endereco de inicio da lista
			novo->prox = pAtual->prim;
			//O inicio da lista recebe o novo no como inicio
			pAtual->prim = novo;
		}//fim void


void Consultar_item (struct Lista_item *pAtual) {
		 	item *p;
		 	
		 	total_venda=0;
				
			 for (p=pAtual->prim; p!= NULL; p=p->prox) {
			 	
		 		if(p->cod_venda==cod_venda1){
				
 				cout<<"\n----- | ";
 				cout<< p->nome_produto;
 				
 				cout<<" ( Codigo: " << p->cod_produto << " )";
 				
 				cout<<"  |  ----- Quantidade: ";
				cout<< p->quantidade;
				
				cout<<"  |  Valor unitario: R$ ";
				cout<< p->valor;
				
				cout<<"  |  Total: R$ ";
				cout<< p->total <<endl;
				
 				total_venda=total_venda+p->total;
 				
				}
				
			}//fim for
				cout<<"\n--------- Total: R$ ";
				cout<< total_venda;
				cout<<"\n\n----------------------------------------------------\n";
		}//fim void
		
		
		
	void excluir_item(struct Lista_item *pAtual){ // cria ponteiro pAtual
     		codigo=0;
    		item *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
    		item *primeiro = pAtual->prim;//Ponteiro que define primeiro endereco
    		item *atual= pAtual->prim;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
    		
    		if(atual==NULL){
    			system("cls");
    			cout<<"\n\n                          Inclua um produto antes.\n\n";
    			limpar();
				menu4();
    		}
    		
    		for (atual=pAtual->prim; atual!= NULL; atual=atual->prox) {
			 	
		 		if(atual->cod_venda==cod_venda_temporario){
				
				cout<<"\nNome do item: "<<atual->nome_produto <<" ( Codigo: "<<atual->cod_produto<<" )"<<endl;
 				
 				cout<<"Quantidade inserida: ";
				cout<< atual->quantidade <<endl;
				
				cout<<"Valor: R$ ";
				cout<< atual->valor <<endl;
				
				cout<<"\nTotal: R$ ";
				cout<< atual->total <<endl;
				
 				cout<<"\n----------------------------------------------------";
				cout<<endl;
				}
			}
			
			atual=primeiro;
			
    		cout<<"  Codigo do item que deseja excluir: "<<endl<<"*:";	//Requisitando e lendo o codigo do Produto a ser excluido.
    		cin>>codigo;
    
    		//Procurando o Produto na lista.
     		while(atual != NULL && atual->cod_produto != codigo){
						anterior = atual;
    				    atual = atual->prox;
    			}//fim while
    			
			
			//Mensagem caso o Produto nao seja encontrado.
    		if(atual->cod_produto!=codigo){
    			system("cls");
								   	cout<<"\n                           Item nao encontrado ou inexistente."<<endl; 
								   	menu4();
    		}//fim if
    		
			system("cls");
     
 				cout<<"\nNome do item: "<<atual->nome_produto<<" ( Codigo: "<<atual->cod_produto<<" )"<<endl;
 				
 				cout<<"Quantidade inserida: ";
				cout<< atual->quantidade <<endl;
				
				cout<<"Valor unitario: R$ ";
				cout<< atual->valor <<endl;
				
				cout<<"\nTotal: R$ ";
				cout<< atual->total <<endl;
				
 				cout<<"\n----------------------------------------------------\n\n";
				cout<<endl;
								
     		do{
			 	cout<<"\nDeseja excluir este item? 1 - SIM | 2 - NaO "<<endl<<endl<<endl; 
     			cin>>op;
     			
     			switch (op){
		
					case 1:
							//Excluindo o primeiro Produto da lista.   
				    		if(anterior == NULL){
								cout<<"\n                        Item excluido com sucesso."<<endl; 
				        		pAtual->prim = atual->prox;
				        		system("PAUSE");
					 		//Excluindo um Produto do meio da lista.
				     		}else{
				        
								cout<<"\n                        Item excluido com sucesso."<<endl; 
								anterior->prox = atual->prox;
								system("PAUSE");
				    		}//fim if
				     
				    		//Desalocando o espaco da memoria.
				    		delete atual;
				    		
				    		total_venda=0;
				    		
				    		menu4();
				    		
							break;
					case 2:
						menu4();
							break;
		     		default:
                 		cout<<"Opcao invalida"<<endl;
	                	system("pause");
				    		
				}//fim void
				
			}while (op!=2);
	}	


			void cancelar_venda(struct Lista_venda *pAtual){
				
			venda *primeiro = pAtual->prim;
			venda *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
    		venda *atual= pAtual->prim;
    		
				if(atual==NULL){
							delete(pAtual);
							cout<<"venda deletada2";
							system("pause");
				}
    		
    			if(atual!=primeiro){

		    		while(atual != pAtual->prim){
								anterior = atual;
		    				    atual = atual->prox;
		    					    				 
		    				
		    					if(anterior == NULL){
					        		pAtual->prim = atual->prox;
					     		}
								else{
									anterior->prox = atual->prox;
					    		}//fim if
					    		delete(atual);
					    		
					    	cout<<"venda deletada";
							system("pause");
					}
				}
							total_venda=0;
				    		cliente_cod_temporario=0;
				    		cod_venda_temporario=0;
				    		cliente_nome_temporario='\0';
				    		produto_cod_temporario=0;
				    		produto_nome_temporario='\0';
				    		produto_quantidade_temporario=0;
				    		produto_valor_temporario=0;
			}
			
			void cancelar_item(struct Lista_item *pAtual){
				
				item *primeiro = pAtual->prim;
				item *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
    			item *atual= pAtual->prim;
    			
				if(primeiro==NULL){
						delete(pAtual);
						cout<<"itens deletados2";
							system("pause");
				}
    			
    			if(atual!=primeiro){

		    		while(atual != pAtual->prim){
								anterior = atual;
		    				    atual = atual->prox;
		    				
		    				cout<<"itens deletados";
							system("pause");
		    				    
		    				
		    				if(anterior == NULL){
					        		pAtual->prim = atual->prox;
					     		}
								else{
									anterior->prox = atual->prox;
					    		}//fim if
					    		delete(atual);
					    		
    						cout<<"itens deletados";
							system("pause");
					    	
					}
					
				}


							total_venda=0;
				    		cliente_cod_temporario=0;
				    		cod_venda_temporario=0;
				    		cliente_nome_temporario='\0';
				    		produto_cod_temporario=0;
				    		produto_nome_temporario='\0';
				    		produto_quantidade_temporario=0;
				    		produto_valor_temporario=0;
			}
			
			
			void concluir_venda(){
							total_venda=0;
				    		cliente_cod_temporario=0;
				    		cod_venda_temporario=0;
				    		cliente_nome_temporario='\0';
				    		produto_cod_temporario=0;
				    		produto_nome_temporario='\0';
				    		produto_quantidade_temporario=0;
				    		produto_valor_temporario=0;
			}
			
			void total_vendas(struct Lista_item *pAtual){
					item *p;
				
				for (p=pAtual->prim; p!= NULL; p=p->prox) {
					
	 				cout<<"\nVenda de codigo : ";
	 				cout<< p->cod_venda;
	 				
	 				cout<<"\nCliente :";
	 				cout<< p->nome_cliente;
	 				
					cout<<"Total da venda: R$";
					cout<< p->total <<endl<<endl;
					
					cout<<"_______________________\n\n";
	 				total_venda=total_venda+p->total;
	 				
					}
					
				cout<<"\n\n  |  Total Geral: R$";
	 				cout<<total_venda<<endl;
			}
				
				


int main(){	
	
	int quantidade;
	
	float valor;
	
	menu_prin();
}

//menu principal

void menu_prin(){
	do{
		system("cls");
	
		cout<<"                                         ______________________________"<<endl;
		cout<<"                                        |        MENU PRINCIPAL        |"<<endl;
        cout<<"                                        |                              |"<<endl;
		cout<<"                                        |       1 - Cliente            |"<<endl;
		cout<<"                                        |       2 - Produto            |"<<endl;
		cout<<"                                        |       3 - Venda              |"<<endl;
		cout<<"                                        |       4 - Total vendas       |"<<endl;
		cout<<"                                        |       5 - Sair               |"<<endl;
		cout<<"                                        |                              |"<<endl;
		cout<<"                                        |______________________________|"<<endl;
	
		setlocale(LC_ALL, "Portuguese");
		cout<<endl<<endl<<" Escolha uma opcao:"<<endl<<"*:";
		cin>>op;
			system ("cls");
	
		switch (op){
		
			case 1:
				menu2();
					break;
			case 2:
				menu3();
					break;
			case 3:
				menu4();
					break;
			case 4:
                 cout<<"Total da vendas:"<<total<<endl;
                 total_venda=0;
                 total_vendas(&dados_item);
                 limpar();
					break;
			case 5:
				cout<<"FIM DO PROGRAMA"<<endl;
				exit(0);
					break ;
			default:
                 cout<<"Opcao invalida"<<endl;
	                 system("pause");
		}
	}
	while (op!=5);
}

//Menu do cliente
void menu2(){
	
	escolha = 1;

	string nome_cliente;
	
	bool confirmacao;
	
	do{
		
		cout<<"                                         ______________________________"<<endl;
		cout<<"                                        |            CLIENTE           |"<<endl;
        cout<<"                                        |                              |"<<endl;
		cout<<"                                        |       1 - Incluir            |"<<endl;
		cout<<"                                        |       2 - Excluir            |"<<endl;
		cout<<"                                        |       3 - Alterar            |"<<endl;
		cout<<"                                        |       4 - Consultar          |"<<endl;
		cout<<"                                        |       5 - Voltar ao menu     |"<<endl;
		cout<<"                                        |                              |"<<endl;
		cout<<"                                        |______________________________|"<<endl;
	
		cout<<endl<<" Escolha uma opcao:"<<endl<<"*:";
		cin>>op;
		system("cls");
	
		switch (op){
		
			case 1:
				do{
				
					cin.ignore();
					cout<<"Nome Cliente:"<<endl;
					getline(cin, nome_cliente);
				
					inserir_cliente ( &dados_cliente, nome_cliente);
					
					cout<<"\n\n\n                          Cadastro concluido !!";
					cout<<"\n\n\n                   Deseja cadastrar mais um cliente?"<<endl;
					cout<< "                         Sim = 1  Nao = 0"<<endl;
					cin>>confirmacao;
					cod_cliente++;
					system("cls");
				}while(confirmacao == true);
				
					break;
		
			case 2:
				do{				
					excluir_cliente( &dados_cliente );
					cout<<"\n\n\n                   Deseja Excluir mais um cliente?"<<endl;
					cout<< "                         Sim = 1  Nao = 0"<<endl;
					cin>>confirmacao;
						system ("cls");
				}while(confirmacao == true);  
					break;
		
			case 3:
			     do{		
					alterar_cliente( &dados_cliente );
					cout<<"\n\n\n                   Deseja alterar mais um cliente?"<<endl;
					cout<< "                         Sim = 1  Nao = 0"<<endl;
					cin>>confirmacao;
						system ("cls");
				}while(confirmacao == true);
					break;
		
			case 4:
				if ( List_vazia_cliente ( &dados_cliente ) ) {
						cout <<"\nCadastre um cliente para executar esta funcao.\n\n";
						limpar();
						menu2();
					}else {
						Consultar_cliente (&dados_cliente);
						limpar();
					}
						break;
			
			case 5:
				menu_prin();
					break ;
			default:
			 cout<<"Opcao invalida"<<endl;
			system("pause");
		}
	}while (op!=5);
}

//Menu Produto
void menu3(){
	
	escolha = 2;

	string nome_produto;
	
	int quantidade;
	float valor;
	
	bool confirmacao;
	

	
	do{
		
		cout<<"                                         ______________________________"<<endl;
		cout<<"                                        |            PRODUTO           |"<<endl;
        cout<<"                                        |                              |"<<endl;
		cout<<"                                        |       1 - Incluir            |"<<endl;
		cout<<"                                        |       2 - Excluir            |"<<endl;
		cout<<"                                        |       3 - Alterar            |"<<endl;
		cout<<"                                        |       4 - Consultar          |"<<endl;
		cout<<"                                        |       5 - Voltar ao menu     |"<<endl;
		cout<<"                                        |                              |"<<endl;
		cout<<"                                        |______________________________|"<<endl;
	
		cout<<endl<<" Escolha uma opcao:"<<endl<<"*:";
		cin>>op;
		system("cls");
	
		
		switch (op){
		
			case 1:
				do{
					cin.ignore();
					cout<<"Nome Produto:"<<endl;
					getline(cin, nome_produto);
					cout<<endl;
					
					cout<<"Quantidade inicial em estoque:"<<endl;
					cin>>quantidade;
					cout<<endl;
					
					cout<<"Valor:\nR$";
					cin>>valor;
					cout<<endl;
				
					inserir_produto ( &dados_produto, nome_produto, quantidade, valor);
					
					cod_produto++;
					
					cout<<"\n\n\n                          Cadastro concluido !!";
					cout<<"\n\n\n                   Deseja cadastrar mais um Produto?"<<endl;
					cout<< "                         Sim = 1  Nao = 0"<<endl;
					cin>>confirmacao;
					system("cls");
				}while(confirmacao == true);
				
			break;
		
			case 2:
				do{
								
					excluir_produto( &dados_produto );
					
					cout<<"\n\n\n                   Deseja Excluir mais um Produto?"<<endl;
					cout<< "                         Sim = 1  Nao = 0"<<endl;
					cin>>confirmacao;
					
					system("cls");
					
				}while(confirmacao == true);
			break;
		
			case 3:
			
			     do{	
								
					alterar_produto( &dados_produto );
					
					cout<<"\n\n\n                   Deseja alterar mais um Produto?"<<endl;
					cout<< "                         Sim = 1  Nao = 0"<<endl;
					cin>>confirmacao;
					
					system("cls");
					
				}while(confirmacao == true);
			break;
		
			case 4:
				if ( List_vazia_produto ( &dados_produto ) ) {
						cout <<"\nLista vazia\n";
						limpar();
						menu2();
					}else {
						Consultar_produto (&dados_produto);
						limpar();
					}
					
			break;
			
			case 5:
				menu_prin();
			break ;
		
			default:
			
			 cout<<"Opcao invalida"<<endl;
		 
			system("pause");
		}
	} 
	
	while (op!=5);	
}

void menu4(){
	
	escolha = 3;
	system("cls");
	bool confirmacao;
	
	do{
		
		cout<<"                                         ______________________________"<<endl;
		cout<<"                                        |             VENDA            |"<<endl;
        cout<<"                                        |                              |"<<endl;
		cout<<"                                        |       1 - Incluir cliente    |"<<endl;
		cout<<"                                        |       2 - Incluir item       |"<<endl;
		cout<<"                                        |       3 - Excluir item       |"<<endl;
		cout<<"                                        |       4 - Concluir venda     |"<<endl;
		cout<<"                                        |     ----------------------   |"<<endl;
		cout<<"                                        |       5 - Cancelar           |"<<endl;
		cout<<"                                        |______________________________|"<<endl;
	
		if(cliente_cod_temporario!=0){cout<<"--------- Nome do cliente: "<<cliente_nome_temporario<<endl;}
		if(produto_cod_temporario!=0){Consultar_item ( &dados_item );}
		cout<<"Codigo: "<<cod_venda1;
		
		
		cout<<endl<<"\n Escolha uma opcao:"<<endl<<"*:";
		cin>>op;
		
		system("cls");
	
		switch (op){
		
			case 1:
				do{
					if ( List_vazia_cliente ( &dados_cliente ) ) {
						cout <<"\nCadastre um cliente para executar esta funcao.\n\n";
						limpar();
						menu2();
					}else {
						Consultar_cliente (&dados_cliente);
						cout<<endl;
						Consultar_cliente2 ( &dados_cliente );
						inserir_venda ( &dados_venda);
					}
						cout<<endl;
					
				}while(confirmacao == true);
						system("cls");
					break;
				
				
			case 2:
				Consultar_produto (&dados_produto);
				Consultar_produto2( &dados_produto );
				inserir_item(&dados_item);
				cout<<endl;
				system("cls");
				break;
		
			case 3:	
				do{
								
					excluir_item( &dados_item );
					
					cout<<"\n\n\n                   Deseja Excluir mais um item?"<<endl;
					cout<< "                         Sim = 1  Nao = 0"<<endl;
					cin>>confirmacao;
					
					system("cls");
					
				}while(confirmacao == true);
					break;
		
			case 4:
				concluir_venda();
				cod_venda1++;
				system("cls");
				menu_prin();
						break;
			
			case 5:
				cancelar_venda (&dados_venda);
				cancelar_item (&dados_item);
				system("cls");
				menu_prin();
					break ;
			default:
			 cout<<"Opcao invalida"<<endl;
			system("pause");
			}
	}while (op!=5);
}

void menu_aux(){
		cout<<"                               _______________________________"<<endl;
		cout<<"                              |                               |"<<endl;
		cout<<"                              |                               |"<<endl;
		cout<<"                              |     1 - Alterar nome          |"<<endl;
		cout<<"                              |     2 - Alterar quantidade    |"<<endl;
		cout<<"                              |     3 - Alterar valor         |"<<endl;
		cout<<"                              |                               |"<<endl;
		cout<<"                              |_______________________________|";
	
		cout<<endl<<" Escolha uma opcao:"<<endl<<"*:";
		cin>>op;
	
}




