#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

class ContaBancaria{
public:
    ContaBancaria();
    ContaBancaria(int,double);
    virtual void sacar(double);
    virtual void depositar(double);
    void transferir(double,ContaBancaria&);
    int get_numero();
    double get_saldo();
    bool operator==(const ContaBancaria&) const;
protected:
    int numero;
    double saldo;
};

#endif