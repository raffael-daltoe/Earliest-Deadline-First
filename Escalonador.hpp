#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#define MAX_N 26
#define MAX_T 100000
using namespace std;
#include "Gerencia.hpp"

class Escalonador{
    static bool compararTarefas(const Tarefa& t1, const Tarefa& t2);
public:
	char Organiza_Tarefas(vector<Tarefa> &t);
	char escalona(Tarefa *nova, Tarefa *antiga, int exec, Gerencia *g);
    void atualizatarefas(vector<Tarefa> &t);
};
