#include "Gerencia.hpp"
#include "Escalonador.hpp"

char* Gerencia::obtemGrade() { return grade; }
unsigned Gerencia::obtemTr() { return tr_contexto; }
unsigned Gerencia::obtemPreemp() { return preemp; }
double Gerencia::obtemU() { return U; }

void Gerencia::increaseTr_contexto()
{
    tr_contexto += 1;
}

void Gerencia::increasePreemp()
{
    preemp += 1;
}
void Gerencia::executaT(vector<Tarefa> &t, int n_tarefas, int time, Gerencia *g)
{
    Escalonador sched;
    char ant='1',nov='2';
    Tarefa *antiga=nullptr, *nova = nullptr;
    int i = 0, execucao = 0,flag=0;
    while (i!= time)
    {
        sched.atualizatarefas(t); 
        nov = sched.Organiza_Tarefas(t);                                       // atualiza o periodo das tarefas
        antiga = busca(ant,t);
        nova = busca(nov,t);
        
        if ( nova == nullptr ){
            if(flag == 1)increaseTr_contexto();
            flag = 0;
            //antiga = nullptr;
            incrementaGrade('.',i);
        }
        else{
            if (nova != antiga)                                                 // se for a mesma tarefa, não vai escalonar!!!
            {
                ant = sched.escalona(nova, antiga, execucao,g);        // vai escalonar se for diferente
                execucao = 0;
                flag = 1;
            }
            nova->defineComputacao_tmp(nova->obtemComput_tmp()+1);
            incrementaGrade(nova->obtemLetra(), i);
        }
            i++;
            execucao++;
    }
}
void Gerencia::defineU(vector<Tarefa> &t, int n_tarefas)
{
    U = 0;
    for (int i = 0; i < n_tarefas; ++i)
        U = U + (static_cast<double>(t[i].obtemC()) / t[i].obtemP()); // converte o C em ponto flutuante e então se consegue o valor da div
}

void Gerencia::incrementaGrade(char l,int i){
    grade[i] = l;
}

Tarefa* Gerencia::busca(char l,vector<Tarefa> &t){
    for(int i=0;i<t.size();i++){
        if(t[i].obtemLetra() == l) return (&(t[i]));
    }
    return nullptr;
}