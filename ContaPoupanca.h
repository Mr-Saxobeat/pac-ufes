#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H
#include <string>
#include "ContaBancaria.h"
#include "Imprimivel.h"

class ContaPoupanca: public ContaBancaria{
public:
  ContaPoupanca(int numero, double saldo);
  bool sacar(double valor);
private:
  double limite;
};

#endif
