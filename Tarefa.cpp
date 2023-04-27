#include "Tarefa.hpp"
Tarefa::Tarefa(unsigned parC, unsigned parP, unsigned parD,char l) {
	define(parC,parP,parD,l);
	state = false;
	time_exec =0;
	Comput_tmp =0;
	d_dinamic =0;
	letra = '\0';
}
unsigned Tarefa::obtemC() { return c; }
unsigned Tarefa::obtemP() { return p; }
unsigned Tarefa::obtemD() { return d; }
char Tarefa::obtemLetra() { return letra; }
unsigned Tarefa::obtemTime_exec() { return time_exec;}
unsigned Tarefa::obtemComput_tmp() {return Comput_tmp;}


unsigned Tarefa::obtemD_dinamic()const { return d_dinamic;}
bool Tarefa::obtemState() { return state; }
void Tarefa::defineTime_exec(unsigned exec){ time_exec = exec;}
void Tarefa::defineState(bool v){ state = v; }
void Tarefa::defineC(unsigned parC) { c = parC; }
void Tarefa::defineP(unsigned parP) { p = parP; }
void Tarefa::defineD(unsigned parD) { d = parD; }
void Tarefa::define(unsigned parC, unsigned parP, unsigned parD,char l) {
	c = parC;
	p = parP;
	d = parD;
	letra = l;
}
void Tarefa::defineComputacao_tmp(unsigned Compt){ Comput_tmp = Compt; }
void Tarefa::defineD_dinamic(unsigned DI){ d_dinamic = DI;}
void Tarefa::defineLetra(char l){ letra = l; }