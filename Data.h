# pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


class Data {
private:
	int dia;
	int mes;
	int ano;

public:
	Data(){};
	Data(string data); // data na forma DD/MM/AAA
	int getDia() const;
	int getMes() const;
	int getAno() const;
	void setDia(int dia);
	void setMes(int mes);
	void setAno(int ano);
	void save(ofstream & out) const;
	friend ostream& operator<<(ostream& out, const Data & data);
};


