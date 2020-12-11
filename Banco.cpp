#include <iostream>
#include <vector>
#include <memory>
#include "Banco.h"
#include "ContaBancaria.h"

Banco::Banco(){};

void Banco::inserir(ContaBancaria* conta){
  contas.push_back(conta);
}

void Banco::deletar(ContaBancaria* conta){
    for(int i = 0; i < contas.size(); i++){
        if (contas[i] == conta){
          contas.erase(contas.begin() + i);
        }
    }
}

void Banco::mostrarDados() const{
  for(int i = 0; i < contas.size(); i++){
    contas[i]->mostrarDados();
  }
}

ContaBancaria* Banco::procurarConta(int num){
    for(int i = 0; i < contas.size(); i++){
        if (contas[i]->getNumero() == num) {
          return contas[i];
        }
    }

    // Se a conta com o número dado não for encontrada
    // retorna um ponteiro null
    return nullptr;
}
