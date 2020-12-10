#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H
#include <string>
#include "ContaBancaria.h"
#include "Imprimivel.h"

class ContaPoupanca: public ContaBancaria{
public:
    ContaPoupanca(int numero, double saldo);
    void sacar(double valor);
private:
  const std::string tipo = "Conta Poupança";
  double limite;
};

#endif
