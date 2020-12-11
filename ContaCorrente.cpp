#include "ContaBancaria.h"
#include "ContaCorrente.h"
#include "Imprimivel.h"
#include <iostream>

ContaCorrente::ContaCorrente(int numero_, double saldo_):
  ContaBancaria("Conta Corrente", numero_, saldo_),
  taxaDeOperacao(1){};

bool ContaCorrente::sacar(double valor){
  if (valor > 0 && saldo >= (valor + taxaDeOperacao)){
    saldo -= valor + taxaDeOperacao;
    return true;
  } else {
    return false;
  }
}

bool ContaCorrente::depositar(double valor){
  if(valor > 0 && (saldo + valor) >= taxaDeOperacao){
    saldo += valor;
    saldo -= taxaDeOperacao;
    return true;
  } else {
    return false;
  }
}
