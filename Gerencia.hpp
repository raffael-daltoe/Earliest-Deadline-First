#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#define MAX_N 26
#define MAX_T 100000
using namespace std;

#include "Tarefa.hpp"


class Gerencia{
	double U;
	unsigned tr_contexto, preemp;
	char grade[MAX_T];
	vector<char> tarefas;
public:	
	Gerencia(){
		tr_contexto = 0;
		preemp = 0;
		grade[0] = '\0';
	}

	char* obtemGrade();
	unsigned obtemTr();
	unsigned obtemPreemp(); 
	double obtemU();
	Tarefa *busca(char l,vector<Tarefa>&t);
	void incrementaGrade(char l,int i);
	void increaseTr_contexto();
	void increasePreemp();
	void executaT(vector<Tarefa> &t, int n_tarefas, int time,Gerencia *g);
	void defineU(vector<Tarefa> &t,int n_tarefas);
};
