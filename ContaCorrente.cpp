#include "ContaBancaria.h"
#include "ContaCorrente.h"
#include "Imprimivel.h"
#include <iostream>

ContaCorrente::ContaCorrente(int numero_, double saldo_):
  ContaBancaria("Conta Corrente", numero_, saldo_),
  taxaDeOperacao(1){};

void ContaCorrente::sacar(double valor){
  saldo -= valor;
  saldo -= taxaDeOperacao;

  std::cout << std::endl;
  std::cout << "sacou da corrente" << std::endl;
  std::cout << std::endl;
}

void ContaCorrente::depositar(double valor){
  saldo += valor;
  saldo -= taxaDeOperacao;

  std::cout << std::endl;
  std::cout << "depositou na corrente" << std::endl;
  std::cout << std::endl;
}
