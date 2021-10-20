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
	int cod_venda=1;
	int num;
	int quantidade_subtrair;
	


	//estrutura lista 
	
			struct Lista_cliente{struct cliente *prim;};	// No com as info do primeiro cliente
			struct Lista_produto{struct produto *prim;};	// No com as info do primeiro produto
			struct Lista_venda{struct venda *prim;};		// No com as info da primeira venda
			struct Lista_item{struct item *prim;};			// No com as info do primeiro item
			
			
			Lista_cliente dados_cliente; //ultimo cliente cadastrado na lista
			Lista_produto dados_produto; //ultimo produto cadastrado na lista
			Lista_venda dados_venda; //ultima venda cadastrado na lista
			Lista_item dados_item;//ultimo item cadastrado na lista
			
//Estruturas
		struct cliente{// campos para cliente
			int cod; // codigo para identificar a cliente
			string nome; // info dos clientes
			struct cliente *prox;	};	//ponteiro que aponta para proximo cliente
				
		struct produto{// campos para produto
			int cod;// codigo para identificar a produto
			string nome;
			int quantidade; // quantidade em estoque
			float valor; // valor unitario do produto
			struct produto *prox;	};	//ponteiro que aponta para o proximo produto
				
		struct venda{// campos para venda
			int cod; // codigo para identificar a venda
			int cod_cliente; 
			string nome_cliente;
			struct venda *prox;		};	//ponteiro que aponta para a proxima venda
				
		struct item{// campos para item
		
			int cod;// codigo para identificar a item
			int cod_venda;
			int cod_cliente;
			string nome_cliente;
			int cod_produto;
			string nome_produto;
			int quantidade; // quantidade a ser vendida
			float valor; // valor unitario do produto
			float total; // calculo de valor * quantidade
			
			struct item *prox;	};		//ponteiro que aponta para o proximo item da venda
		
	
//Listas
	//estrutura para checar se a lista esta vazia
		int List_vazia_cliente (Lista_cliente *pAtual){return pAtual->prim ==  NULL;}
		int List_vazia_produto (Lista_produto *pAtual){return pAtual->prim ==  NULL;}
		int List_vazia_venda (Lista_venda *pAtual){return pAtual->prim ==  NULL;}
		int List_vazia_item (Lista_item *pAtual){return pAtual->prim ==  NULL;}


	// prototipo das funcoes existentes no programa

		void menu_prin(); // menu principal
		void menu2(); // submenu cliente
		void menu3(); // submenu produto
		void menu4(); // submenu de venda
		void menu_aux(); // submenu para funcao alterar de cliente e produto
		void verificar_cliente(struct Lista_item *pAtual); // funcao para tratar erro
		
//Funcao limpar tela
		void limpar(){ system ("pause"); system ("cls"); }
		
//CLIENTE
	//Funcao Inserir para cliente
		
		void inserir_cliente(struct Lista_cliente *pAtual, string n){ // cria ponteiro pAtual e uma variavel para armazenar nome
			cliente *novo; // cria um ponteiro com as info de estrutura cliente
			novo = new cliente; //faz de "novo"  um No vazio para ser inserido
			novo->nome = n; // armazena nome digitado por usuario
			novo->cod = cod_cliente; // armazena codigo automatico gerado pelo programa
			novo->prox = pAtual->prim; // O endereco do prox no novo No recebe o endereco de inicio da lista
			pAtual->prim = novo;//O inicio da lista recebe o novo No como inicio
		}//fim void
	
	//funcao para nao permirtir ao usuario realizar uma venda sem que haja cliente cadastrado
		
		void verificar_cliente(struct Lista_item *pAtual){ // pAtual - variavel temporaria para auxuliar a funcao
			
		 	item *atual; 	// Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
		 	
			//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
    		
    		if(atual==NULL){ // verifica se a lista esta vazia
    		}
	    		else{ 
					 for (atual=pAtual->prim; atual!= NULL; atual=atual->prox) { // armazena em atual o promeiro da lista; enquanto houver item na lista; armazena em atual o proximo item
					 	
				 		if(atual->cod_cliente==codigo){ // coferi se existe alguma venda cadastrada nos clientes
		 				cout<<"\n\n  Nao e possovel excluir. O cliente possui vendas em seu cadastro.  \n\n"<<endl;
		 				limpar();
		 				menu2(); // retorna ao menu cliente
						}
						
					}//fim for
				}
		}//fim void
			
	
	
	// Funcao Excluir
		void excluir_cliente(struct Lista_cliente *pAtual){ // cria ponteiro pAtual
     		codigo = 0; 
    		cliente *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
    		cliente *atual= pAtual->prim;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
    		cout<<"  Codigo do cliente que deseja  excluir: "<<endl<<"*:";
    		cin>>codigo;
    			
    		verificar_cliente(&dados_item); // verifica se o cliente tem alguma venda cadastrada
    		
    		//Procurando o cliente na lista.
     		while(atual != NULL && atual->cod != codigo){ // enquanto houver cliente cadastrado e o codigo digitado pelo usuario for diferente do codigo no cliente atual
						anterior = atual; // armazena o cliente anterior
    				    atual = atual->prox; // passa para o proximo cliente da lista
    			}//fim while
			
			//Mensagem caso o cliente nao seja encontrado.
    		if(atual==NULL){
			   	cout<<"\n                           Cliente nao encontrado."<<endl<<endl<<endl; 
    			limpar();
				menu2();
    		}//fim if
     
    		//Excluindo o primeiro cliente da lista.   
    		if(anterior == NULL){
				cout<<"\n  Conteudo excluido com sucesso."<<endl; 
        		pAtual->prim = atual->prox; // define o novo primeiro da lista
	 		//Excluindo um cliente do meio da lista.
     		}else{
				cout<<"\n  Conteudo excluido com sucesso."<<endl; 
				anterior->prox = atual->prox; // religa a lista
    		}//fim if
     
    		delete atual;//retirando item da lista
		}//fim void
	
	//Funcao alterar 
	
		void alterar_cliente(struct Lista_cliente *pAtual){
			string nome_substituto; //variavel temporaria
		    cliente *atual= pAtual->prim;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
	    	cout<<"  Codigo do Cliente que deseja  alterar: "<<endl<<"*:";
    		cin>>codigo;
	  		//Procurando o cliente na lista.
	    	while(atual != NULL && atual->cod != codigo){	// enquanto houver cliente cadastrado e o codigo digitado pelo usuario for diferente do codigo no cliente atual
    				    atual = atual->prox; //passa para o proximo cliente da lista
    			}//fim while
     
   			//Alterando os dados do Cliente.
     		if( atual != NULL){
        		cout<<"\n  Novo nome: "<<endl<<"*:";
        		cin>>nome_substituto; 
        		atual->nome = nome_substituto; //armazena o novo nome no campo do antigo nome digitado
        		cout<<"  Dados alterados com sucesso."<<endl;
			}else{
				cout<<"\n  Cliente nao encontrado."<<endl;
     		}
		}
	// Funcao consultar	

		void Consultar_cliente (struct Lista_cliente *pAtual) {
		 	cliente *atual; 
			 for (atual=pAtual->prim; atual!= NULL; atual=atual->prox) { //armazena em atual o promeiro da lista; enquanto houver item na lista; armazena em atual o proximo item 
				cout<<"\nCodigo do cliente: ";
				cout<< atual->cod;
 				cout<<"\nNome: ";
 				cout<< atual->nome <<endl;
 				cout<<"----------------------------------------------------";
			}//fim for
			cout<<endl;
		}//fim void


//produto

	//Funcao Inserir Produto
		void inserir_produto(struct Lista_produto *pAtual, string n, int quant, float v){ // cria ponteiro pAtual
			produto *novo; // cria um ponteiro com as info de estrutura produto
			novo = new produto; //faz de "novo"  um No vazio para ser inserido
			novo->nome = n; // armazena nome digitado por usuario
			novo->cod = cod_produto; // armazena codigo automatico gerado pelo programa
			novo->quantidade = quant; // armazena quantidade em estoque digitado por usuario
			novo->valor = v; // armazena valor unitario digitado por usuario
			novo->prox = pAtual->prim;	// O endereco do prox no novo No recebe o endereco de inicio da lista
			pAtual->prim = novo;	//O inicio da lista recebe o novo No como inicio
		}//fim void
	
	//funcao para verificar se o produto esta cadastrado em alguma venda
		void verificar_produto(struct Lista_item *pAtual){
			
			item *atual; // Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
		 	
			//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
    		
    		if(atual==NULL){ // verifica se a lista esta vazia
    		}
	    	else{
				for (atual=pAtual->prim; atual!= NULL; atual=atual->prox) {// armazena em atual o promeiro da lista; enquanto houver item na lista; armazena em atual o proximo item
				 	
			 		if(atual->cod_produto==codigo){// coferi se existe alguma venda cadastrada nos clientes
		 				cout<<"\n\n  Nao e possivel excluir o produto. Produto utilizado em venda.  \n\n"<<endl;
		 				limpar();
		 				menu3(); //retorna ao menu produto
					}
						
				}//fim for
			}
		}//fim void
		
	// Funcao Excluir

		void excluir_produto(struct Lista_produto *pAtual){ // cria ponteiro pAtual
     		codigo = 0;
    		produto *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
    		produto *atual= pAtual->prim;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
    		
			cout<<"  Codigo do Produto que deseja  excluir: "<<endl<<"*:";	//Requisitando e lendo o codigo do Produto a ser excluido.
    		cin>>codigo;
    		
        	verificar_produto(&dados_item); // verifica se o produto tem alguma venda cadastrada
        		
    		//Procurando o Produto na lista.
     		while(atual != NULL && atual->cod != codigo){// enquanto houver produto cadastrado e o codigo digitado pelo usuario for diferente do codigo no produto atual
					anterior = atual; // armazena o cliente anterior
    			    atual = atual->prox; // passa para o proximo cliente da lista
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
        		pAtual->prim = atual->prox;// define o novo primeiro da lista
	 		//Excluindo um Produto do meio da lista.
     		}else{
        
				cout<<"\n  Conteudo excluido com sucesso."<<endl; 
				anterior->prox = atual->prox; // religa a lista
    		}//fim if
     
    		delete atual; //retirando item da lista
		}//fim void
	
	//Funcao alterar 
	
		void alterar_produto(struct Lista_produto *pAtual){
			string nome_substituto; //variavel temporaria
			int quantidade_substituto; //variavel temporaria
			float valor_substituto; //variavel temporaria
		    produto *atual= pAtual->prim;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
		
		    //Requisitando e lendo o codigo do Produto a ser alterado.
	    	cout<<" Insira o codigo do Produto que deseja alterar: "<<endl<<"*:";
    		cin>>codigo;
    
	  		//Procurando o Produto na lista.
	    	while(atual != NULL && atual->cod != codigo){// enquanto houver cliente cadastrado e o codigo digitado pelo usuario for diferente do codigo no cliente atual
    		    atual = atual->prox; //passa para o proximo cliente da lista
    		}//fim while
     
   			//Alterando os dados do Produto.
     		if( atual != NULL){

 				cout<<"\nNome do Produto: ";
 				cout<< atual->nome; //armazena o novo nome no campo do antigo nome digitado
 				cout<<" ( Codigo: " << atual->cod<<" )";
 				cout<<"\nQuantidade em estoque: "; //armazena a quantidade no campo do antigo quantidade digitado
				cout<< atual->quantidade; 
				cout<<"\nValor unitario: R$ ";//armazena  o valor digitado pelo usuario
				cout<< atual->valor;
 				cout<<"\n----------------------------------------------------\n";
     			
				menu_aux(); //exibicao de submenu
				if(op == 1){ // altera somente nome
					cout<<"\n  Alterar nome: "<<endl<<"*:";
        			cin>>nome_substituto; 
        			atual-> nome = nome_substituto;
        		
				}else{
					if(op == 2){ // altera somente a quantidade
						cout<<"\n  Alterar Quantidade: "<<endl<<"*:";
        				cin>>quantidade_substituto; 
        				atual->quantidade = quantidade_substituto;
					}else{
						
						if(op==3){ // altera somente valor 
							cout<<"\n  Alterar Valor unitario: "<<endl<<"*:";
        					cin>>valor_substituto; 
        					atual->valor = valor_substituto;
						} //fim if
					}// fim if
				}//fim if
				
        		cout<<"  Dado alterado com sucesso."<<endl;
        	}else{
				cout<<"\n  Produto nao encontrado."<<endl;
     		} //fim if
		} //fim void
	
	// Funcao consultar

		void Consultar_produto (struct Lista_produto *pAtual) {
		 	produto *atual;
			for (atual=pAtual->prim; atual!= NULL; atual=atual->prox) { //armazena em atual o promeiro da lista; enquanto houver item na lista; armazena em atual o proximo item
 				cout<<"\nNome: ";
 				cout<< atual->nome;
 				
				cout<<" ( Codigo: " << atual->cod<<" )"<<endl;
				
 				cout<<"Quantidade em estoque: ";
				cout<< atual->quantidade <<endl;
				cout<<"Valor unitario: R$ ";
				cout<< atual->valor <<endl;
 				cout<<"\n----------------------------------------------------"<<endl;
			}//fim for
		}//fim void



//Venda

	//Funcao Inserir Venda	
		
		int cliente_cod_temporario;
		string cliente_nome_temporario;
		int cod_venda_temporario;
		
	// funcao para  encontrar cliente e iniciar uma venda
		void Consultar_cliente2 (struct Lista_cliente *pAtual ) { // 
			codigo=0;
		    cliente *atual= pAtual->prim;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
		    	
		   	do{
			cout<<"  Insira o codigo do cliente: "<<endl<<"*:";
	    	cin>>codigo;
		
			//Procurando o Produto na lista.
     			while(atual != NULL && atual->cod != codigo){// enquanto houver produto cadastrado e o codigo digitado pelo usuario for diferente do codigo no produto atual
    			    atual = atual->prox; // passa para o proximo cliente da lista
    			}//fim while
	    			
	    		if(atual==NULL){ // verifica se a lista esta vazia
	    			system("cls");
				   	cout<<"\n                           Cliente nao encontrado ou inexistente."<<endl; 
				   	cout<<"\n                              Insira valor 0 para voltar."<<endl<<endl<<endl; 
				} //fim if
		    	
		   		if(codigo==0){
		   			system("cls");
		   			menu4(); // menu venda
		   		}
		    	
		    	
		   	}while(atual==NULL); // fim do - while
					cout<<endl;
				
				cliente_cod_temporario = atual -> cod;
				cliente_nome_temporario = atual -> nome;
		} // fim void
		

		void inserir_venda(struct Lista_venda *pAtual){ // cria ponteiro pList
			venda *novo; // cria um ponteiro com as info de estrutura cliente
			novo = new venda; //faz de "novo"  um No vazio para ser inserido
			novo->cod = cod_venda; // armazena codigo automatico gerado pelo programa
			cod_venda_temporario = novo->cod;// armazena codigo automatico gerado pelo programa
			novo->cod_cliente = cliente_cod_temporario; // armazena codigo do cliente digitado por usuario
			novo->nome_cliente = cliente_nome_temporario;// armazena nome do cliente digitado por usuario
			// O endereco do prox no novo no recebe o endereco de inicio da lista
			novo->prox = pAtual->prim;
				
			//O inicio da lista recebe o novo no como inicio
			pAtual->prim = novo;
		}//fim void

// sub menu de venda		

	//Lista de itens por venda

		//Funcao Inserir item

			int produto_cod_temporario;
			string produto_nome_temporario;
			int produto_quantidade_temporario;
			float produto_valor_temporario;
			float total_venda;
		
			// funcao para buscar cliente
			void Consultar_produto2 (struct Lista_produto *pAtual ){
				
				codigo=0;
				string nome_substituto; 
			    produto *atual= pAtual->prim;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
			    
			
			    do{
				   	cout<<"  Insira o codigo do produto: "<<endl<<"*:";
			   		cin>>codigo;
			
					//Procurando o Produto na lista.
     				while(atual != NULL && atual->cod != codigo){// enquanto houver produto cadastrado e o codigo digitado pelo usuario for diferente do codigo no produto atual
    				    atual = atual->prox; // passa para o proximo cliente da lista
    				}//fim while
			    	
					if(atual==NULL){ // verifica se a lista esta vazia
			    		system("cls");
					   	cout<<"\n                           Produto nao encontrado ou inexistente."<<endl; 
					   	system("pause");
					   	menu4(); //menu venda
					} //fim if
			    			
	    		}while(atual==NULL); // fim do - while		  
						  		
	    		do{
	    			
	    			cout<<"\n  Insira a quantidade: "<<endl<<"*:"; // pede ao usuario a quantidade para compra
	    			cin>>codigo2;
	    			
	    			if(atual->quantidade < codigo2 || codigo2 <= 0){ // se houver menos produto do que o usuario deseja ou ele pedir zero produtos
	    				cout<<"  Nao possui essa quantidade em estoque.\n\n "<<endl;
	    				system("PAUSE");
	    			}  //fim if 
	    			
	    		}while(atual->quantidade < codigo2 ); //fim do - while
				
				cout<<endl;
				
				//limpa os temporarios
				produto_cod_temporario = atual -> cod;
				produto_nome_temporario = atual -> nome;
				produto_quantidade_temporario = codigo2;
				produto_valor_temporario = atual -> valor;
			}	
		

		// Funcao inserir item	
			void inserir_item(struct Lista_item *pAtual ){ // cria ponteiro pAtual
				num++; //conta quantas vezes a funcao foi executada
				item *novo; // cria um ponteiro com as info de estrutura cliente
				novo = new item; //faz de "novo"  um No vazio para ser inserido
			
			
				novo->cod_venda = cod_venda; //armazena o codigo de venda atual
			
				novo->cod_cliente = cliente_cod_temporario; //armazena o codigo do cliente que esta fazendo a compra
				novo->nome_cliente = cliente_nome_temporario; //armazena o nome do cliente que esta fazendo a compra
				
				novo->cod_produto = produto_cod_temporario; //armazena o codigo do produto escolhido
				novo->nome_produto = produto_nome_temporario; //armazena o nome do produto escolhido
				novo->quantidade = produto_quantidade_temporario; //armazena o quantidade que comprou do produto escolhido
				novo->valor = produto_valor_temporario; //armazena o valor unitario do produto escolhido
			
				novo->total = novo->quantidade*novo->valor; //armazena o valor da quantidade pelo valor do produtp
			
			
				// O endereco do prox no novo No recebe o endereco de inicio da lista
				novo->prox = pAtual->prim;
				//O inicio da lista recebe o novo No como inicio
				pAtual->prim = novo;
			
			}//fim void

		//Funcao consultar item
			void Consultar_item (struct Lista_item *pAtual) {
			 	item *atual; //Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
		 	
			 	total_venda=0;
				
				for (atual=pAtual->prim; atual!= NULL; atual=atual->prox) {//armazena em atual o promeiro da lista; enquanto houver item na lista; armazena em atual o proximo item
			 	
			 		if(atual->cod_venda==cod_venda){ //conferi os codigos
					
 						cout<<"\n----- | ";
 						cout<< atual->nome_produto;
 				
 						cout<<" ( Codigo: " << atual->cod_produto << " )";
 				
 						cout<<"  |  ----- Quantidade: ";
						cout<< atual->quantidade;
				
						cout<<"  |  Valor unitario: R$ ";
						cout<< atual->valor;
				
						cout<<"  |  Total: R$ ";
						cout<< atual->total;
					
						cout<<"  |\n"<<endl;
				
 						total_venda=total_venda+atual->total;
 				
					} // fim if
				
				}//fim for
				cout<<"\n--------- Total: R$ ";
				cout<< total_venda;
				cout<<"\n\n----------------------------------------------------\n";
			}//fim void
		
		
		//Funcao excluir item
			void excluir_item(struct Lista_item *pAtual){ // cria ponteiro pAtual
     			codigo=0;
    			item *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
    			item *primeiro = pAtual->prim;//Ponteiro que define primeiro endereco
    			item *atual= pAtual->prim;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
    		
    			if(atual==NULL){
    				system("cls");
    				cout<<"\n\n                          Inclua um produto antes.\n\n";
    				limpar();
					menu4(); //menu venda
    			} // fim if
    		
    			for (atual=pAtual->prim; atual!= NULL; atual=atual->prox) {//armazena em atual o promeiro da lista; enquanto houver item na lista; armazena em atual o proximo item
			 	
			 		if(atual->cod_venda==cod_venda){  //se o codigo for o mesmo
					
						cout<<"\nNome do item: "<<atual->nome_produto <<" ( Codigo: "<<atual->cod_produto<<" )"<<endl;
 				
 						cout<<"Quantidade inserida: ";
						cout<< atual->quantidade <<endl;
				
						cout<<"Valor: R$ ";
						cout<< atual->valor <<endl;
				
						cout<<"\nTotal: R$ ";
						cout<< atual->total <<endl;
				
 						cout<<"\n----------------------------------------------------";
						cout<<endl;
					} // fim if
				} // fim for
			
				atual=primeiro; // inserei novamente o primeiro em atual
			
    			cout<<"  Codigo do item que deseja excluir: "<<endl<<"*:";	//Requisitando e lendo o codigo do Produto a ser excluido.
    			cin>>codigo;
    
    			//Procurando o Produto na lista.
     			while(atual != NULL && atual->cod != codigo){// enquanto houver produto cadastrado e o codigo digitado pelo usuario for diferente do codigo no produto atual
					anterior = atual; // armazena o cliente anterior
    			    atual = atual->prox; // passa para o proximo cliente da lista
    			}//fim while
			
				//Mensagem caso o Produto nao seja encontrado.
    			if(atual->cod_produto!=codigo){
    				system("cls");
	
				   	cout<<"\n                           Item nao encontrado ou inexistente."<<endl; 
				   	menu4(); //retorna ao menu venda
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
				        		pAtual->prim = atual->prox; // define o novo primeiro da lista
				        		system("PAUSE");
			
					 		//Excluindo um Produto do meio da lista.
				     		}else{		        
								cout<<"\n                        Item excluido com sucesso."<<endl; 
								anterior->prox = atual->prox; // religa a lista
								system("PAUSE");
					    	}//fim if
				     
				    		
				    		delete atual;  //retirando item da lista
				    		
				    		total_venda=0;
				    		
				    		menu4(); //retorna ao menu venda
				    			
							break;
					
						case 2:
							menu4(); //retorna ao menu venda
								break;
		     			default:
                 			cout<<"Opcao invalida"<<endl;
	                		system("pause");
				    		
					} // fim switch
				
				}while (op!=2); // fimm do - while
			}//fim void	

		//Funcao cancelar	
			void cancelar(struct Lista_item *pAtual){ // cria ponteiro pAtual
				int numtemp; // variavel para comparar o for
				item *anterior= NULL; //Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
				item *atual = pAtual->prim; //Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
			
				for (numtemp=0; numtemp< num  ; numtemp++){ // para numerotemp zerado; numerotemp for menor que o numero de vezes q a funcao inserir foi executada; soma 1 a numero temp
				
					anterior = atual; // armazena o item anterior
					pAtual->prim = atual->prox; //passa para o proximo cliente da lista
				
					if(atual->cod_venda==cod_venda){ //conferi os codigos
		
		   				if(anterior != NULL){ //se nao for primeiro
			        		anterior->prox = atual->prox; 
							system("pause");
			     		}
						else{
							pAtual->prim = atual->prox;
							system("pause");
			    		}//fim if
			    		delete atual;//retirando item da lista
					} //fim if
				}// fim for
			
				//limpando os temporarios
				total_venda=0;
				cliente_cod_temporario=0;
				cod_venda_temporario=0;
				cliente_nome_temporario='\0';
				produto_cod_temporario=0;
				produto_nome_temporario='\0';
				produto_quantidade_temporario=0;
				produto_valor_temporario=0;
				codigo=0;
			} // fim void
				
		// funcao para retirar do estoque os itens ja vendidos	
			void diminuir_estoque(struct Lista_produto *pAtual){
				produto *atual= pAtual->prim; // atual recebe primeiro produto da lista
				
				//percorre a lista para achar o produto solicitado
				while(atual != NULL && atual->cod != codigo){ 
    				    atual = atual->prox;
    			} // fim while
    			
				atual->quantidade = atual->quantidade - quantidade_subtrair; // atualiza o valor de estoque
			
			} // fim void
			
		// funcao para confimar a realizacao da venda
			void concluir_venda(struct Lista_item *pAtual){
				item *atual;
				
				for (atual=pAtual->prim; atual!= NULL; atual=atual->prox) {// armazena em atual o promeiro da lista; enquanto houver item na lista; armazena em atual o proximo item
				 	
			 		if(atual->cod_venda==cod_venda){ // 
					
						//armazena info do produto para a funcao diminuir estoque
						codigo=atual->cod_produto; 
						quantidade_subtrair=atual->quantidade; 
	 					diminuir_estoque(&dados_produto);
	 				
					} // fim if
				
				} // fim for
			
				// limpa os temporarios
				total_venda=0;
				cliente_cod_temporario=0;
				cod_venda_temporario=0;
				cliente_nome_temporario='\0';
				produto_cod_temporario=0;
				produto_nome_temporario='\0';
				produto_quantidade_temporario=0;
				produto_valor_temporario=0;
				codigo=0;
			} // fim void
	

		//Funcao total vendas para menu principal	
			void total_vendas(struct Lista_item *pAtual){
				item *atual;
				
				int total_venda=0;
				
				//mostra o historico de itens vendidos
				for (atual=pAtual->prim; atual!= NULL; atual=atual->prox) { //armazena em atual o promeiro da lista; enquanto houver item na lista; armazena em atual o proximo item
					
	 				cout<<"\nVenda de codigo : ";
	 				cout<< atual->cod_venda;
	 				
	 				cout<<"\nProduto: ";
	 				cout<< atual->nome_produto;
	 				
	 				cout<<"\nCliente: ";
	 				cout<< atual->nome_cliente;
	 				
					cout<<"\n--Total da venda: R$";
					cout<< atual->total <<endl;
					
					cout<<"_______________________\n";
	 				total_venda=total_venda+atual->total;
	 				
				} // fim for
					
				cout<<"\n\n----------------- TOTAL GERAL: R$";
	 			cout<<total_venda<<endl<<endl<<endl<<endl<<endl;
	
			} // fim void
				
				
		



int main(){	
	
	menu_prin(); // chama menu principal
}

//menu principal

	void menu_prin(){
		do{
		
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
	
			setlocale(LC_ALL, "Portuguese"); // chama bliblioteca da lingua protuguesa -- aceita pontuacoes
			cout<<endl<<endl<<" Escolha uma opcao:"<<endl<<"*:";
			cin>>op;
			system ("cls");
	
			switch (op){
		
				case 1:
					menu2(); // chama menu cliente
						break;
			
				case 2:
					menu3();// chama menu produto
						break;
			
				case 3:
					menu4(); // chama menu venda
						break;
			
				case 4:
					if ( List_vazia_item ( &dados_item ) ) { // checa se a lista esta vazia
						cout <<"\nVoce precisa fazer alguma venda antes de consultar o total.\n\n";
						limpar();
						menu_prin(); // retorna ao menu principal
					}
					else{ // calula o total das vendas
						total_vendas(&dados_item);
						limpar();
					}
					break;
			
				case 5:
					cout<<"FIM DO PROGRAMA"<<endl;
					exit(0); // finaliza o programa
					break ;
			
				default:
                 cout<<"Opcao invalida"<<endl;
	                 system("pause");
			} //fim switch
		
		}while (op!=5); // fim do - while
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
		
				case 1: // incluir
					do{
				
						cin.ignore();
						cout<<"Nome Cliente:"<<endl;
						getline(cin, nome_cliente); // armazena qualquer informacao digita na linha
					
						inserir_cliente ( &dados_cliente, nome_cliente); // adiciona cliente a lista
					
						cout<<"\n\n\n                          Cadastro concluido !!";
						cout<<"\n\n\n                   Deseja cadastrar mais um cliente?"<<endl;
						cout<< "                         Sim = 1  Nao = 0"<<endl;
						cin>>confirmacao;
						cod_cliente++; // passa para o proximo codigo
						system("cls");
					}while(confirmacao == true); // fim do - while
				
				break;
		
				case 2: // excluir
					if ( List_vazia_cliente ( &dados_cliente ) ) { // checa se a lista esta vazia
						cout <<"\nCadastre um cliente para executar esta funcao.\n\n";
						limpar();
						menu2(); // retorna menu cliente
			
					}else {
						do{
							
							Consultar_cliente (&dados_cliente);
							excluir_cliente( &dados_cliente );
							cout<<"\n\n\n                   Deseja Excluir mais um cliente?"<<endl;
							cout<< "                         Sim = 1  |  Nao = 0"<<endl;
							cin>>confirmacao;
							system ("cls");
						}while(confirmacao == true);  //fim do - while
					} // fim if
					break;
		
				case 3: // alterar
					if ( List_vazia_cliente ( &dados_cliente ) ) { // checa se a lista esta vazia
						cout <<"\nCadastre um cliente para executar esta funcao.\n\n";
						limpar();
						menu2(); // retorna menu cliente
					
					}else {
					
					    do{
							alterar_cliente( &dados_cliente );
							cout<<"\n\n\n                   Deseja alterar mais um cliente?"<<endl;
							cout<< "                         Sim = 1  |  Nao = 0"<<endl;
							cin>>confirmacao;
							system ("cls");
						}while(confirmacao == true);//fim do - while
					} // fim if
				break;
		
				case 4: // consultar
					if ( List_vazia_cliente ( &dados_cliente ) ) { //checa se a lista esta vazia
						cout <<"\nCadastre um cliente para executar esta funcao.\n\n";
						limpar();
						menu2(); // retorna ao menu cliente
					}else {
						Consultar_cliente (&dados_cliente);
						limpar();
					} // fim if
				break;
			
				case 5: // voltar
					menu_prin(); // retorna ao menu principal
					break ;
		
				default:
				 cout<<"Opcao invalida"<<endl;
				system("pause");
			} // fim switch
		}while (op!=5); //fim do - while
	} // fim void

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
		
				case 1: // incluir
					do{
						cin.ignore();
						cout<<"Nome Produto:"<<endl;
						getline(cin, nome_produto); // armazena qualquer informacao digita na linha
						cout<<endl;
					
						cout<<"Quantidade inicial em estoque:"<<endl;
						cin>>quantidade;
						cout<<endl;
						
						cout<<"Valor:\nR$";
						cin>>valor;
						cout<<endl;
				
						inserir_produto ( &dados_produto, nome_produto, quantidade, valor); // adiciona um  produto a lista
					
						cod_produto++; // passa para o proximo codigo
						
						cout<<"\n\n\n                          Cadastro concluido !!";
						cout<<"\n\n\n                   Deseja cadastrar mais um Produto?"<<endl;
						cout<< "                         Sim = 1  Nao = 0"<<endl;
						cin>>confirmacao;
						system("cls");
					}while(confirmacao == true); //fim do - while
				
				break;
		
				case 2: //excluir
					if ( List_vazia_produto ( &dados_produto ) ) { // verifica se a lista esta vazi
						cout <<"\nCadastre um produto para executar esta funcao.\n\n";
						limpar();
						menu3(); // retorna ao menu produto
					}else {
							do{
											
								excluir_produto( &dados_produto );
								
								cout<<"\n\n\n                   Deseja Excluir mais um Produto?"<<endl;
								cout<< "                         Sim = 1  Nao = 0"<<endl;
								cin>>confirmacao;
							
								system("cls");
							
							}while(confirmacao == true);//fim do - while
					} // fim iif
				break;
		
				case 3: // alterar
					if ( List_vazia_produto ( &dados_produto ) ) { // verifica se a lista esta vazi
						cout <<"\nCadastre um produto para executar esta funcao.\n\n";
						limpar();
						menu3(); // retorna ao menu produto
					}else {
					     do{
										
							alterar_produto( &dados_produto );
							
							cout<<"\n\n\n                   Deseja alterar mais um Produto?"<<endl;
							cout<< "                         Sim = 1  Nao = 0"<<endl;
							cin>>confirmacao;
							
							system("cls");
							
						}while(confirmacao == true);//fim do - while
					} //fim if
				break;
		
				case 4: // consultar
					if ( List_vazia_produto ( &dados_produto ) ) { // verifica se a lista esta vazi
						cout <<"\nCadastre um produto para executar esta funcao.\n";
						limpar();
						menu3(); // retorna ao menu produto
					}else {
						Consultar_produto (&dados_produto);
						limpar();
					} // fim if
					
				break;
			
				case 5: // voltar
					menu_prin(); // retorna ao menu principal
				break ;
		
				default:
			
					 cout<<"Opcao invalida"<<endl;
		 
					system("pause");
			}// fim switch
		}while (op!=5);	//fim do - while
	} // fim void

// menu venda
	void menu4(){
	
		num=0;
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
	
			cout<<"Numero da venda: "<<cod_venda<<endl<<endl;
			if(cliente_cod_temporario!=0){cout<<"--------- Nome do cliente: "<<cliente_nome_temporario<<endl;}
			if(produto_cod_temporario!=0){Consultar_item ( &dados_item );}
		
		
		
			cout<<endl<<"\n Escolha uma opcao:"<<endl<<"*:";
			cin>>op;
			
			system("cls");
	
			switch (op){
		
				case 1: // incluir cliente
					do{
						if ( List_vazia_cliente ( &dados_cliente ) ) { 	// verifica se a lista esta vazia
							cout <<"\nCadastre um cliente para executar esta funcao.\n\n";
							limpar();
							menu2(); //retorna ao menu cliente
						}else {
							Consultar_cliente (&dados_cliente);
							cout<<endl;
							Consultar_cliente2 ( &dados_cliente );
							inserir_venda ( &dados_venda);
						}
						cout<<endl;
					
					}while(confirmacao == true); // fim do - while
		
					system("cls");
				break;
				
				
				case 2: // incluir item
					if ( List_vazia_produto ( &dados_produto ) ) { // verifica se a lista esta vazia
						cout <<"\nCadastre um produto antes de executar esta funcao.\n\n";
						limpar();
						menu3(); //retorna ao menu produto
					} //fim if
				
					if ( List_vazia_venda ( &dados_venda ) ) { // verifica se a lista esta vazia
						cout <<"\nInsira um cliente antes de executar esta funcao.\n\n";
						limpar();
						menu4(); //retorna ao menu venda
					}else{
						Consultar_produto (&dados_produto);
						Consultar_produto2( &dados_produto );
						inserir_item(&dados_item);
					} //fim if
					cout<<endl;
					system("cls");
				break;
		
				case 3:	//excluir item
					if ( List_vazia_produto ( &dados_produto ) ) {// verifica se a lista esta vazia
						cout <<"\nCadastre um produto antes de executar esta funcao.\n\n";
						limpar();
						menu3();//retorna ao menu produto 
					} // fim if
			
					if ( List_vazia_item ( &dados_item ) ) { // verifica se a lista esta vazia
						cout <<"\nInsira um produto antes de executar esta funcao.\n\n";
						limpar();
						menu4(); //retorna ao menu venda
					} // fim if
				
					do{
								
						excluir_item( &dados_item );
					
						cout<<"\n\n\n                   Deseja Excluir mais um item?"<<endl;
						cout<< "                         Sim = 1  Nao = 0"<<endl;
						cin>>confirmacao;
						
						system("cls");
					
					}while(confirmacao == true); // fim do - while
				break;
		
				case 4: // concluir venda
					if ( List_vazia_cliente ( &dados_cliente ) ) { // verifica se a lista esta vazia
						cout <<"\nCadastre um cliente para executar esta funcao.\n\n";
						limpar();
						cancelar(&dados_item); //limpa a venda feita
						menu2(); // retorna ao menu cliente
					}//fim if
			
					if ( List_vazia_produto ( &dados_produto ) ) { // verifica se a lista esta vazia
						cout <<"\nCadastre um produto antes de executar esta funcao.\n\n";
						limpar();
						cancelar(&dados_item); //limpa a venda feita
						menu3();// retorna ao menu produto
					} // fim if
	
					if ( List_vazia_venda ( &dados_venda ) ) { // verifica se a lista esta vazia
						cout <<"\nInsira um cliente antes de executar esta funcao.\n\n";
						limpar();
						cancelar(&dados_item); //limpa a venda feita
						menu4(); // retorna ao menu venda
					} // fim if
	
					if ( List_vazia_item ( &dados_item ) ) { // verifica se a lista esta vazia
						cout <<"\nInsira um produto para finalizar a venda.\n\n";
						limpar();
						cancelar(&dados_item); //limpa a venda feita
						menu4(); // retorna ao menu venda
					} //fim if
	
					concluir_venda(&dados_item);
					cod_venda++; // novo codigo
					system("cls");
					cout <<"\n\n\n\n-------------------------------VENDA FINALIZADA COM SUCESSO!-------------------------------\n\n\n\n";
					limpar();
					menu_prin(); // retorna ao menu principal
				break;
			
				case 5: // cancelar
					cancelar(&dados_item);
			
					system("cls");
					menu_prin(); // retorna ao menu principal
				break ;
			
				default:
					 cout<<"Opcao invalida"<<endl;
					system("pause");
			} // fim switch
		}while (op!=5);//fim do - while
	} //fim void

// menu da funcao alterar
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
