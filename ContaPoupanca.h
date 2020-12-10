#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H
#include "ContaBancaria.h"
#include "Imprimivel.h"

class ContaPoupanca:public ContaBancaria, public Imprimivel{
public:
    ContaPoupanca();
    ContaPoupanca(int,double);
    void sacar(double a);
    void mostrarDados() const;
};

#endif