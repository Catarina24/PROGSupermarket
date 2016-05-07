#include "utils.h"


void clearScreen(){
	system("cls");
}


unsigned short int leUnsignedShortInt(unsigned short int min, unsigned short int  max){
	unsigned short int num;
	string n;
	while (true){
		getline(cin, n, '\n');
		num = stoi(n);
		if (num >= min){
			if (num <= max){
				return num;
				break;
			}
		}
	}

}


int leInteiro(int min, int max){

	int num;
	string n;
	while (true){
		getline(cin, n, '\n');
		num = stoi(n);
		if (num > min && num < max){
			return num;
			break;
		}
	}

}

int leInteiro(){
	int num;
	string n;
	getline(cin, n, '\n');
	num = stoi(n);
	return num;
}