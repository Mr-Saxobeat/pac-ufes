#include "ContaBancaria.h"
#include "ContaPoupanca.h"
#include "Imprimivel.h"
#include <math.h>
#include <iostream>

ContaPoupanca::ContaPoupanca(int numero_, double saldo_):
  ContaBancaria("Conta Poupança", numero_, saldo_),
  limite(100){};

bool ContaPoupanca::sacar(double valor){
    if(valor > 0 && abs(saldo - valor) <= limite){
      saldo -= valor;
      return true;
    } else {
      return false;
    }
}
