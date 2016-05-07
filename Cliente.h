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


class Cliente {
private:
	unsigned int id;
	string nome;
	Data cartaoCliente;
	float volCompras;

public:
	Cliente();
	Cliente(ifstream & in);

	string getNome() const;
	unsigned int getId() const;
	float getVolCompras() const;
	Data getCartaoCliente() const;

	void setId(unsigned int id);
	void setNome(string nome);
	void setCartaoCliente(Data cartaoCliente);
	void setVolCompras(float volCompras);

	void save(ofstream & out) const;
	friend ostream& operator<<(ostream& out, const Cliente & cli);  // mostra informacao do cliente no ecra
	friend bool operator<(const Cliente &cli1, const Cliente &cli2); // compara 2 clientes (1 cleinte e menor que outro se o seu nome for "alfabeticamente" inferior)
};

