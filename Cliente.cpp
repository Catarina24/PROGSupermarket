#include "Cliente.h"


Cliente::Cliente(){
	id = 0;
	nome = "";
	cartaoCliente.setAno(0);
	cartaoCliente.setDia(0);
	cartaoCliente.setMes(0);
	volCompras = 0;

}
Cliente::Cliente(ifstream & in){
	Cliente c;
	string line;
	stringstream str;
	string filename;
	cout << "Introduza o nome do ficheiro(com extensao .txt)" << endl;
	getline(cin, filename, '\n');
	in.open(filename);
	if (in.is_open()){
		while (!in.eof()){
			getline(in, line);
			int pos1 = -90;
			int pos2 = -5;
			int pos3 = -5;
			for (unsigned int i = 0; i < line.size(); i++)
			{
				if (line[i] == ';'){
					if (pos1 < 0){
						pos1 = i;
					}
					else if (pos1 > 0 && pos2 < 0){
						pos2 = i;
					}
					else if (pos1 > 0 && pos2 > 0){
						pos3 = i;
					}
				}
			}
			str << line.substr(0, pos1 - 1);
			str >> c.id;
			str.clear();

			c.nome = line.substr(2 + pos1, pos2 - pos1 - 3);

			c.cartaoCliente = line.substr(pos2 + 2, pos3 - pos2 - 2);

			str << line.substr(pos3 + 1, line.size() - pos3 - 2);
			str >> c.volCompras;
			str.clear();

			//			clientes.push_back(c);
		}
	}

	in.close();
}


string Cliente::getNome() const{
	return nome;
}

unsigned int Cliente::getId() const{
	return id;
}

float Cliente::getVolCompras() const{
	return volCompras;
}

Data Cliente::getCartaoCliente() const{
	return this->cartaoCliente;
}

void Cliente::setId(unsigned int id){
	this->id = id;
}
void Cliente::setNome(string nome){
	this->nome = nome;
}

void Cliente::setCartaoCliente(Data cartaoCliente){
	this->cartaoCliente = cartaoCliente;
}

void Cliente::setVolCompras(float volCompras){
	this->volCompras = volCompras;
}


void Cliente::save(ofstream & out) const{

	// A IMPLEMENTAR

}

ostream& operator<<(ostream& out, const Cliente & cli){
	out << "====================================" << endl;
	out << "    Codigo do cliente: " << cli.id << endl;
	out << "    Nome do cliente: " << cli.nome << endl;
	out << "    Montante do cliente: " << cli.volCompras << endl;
	out << "====================================" << endl;
	out << endl;
	return out;
}


bool operator<(const Cliente &cli1, const Cliente &cli2){
	if (cli1.nome < cli2.nome)
		return true;
	else
		return false;
}
