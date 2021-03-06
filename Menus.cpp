#include "Menus.h"



bool infoInicial(string & loja, string & fichClientes, string & fichProdutos, string & fichTransacoes){
	bool temp = true;
	fichClientes = "clientes.txt";
	fichProdutos = "produtos.txt";
	fichTransacoes = "transacoes.txt";
	loja = "Continente";
	/*bool temp1 = true;
	bool temp2 = true;
	bool temp3 = true;
	bool temp;
	cout << "Introduza o nome do ficheiro dos clientes (com a extensao .txt)" << endl;
	getline(cin, fichClientes, '\n');
	fstream file;
	file.open(fichClientes);
	if (!file.is_open()){
	temp1 = false;
	}
	cout << "Introduza o nome do ficheiro dos produtos (com a extensao .txt)" << endl;
	getline(cin, fichProdutos, '\n');
	fstream file2;
	file2.open(fichProdutos);
	if (!file2.is_open()){
	temp2 = false;
	}

	cout << "Introduza o nome do ficheiro das transacoes (com a extensao .txt)" << endl;
	getline(cin, fichTransacoes, '\n');
	fstream file3;
	file3.open(fichTransacoes);
	if (!file3.is_open()){
	temp3 = false;
	}
	if (temp1 == false || temp2 == false || temp3 == false){
	temp = false;
	}
	else
	temp = true;*/
	return temp;
}

/******************************************
* Gestao de Clientes
******************************************/
unsigned short int menuGestaoClientes(){
	unsigned short int opcao;

	clearScreen();
	cout << TAB_BIG << "Menu Gestao Clientes" << endl;
	cout << endl;
	cout << TAB << "1 - Adicionar cliente" << endl;
	cout << TAB << "2 - Alterar cliente" << endl;
	cout << TAB << "3 - Remover cliente" << endl;
	cout << TAB << "4 - Listar os clientes por ordem alfabetica" << endl;
	cout << TAB << "5 - Voltar ao menu inicial" << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leUnsignedShortInt(1, 5);

	if (opcao == 5)
		return 0;

	return opcao;
}
unsigned short int menuEditarCliente(){
	unsigned short int opcao;
	clearScreen();
	cout << TAB_BIG << "Menu Alterar Cliente" << endl;
	cout << endl;
	cout << TAB << "1 - Modificar o nome" << endl;
	cout << TAB << "2 - Modificar a data de ades�o" << endl;
	cout << TAB << "3 - Modificar o volume de compras" << endl;
	cout << TAB << "4 - Voltar ao menu inicial" << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leUnsignedShortInt(1, 4);

	if (opcao == 4)
		return 0;

	return opcao;
}


void opcoesGestaoClientes(VendeMaisMais & supermercado){
	unsigned int opcao, op;
	string nome;

	while ((opcao = menuGestaoClientes()))
		switch (opcao){

		case 1:
			//criar
			cout << "Qual o nome do cliente: ";
			getline(cin, nome);
			//Adicionar cliente
			break;

		case 2:
			//alterar
			cout << "Qual o nome do cliente: ";
			getline(cin, nome);
			while ((op = menuEditarCliente()))
				switch (op){
				case 1:
					//modificar o nome do cliente
					break;
				case 2:
					//modificar a data de adesao
					break;
				case 3:
					//Modificar o volume de compras
					break;
			}

			/*
			cout << "Qual o nome do cliente: ";
			getline(cin, nome);
			supermercado.mostraInformacaoCliente(nome);*/
			break;
			
		case 3:
			//Remover cliente
			cout << "Qual o nome do cliente: ";
			getline(cin, nome);
			//Remove cliente

			break;

			
		case 4:
			//Listar os clientes por ordem alfabetica
			supermercado.listarClientesOrdemAlfa();

			break;
	}
}

/******************************************
* Gestao de Transacoes
******************************************/
unsigned short int menuGestaoTransacoes(){
	unsigned short int opcao;
	clearScreen();
	cout << TAB_BIG << "Menu Gestao Transacoes" << endl;
	cout << endl;
	cout << TAB << "1 - Listar todas as transacoes num intervalo de tempo" << endl;
	cout << TAB << "2 - Listar todas as transacoes por ordem cronologica de um cliente" << endl;
	cout << TAB << "3 - Voltar ao menu inicial" << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leUnsignedShortInt(1, 3);

	if (opcao == 3)
		return 0;

	return opcao;
}

void opcoesGestaoTransacoes(VendeMaisMais & supermercado){
	unsigned int opcao;
	string nome, dat, dat2;
	while ((opcao = menuGestaoTransacoes()))
		switch (opcao){
		case 1:
			cout << "Introduza o intervalo de tempo" << endl;
			cout << "A primeira data" << endl;
			getline(cin, dat, '\n');
			cout << "A segunda data" << endl;
			getline(cin, dat2, '\n');
			//ver transacoes de um cliente
			break;
		case 2:
			cout << "Qual o nome do cliente: ";
			getline(cin, nome);

			//ver transacoes de um cliente entre duas datas
			break;
		/*case 3:
			//listar todas as transacoes por ordem cronologica
			break;
		case 4:
			
			break;*/
	}

}

unsigned short int menuVerInformacao(){
	unsigned short int opcao;
	clearScreen();
	cout << TAB_BIG << "Menu Ver Informacao" << endl;
	cout << endl;
	cout << TAB << "1 - Clientes" << endl;
	cout << TAB << "2 - Transacoes" << endl;
	cout << TAB << "3 - Produtos" << endl;
	cout << TAB << "4 - Voltar ao menu inicial" << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leUnsignedShortInt(1, 4);

	if (opcao == 4)
		return 0;

	return opcao;
}

unsigned short int menuVerInformacaoCliente(){
	unsigned short int opcao;
	clearScreen();
	cout << TAB_BIG << "Menu Ver Informacao Cliente" << endl;
	cout << endl;
	cout << TAB << "1 - Um Cliente" << endl;
	cout << TAB << "2 - Todos os clientes" << endl;
	cout << TAB << "3 - Voltar ao menu inicial" << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leUnsignedShortInt(1, 3);

	if (opcao == 3)
		return 0;

	return opcao;
}

void opcoesVerInformacaoClientes(VendeMaisMais & supermercado){
	unsigned int opcao;
	string nome, dat, dat2;
	while ((opcao = menuVerInformacaoCliente()))
		switch (opcao){
		case 1:
			//Um cliente
			cout << "Qual o nome do cliente: ";
			getline(cin, nome);
			//ver informacoes de um cliente
			break;
		case 2:
			//Todos os clientes

			//ver informacoes de todos os clientes
			break;
	}
}

unsigned short int menuVerInformacaoTransacoes(){
	unsigned short int opcao;
	clearScreen();
	cout << TAB_BIG << "Menu Ver Informacao Transacoes" << endl;
	cout << endl;
	cout << TAB << "1 - De um Cliente" << endl;
	cout << TAB << "2 - De um dia" << endl;
	cout << TAB << "3 - Entre duas datas especificas" << endl;
	cout << TAB << "4 - Todas as transacoes" << endl;
	cout << TAB << "5 - Voltar ao menu inicial" << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leUnsignedShortInt(1, 5);

	if (opcao == 5)
		return 0;

	return opcao;
}

void opcoesVerInformacaoTransacoes(VendeMaisMais & supermercado){
	unsigned int opcao;
	string nome, data, data2;
	while ((opcao = menuVerInformacaoTransacoes()))
		switch (opcao){
		case 1:
			//De um cliente
			cout << "Qual o nome do cliente: " << endl;
			getline(cin, nome);
			//ver transacoes de um cliente
			break;
		case 2:
			//De um dia
			cout << "Introduza a data" << endl;
			getline(cin, data, '\n');
			//ver transacoes de uma data
			break;
		case 3:
			//entre duas datas especificas
			cout << "Introduza a primeira data" << endl;
			getline(cin, data, '\n');
			cout << "Introduza a segunda data" << endl;
			getline(cin, data2, '\n');
			//ver transacoes entre as duas datas
			break;
		case 4:
			//ver todas as transacoes
			break;
	}
}


/******************************************
* Gestao de Recomendacao
******************************************/
unsigned short int menuRecomendacao(){
	unsigned short int num = 5;
	return num;
}

void opcoesRecomendacao(VendeMaisMais & supermercado){
	unsigned int opcao;

	while ((opcao = menuRecomendacao()))
		switch (opcao){
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
	}

}

/******************************************
* Menu Inicial
******************************************/
unsigned short int menuInicial(){
	unsigned short int opcao;

	clearScreen();
	cout << TAB_BIG << "Menu Inicial" << endl;
	cout << endl;
	cout << TAB << "1 - Menu Gestao de clientes" << endl;
	cout << TAB << "2 - Menu Gestao de transacoes" << endl;
	cout << TAB << "3 - Efetuar compras" << endl;
	cout << TAB << "4 - Visualizar informacoes" << endl;
	cout << TAB << "5 - Recomendacoes" << endl;
	cout << TAB << "6 - Sair do programa" << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leUnsignedShortInt(1, 6);

	if (opcao == 6)
		return 0;

	return opcao;
}

void opcoesIniciais(VendeMaisMais & supermercado){
	unsigned int opcao, op;


	while ((opcao = menuInicial()))
		switch (opcao){
		
		case 1:
			//Menu gestao clientes
			opcoesGestaoClientes(supermercado);
			break;
			
		case 2:
			//menu gestao transacoes
			opcoesGestaoTransacoes(supermercado);
			break;
			
		case 3:
			//efetuar compras
		//	cout << "Qual o nome do cliente: ";
			//getline(cin, nome);
			//QUAIS OS PRODUTOS QUE FORAM COMPRADOS
			//QUAL O PRECO DELES
			//ACRESCENTAR O MONTANTE TOTAL DASA COMPRAS AO CLIENTE
		
			
			break;
			
		case 4:
			//visualizar informcao
			
			while((op = menuVerInformacao()))
				switch (op){
				case 1:
					//Clientes
					opcoesVerInformacaoClientes(supermercado);
					break;
				case 2:
					//Transacoes
					opcoesVerInformacaoTransacoes(supermercado);
					break;
				case 3:
					//Produtos
					supermercado.listarProdutos();
					break;
			}
			break;
			
		case 5: 
			//Recomendacoes
			opcoesRecomendacao(supermercado);
			break;
	}

	supermercado.saveChanges();
}
