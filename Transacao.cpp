#include "Transacao.h"



unsigned int Transacao::getIdCliente() const{
	return this->idCliente;
}

Data Transacao::getData() const{
	return this->data;
}
vector<string> Transacao::getProdutos() const{
	return this->produtos;
}

void Transacao::setIdCliente(unsigned int id){
	this->idCliente = id;
}

void Transacao::setData(Data d){
	this->data = d;
}
void Transacao::setProdutos(vector<string> vec){
	this->produtos = vec;
}

Transacao::Transacao(ifstream & in){ // le uma transacao na forma de  idcliente ; data ; lista produtos
	stringstream ss;
	string str;
	int pos1 = -5;
	int pos2 = -5;
	ss << in;
	ss >> str;
	for (unsigned int i = 0; i < str.size(); i++){
		if (str[i] == ';'){
			if (pos1 >0){
				pos2 = i;
				break;
			}
			else{
				pos1 = 1;
			}
		}
	}
	idCliente = stoi(str.substr(0, pos1 - 1));
	data = str.substr(pos1 + 1, pos2 - pos1 - 2);
	produtos.push_back(str.substr(pos2 + 1, str.size() - pos2 - 1));
}

void Transacao::save(ofstream & out) const{ // transacao guardada como na forma de  idcliente ; data ; lista produtos
	// A IMPLEMENTAR
}


ostream& operator<<(ostream& out, const Transacao & trans){
	out << trans.getIdCliente() << trans.getData();
	for (unsigned int i = 0; i < trans.getProdutos().size(); i++) {
		out << trans.getProdutos()[i];
	}
	return out;
}
