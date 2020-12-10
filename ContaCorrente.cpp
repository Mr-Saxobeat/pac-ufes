#include "ContaBancaria.h"
#include "ContaCorrente.h"
#include "Imprimivel.h"
#include <iostream>

ContaCorrente::ContaCorrente():ContaBancaria(){};

ContaCorrente::ContaCorrente(int a,double b):ContaBancaria(a,b){};

double taxaDeOperacao = 1;

void ContaCorrente::sacar(double a){
    saldo-= a;
    saldo-= taxaDeOperacao;
}
void ContaCorrente::depositar(double b){
    saldo+= b;
    saldo-= taxaDeOperacao;
}
void ContaCorrente::mostrarDados() const{
    std::cout << "O número é:" << numero << std::endl;
    std::cout << "O saldo é:" << saldo << std::endl;
}