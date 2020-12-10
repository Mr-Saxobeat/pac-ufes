#include "ContaBancaria.h"

ContaBancaria::ContaBancaria():numero(0),saldo(0){};

ContaBancaria::ContaBancaria(int a,double b):numero(a),saldo(b){};

void ContaBancaria::sacar(double a){
    saldo-= a;
}

void ContaBancaria::depositar(double b){
    saldo+= b;
}
void ContaBancaria::transferir(double valor,ContaBancaria& conta){
    sacar(valor);
    conta.depositar(valor);
}
int ContaBancaria::get_numero(){
    return numero;
}
double ContaBancaria::get_saldo(){
    return saldo;
}
bool ContaBancaria::operator==(const ContaBancaria& ref1) const{
    return ref1.numero == this->numero;
};