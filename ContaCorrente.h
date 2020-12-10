#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H
#include "ContaBancaria.h"
#include "Imprimivel.h"

class ContaCorrente: public ContaBancaria, public Imprimivel{
public:
    ContaCorrente();
    ContaCorrente(int,double);
    void sacar(double a);
    void depositar(double b);
    void mostrarDados() const;
};

#endif