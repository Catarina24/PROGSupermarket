#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Data.h"



using namespace std;


class Transacao {
private:
	unsigned int idCliente;
	Data data; // na forma DD/MM/AAAAA
	vector<string> produtos;

public:
	Transacao(ifstream & in); // transacao na forma de  idCliente ; data ; lista de produtos
	unsigned int getIdCliente() const;
	Data getData() const;
	vector<string> getProdutos() const;

	void setIdCliente(unsigned int id);
	void setData(Data d);
	void setProdutos(vector<string> vec);

	void save(ofstream & out) const; // guarda a transacao
	friend ostream& operator<<(ostream& out, const Transacao & trans); // mostra a transacao
};



