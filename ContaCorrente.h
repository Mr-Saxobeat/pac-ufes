#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H
#include <string>
#include "ContaBancaria.h"
#include "Imprimivel.h"

class ContaCorrente: public ContaBancaria{
public:
  ContaCorrente(int numero, double saldo);
  bool sacar(double valor);
  bool depositar(double valor);
private:
  double taxaDeOperacao;
};

#endif
