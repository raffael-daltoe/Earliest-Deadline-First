#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#define MAX_N 26
#define MAX_T 100000
using namespace std;

class Tarefa {
private:
	unsigned c, p, d;
	unsigned time_exec,Comput_tmp,d_dinamic;
	bool state;
	char letra;
public:
	Tarefa(unsigned parC=0, unsigned parP=0, unsigned parD=0,char l='\0');
	unsigned obtemC();
	unsigned obtemP();
	unsigned obtemD();
	char obtemLetra();

	unsigned obtemTime_exec();
	bool obtemState() ;
	unsigned obtemComput_tmp();
	unsigned obtemD_dinamic() const;
	void defineLetra(char l );

	void defineD_dinamic(unsigned DI);
	void defineComputacao_tmp(unsigned Compt);
	void defineTime_exec(unsigned exec);
	void defineState(bool v);

	void defineC(unsigned parC);
	void defineP(unsigned parP);
	void defineD(unsigned parD);
	void define(unsigned parC, unsigned parP, unsigned parD,char l);
};
