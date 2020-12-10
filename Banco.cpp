#include "Banco.h"
#include "ContaBancaria.h"
#include <iostream>
#include <vector>

Banco::Banco(){};

std::vector <ContaBancaria> contas;

void Banco::inserir(ContaBancaria& conta){
    contas.push_back(conta);
}
void Banco::deletar(ContaBancaria& conta){
    int i;
    for(i=0;i<=contas.size()-1;i++){
        if (contas[i] == conta)contas.erase(contas.begin()+i);
    }
}
ContaBancaria Banco::procurarConta(int num){
    int i;
    for(i=0;i<=contas.size()-1;i++){
        if (contas[i].get_numero() == num) return contas[i];
    }
}