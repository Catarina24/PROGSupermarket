#include "Produto.h"


Produto::Produto(ifstream & in){ // nome ; custo
	stringstream ss;
	string str;
	int pos = -5;
	ss << in;
	ss >> str;
	for (unsigned int i = 0; i < str.size(); i++){
		if (str[i] == ';'){
			pos = i;
		}
		this->nome = str.substr(0, pos - 1);
		this->custo = stof(str.substr(pos + 1, str.size() - pos - 1));
	}
}

string Produto::getNome() const {
	return nome;
}

float Produto::getCusto() const {
	return custo;
}

void Produto::setNome(string nome){
	this->nome = nome;
}
void Produto::setCusto(float custo){
	this->custo = custo;
}
ostream& operator<<(ostream& out, const Produto & prod){

	out << prod.nome << prod.custo;
	return out;

}


bool operator<(const Produto &prod1, const Produto &prod2){
	bool temp = false;
	//if (prod1.)
	return temp;
}
