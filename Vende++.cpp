#include "Vende++.h"


VendeMaisMais::VendeMaisMais(string loja, string fichClients, string fichProdutos, string fichTransacoes){
	this->loja = loja;
	this->fichClientes = fichClients;
	this->fichProdutos = fichProdutos;
	this->fichTransacoes = fichTransacoes;
}

bool VendeMaisMais::getTransacoesAlteradas() const{
	return this->transacoesAlteradas;
}
bool VendeMaisMais::getClientesAlterados() const{
	return this->clientesAlterados;
}

unsigned int VendeMaisMais::getMaxClientesId() const{
	return this->maxClientesId;
}
vector<Cliente> VendeMaisMais::getClientes() const{
	return this->clientes;
}
vector<Produto> VendeMaisMais::getProdutos() const{
	return this->produtos;
}
vector<Transacao> VendeMaisMais::getTransacoes() const{
	return this->transacoes;
}

void VendeMaisMais::setTransacoesAlteradas(bool temp){
	this->transacoesAlteradas = temp;
}

void VendeMaisMais::setClientesAlterados(bool temp){
	this->clientesAlterados = temp;
}
void VendeMaisMais::setMaxClientesId(unsigned int id){
	this->maxClientesId = id;
}
/*********************************
* Gestao de Clientes
********************************/

// lista os clientes por ordem alfabetica crescente
void VendeMaisMais::listarClientesOrdemAlfa() const{

	for (unsigned int i = 0; i < clientes.size(); i++){

	}

}

// mostra a informacao individual de um cliente
void VendeMaisMais::mostraInformacaoCliente(string nome){



}

/*********************************
* Gestao de Produtos
********************************/

// lisat os produto por ordem alfabetica crescente
void VendeMaisMais::listarProdutos() const{

	// A IMPLEMENTAR 

}


/*********************************
* Preservar Informacao
********************************/

// guarda apenas a informacao de clientes e/ou de transacoes que foi alterada
void VendeMaisMais::saveChanges() const{

	fstream file2;
	file2.open(fichClientes);
	file2.is_open();
	if (file2.is_open()){
		for (unsigned int i = 0; i < clientes.size(); i++){
			if (i == clientes.size() - 1){
				file2 << clientes[i].getId() << " ; " << clientes[i].getNome() << " ; " << clientes[i].getVolCompras();
			}
			else{
				file2 << clientes[i].getId() << " ; " << clientes[i].getNome() << " ; " << clientes[i].getVolCompras() << endl;
			}
		}
	}
	file2.close();

	fstream file3;
	file3.open("transacoes.txt");
	file3.is_open();
	if (file3.is_open()){
		for (unsigned int i = 0; i < transacoes.size(); i++){
			if (i == transacoes.size() - 1){
				file3 << transacoes[i].getIdCliente() << " ; " << transacoes[i].getData().getDia() << "/" << transacoes[i].getData().getMes() << "/" << transacoes[i].getData().getAno() << " ; ";
				for (unsigned int j = 0; j < transacoes[i].getProdutos().size(); j++){
					if (j == transacoes[i].getProdutos().size() - 1){
						file3 << transacoes[i].getProdutos()[j];
					}
					else {
						file3 << transacoes[i].getProdutos()[j];
					}
				}
			}
			else{
				file3 << transacoes[i].getIdCliente() << " ; " << transacoes[i].getData().getDia() << "/" << transacoes[i].getData().getMes() << "/" << transacoes[i].getData().getAno() << " ; ";
				for (unsigned int j = 0; j < transacoes[i].getProdutos().size(); j++){
					if (j == transacoes[i].getProdutos().size() - 1){
						file3 << transacoes[i].getProdutos()[j] << endl;
					}
					else {
						file3 << transacoes[i].getProdutos()[j] << ", ";
					}
				}
			}
		}
	}
	file3.close();


}

/*********************************
* Mostrar Loja
********************************/

// mostra o conteudo de uma loja
ostream& operator<<(ostream& out, const VendeMaisMais & supermercado){

	for (unsigned int i = 0; supermercado.getClientes().size(); i++){
		out << supermercado.getClientes()[i];
	}
	for (unsigned int i = 0; supermercado.getTransacoes().size(); i++){
		out << supermercado.getTransacoes()[i];
	}
	for (unsigned int i = 0; supermercado.getProdutos().size(); i++){
		out << supermercado.getProdutos()[i];
	}
	return out;
}
