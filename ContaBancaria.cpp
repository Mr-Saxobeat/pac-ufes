#include <iostream>
#include <string>
#include "ContaBancaria.h"

ContaBancaria::ContaBancaria(std::string tipo_, int numero_, double saldo_ = 0):
  tipo(tipo_),
  numero(numero_),
  saldo(saldo_)
  {};

void ContaBancaria::sacar(double valor){
    if (saldo >= valor){
      saldo -= valor;
    } else {
      std::cout << "Saldo insuficiente. Saque não realizado." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "sacou na bancária" << std::endl;
    std::cout << std::endl;
}

void ContaBancaria::depositar(double valor){
    saldo += valor;

    std::cout << std::endl;
    std::cout << "depositou na bancária" << std::endl;
    std::cout << std::endl;
}

void ContaBancaria::transferir(double valor, ContaBancaria& contaDestino){
    sacar(valor);
    contaDestino.depositar(valor);
}

int ContaBancaria::getNumero() const{
    return numero;
}

double ContaBancaria::getSaldo() const{
    return saldo;
}

std::string ContaBancaria::getTipo() const{
  return tipo;
}

bool ContaBancaria::operator==(const ContaBancaria& ref1) const{
    return ref1.numero == this->numero;
};

void ContaBancaria::mostrarDados() const{
  std::cout << std::endl;
  std::cout << "-------------------------------------------------------------------------" << std::endl;
  std::cout << "| Tipo: " << getTipo() << std::endl;
  std::cout << "| Número: " << getNumero() << std::endl;
  std::cout << "| Saldo: " << getSaldo() << std::endl;
  std::cout << "-------------------------------------------------------------------------" << std::endl;
  std::cout << std::endl;
}
