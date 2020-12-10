#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

class ContaBancaria{
public:
    ContaBancaria(int numero, double saldo);
    virtual void Sacar(double valor);
    virtual void Depositar(double valor);
    void Transferir(double valor, ContaBancaria &contaDestino);
    int getNumero() const;
    double getSaldo() const;
    bool operator==(const ContaBancaria&) const;
protected:
    int numero;
    double saldo;
};

#endif
