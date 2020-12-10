#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H
#include <string>
#include "Imprimivel.h"

class ContaBancaria: public Imprimivel{
public:
    ContaBancaria(std::string tipo, int numero, double saldo);
    virtual void sacar(double valor);
    virtual void depositar(double valor);
    void transferir(double valor, ContaBancaria &contaDestino);
    int getNumero() const;
    double getSaldo() const;
    std::string getTipo() const;
    virtual void mostrarDados() const;
    bool operator==(const ContaBancaria&) const;
protected:
    int numero;
    double saldo;
    std::string tipo;
};

#endif
