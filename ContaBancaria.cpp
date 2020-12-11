#include <iostream>
#include <string>
#include "ContaBancaria.h"

ContaBancaria::ContaBancaria(std::string tipo_, int numero_, double saldo_ = 0):
  tipo(tipo_),
  numero(numero_),
  saldo(saldo_)
  {};

bool ContaBancaria::sacar(double valor){
    if (valor > 0 && saldo >= valor){
      saldo -= valor;
      return true;
    } else {
      return false;
    }
}

bool ContaBancaria::depositar(double valor){
    if(valor > 0){
      saldo += valor;
      return true;
    } else {
      return false;
    }
}

bool ContaBancaria::transferir(double valor, ContaBancaria& contaDestino){
    if(valor > 0){
        sacar(valor);
        contaDestino.depositar(valor);
        return true;
    } else {
      return false;
    }
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

bool ContaBancaria::operator==(const ContaBancaria& conta2) const{
    return this->numero == conta2.numero;
};

void ContaBancaria::mostrarDados() const{
  std::cout << std::endl;
  std::cout << "--------------------------------------------------------------" << std::endl;
  std::cout << "| " << getTipo() << std::endl;
  std::cout << "| Número: " << getNumero() << std::endl;
  std::cout << "| Saldo: R$ " << getSaldo() << std::endl;
  std::cout << "--------------------------------------------------------------" << std::endl;
  std::cout << std::endl;
}
