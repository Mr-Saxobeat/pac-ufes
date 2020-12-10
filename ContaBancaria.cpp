#include "ContaBancaria.h"

ContaBancaria::ContaBancaria(int numero_, double saldo_ = 0): numero(numero_), saldo(saldo_){};

void ContaBancaria::Sacar(double valor_){
    saldo -= valor_;
}

void ContaBancaria::Depositar(double valor_){
    saldo += valor_;
}

void ContaBancaria::Transferir(double valor_, ContaBancaria& contaDestino_){
    Sacar(valor_);
    contaDestino_.Depositar(valor_);
}

int ContaBancaria::getNumero() const{
    return numero;
}

double ContaBancaria::getSaldo() const{
    return saldo;
}

bool ContaBancaria::operator==(const ContaBancaria& ref1) const{
    return ref1.numero == this->numero;
};
