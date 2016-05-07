#pragma once

#include <map>
#include<algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "defs.h"
#include "Data.h"
#include "Cliente.h"
#include "Transacao.h"
#include "Produto.h"
#include "utils.h"


using namespace std;

class VendeMaisMais{
private:
	string loja; // nome da loja
	string fichClientes, fichProdutos, fichTransacoes; // nome dos
	// ficheiros de
	// clientes,
	// produtos e
	// transacoes
	bool transacoesAlteradas; // flag que fica a true se for preciso guardar no final as transacoes
	bool clientesAlterados; // flag que fica a true se for preciso guardar no final os clienets
	unsigned int maxClientesId; // variavel que guarda o identificador unico do cliente com o maior identificador
	vector<Cliente> clientes; // vetor que guarda a informacao dos clientes existentes
	vector<Produto> produtos; // vetor que guarda a informacao dos produtos disponiveis
	vector<Transacao> transacoes; // vetor que guarda a informacao das ttransacoes efetuadas
	map<string, int> clienteIdx;  // map para "traduzir" nome do cliente no indice dele no vetor de clientes
	map<string, int> produtoIdx;  // map para "traduzir" nome do produto no indice dele no vetor de produtos
	multimap<int, int> transacaoIdx; // multima para "traduzir" o identificador do
	// cliente nos indices das suas
	// transacoes no vetor de
	// transacoes

public:
	VendeMaisMais(string loja, string fichClients, string fichProdutos, string fichTransacoes);
	bool getTransacoesAlteradas() const;
	bool getClientesAlterados() const;
	unsigned int getMaxClientesId() const;
	vector<Cliente> getClientes() const;
	vector<Produto> getProdutos() const;
	vector<Transacao> getTransacoes() const;

	void setTransacoesAlteradas(bool temp);
	void setClientesAlterados(bool temp);
	void setMaxClientesId(unsigned int id);

	void listarClientesOrdemAlfa() const;
	void listarProdutos() const;
	void mostraInformacaoCliente(string nome);
	void saveChanges() const;

	friend ostream& operator<<(ostream& out, const VendeMaisMais & supermercado);
};
