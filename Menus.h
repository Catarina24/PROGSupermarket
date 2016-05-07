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

#include "defs.h"
#include "utils.h"
#include "Vende++.h"

using namespace std;

bool infoInicial(string & loja, string & fichClients, string & fichProdutos, string & fichTransacoes);

void opcoesIniciais(VendeMaisMais & supermercado);

void opcoesGestaoClientes(VendeMaisMais & supermercado);
void listarClientesOrdemAlfabetica(VendeMaisMais & supermercado);

void listarProdutos(VendeMaisMais & supermercado);

void opcoesGestaoTransacoes(VendeMaisMais & supermercado);

void opcoesRecomendacao(VendeMaisMais & supermercado);
