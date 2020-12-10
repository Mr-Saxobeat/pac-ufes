#include "ContaBancaria.h"
#include "ContaPoupanca.h"
#include "Imprimivel.h"
#include <math.h>
#include <iostream>

ContaPoupanca::ContaPoupanca(int numero_, double saldo_):
  ContaBancaria("Conta Poupança", numero_, saldo_),
  limite(100){};

void ContaPoupanca::sacar(double valor){
    if (abs(saldo - valor) <= limite){
      saldo -= valor;
    } else {
      std::cout << "Não é possível efetuar o saque. Limite excedido.\n";
    }

    std::cout << std::endl;
    std::cout << "sacou da poupança" << std::endl;
    std::cout << std::endl;
}
