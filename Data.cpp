#include "Data.h"

Data::Data(string dataStr){ // data na forma DD/MM/AAA
	int pos1 = -5;
	int pos2 = -5;
	for (unsigned int i = 0; i < dataStr.size(); i++){
		if (dataStr[i] == '/'){
			if (pos1 >0){
				pos2 = i;
			}
			else
				pos1 = i;
		}
	}
	this->dia = stoi(dataStr.substr(0, pos1 - 1));
	this->mes = stoi(dataStr.substr(pos1 + 1, pos2 - pos1 - 2));
	this->ano = stoi(dataStr.substr(pos2 + 1, dataStr.size() - pos2 - 1));
}

int Data::getDia() const{
	return dia;
}

int Data::getMes() const{
	return mes;
}

int Data::getAno() const{
	return ano;
}

void Data::setDia(int dia){
	this->dia = dia;
}

void Data::setMes(int mes){
	this->mes = mes;
}

void Data::setAno(int ano){
	this->ano = ano;
}

void Data::save(ofstream & out) const{
	// A IMPLEMENTAR
}

ostream& operator<<(ostream& out, const Data & data){
	out << data.getDia() << "/" << data.getMes() << "/" << data.getAno();
	return out;
}
