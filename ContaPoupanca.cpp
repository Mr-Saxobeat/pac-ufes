#include "ContaBancaria.h"
#include "ContaPoupanca.h"
#include "Imprimivel.h"
#include <math.h>
#include <iostream>

ContaPoupanca::ContaPoupanca():ContaBancaria(){};

ContaPoupanca::ContaPoupanca(int a,double b):ContaBancaria(a,b){}

double limite = 100;

void ContaPoupanca::sacar(double a){
    if(abs(saldo-a)<=limite) saldo-=a;
    else std::cout << "Não é possível efetuar o saque\n";
}
void ContaPoupanca::mostrarDados() const{
    std::cout << "O número é:" << numero << std::endl;
    std::cout << "O saldo é:" << saldo << std::endl;
}