#include "Escalonador.hpp"

char Escalonador::Organiza_Tarefas(vector<Tarefa> &t)
{
    std::sort(t.begin(), t.end(), compararTarefas);
    for(int i=0;i<t.size();i++){
        /*cout<<"Tarefa = "<<t[i].obtemLetra()<< " | state= "
        << t[i].obtemState() << " | Compt_tmp = "<<t[i].obtemComput_tmp()<<
        " | obtemTime_exec = "<< t[i].obtemTime_exec()<< endl;  
        */if (t[i].obtemState() == false){
            //cout<<"retornou = " << t[i].obtemLetra()<<endl;
            return (t[i].obtemLetra());
        
        }
    }
    return '.';
    // vai verificar qual o valor do deadline dinamico e retornar se aquela tarefa atual continua, se não, vai ter que escalonar outra
}

char Escalonador::escalona(Tarefa *nova, Tarefa *antiga, int exec, Gerencia *g)
{
    if(antiga!= nullptr){
        cout<<"antiga = "<<antiga->obtemLetra()<<endl;
        if(antiga->obtemComput_tmp() < antiga->obtemC()){ 
            g->increasePreemp();
        }
    }
    cout<<"nova = "<<nova->obtemLetra() <<endl;
    cout<<"contexto  =  "<< g->obtemTr()<<endl;
    g->increaseTr_contexto();
    return nova->obtemLetra();
    // aqui ele vai trocar de contexto, vai colocar outra tarefa para processar
}

bool Escalonador::compararTarefas(const Tarefa& t1, const Tarefa& t2) {
    // Implementa o critério de comparação entre duas tarefas
    // Neste exemplo, compara as tarefas com base no valor retornado pelo método obtemD()
    return t1.obtemD_dinamic() < t2.obtemD_dinamic();
}

void Escalonador::atualizatarefas(vector<Tarefa> &t){

    for (vector<Tarefa>::iterator it = t.begin(); it != t.end(); ++it){
    
        if(it->obtemComput_tmp() >= it->obtemC()){
            it->defineState(true);
        }
        if(it->obtemP() == it->obtemTime_exec()){                      // verifica se o periodo já está renovado
            it->defineTime_exec(0);                                    // se estiver ele define 0 o tempo dela e o estado false para escalonar
            it->defineComputacao_tmp(0);
            it->defineState(false);
        }
        it->defineD_dinamic(it->obtemD() - it->obtemTime_exec());
        it->defineTime_exec(it->obtemTime_exec()+1);                   //atualiza qual o tempo real da tarefa
        
    }
}