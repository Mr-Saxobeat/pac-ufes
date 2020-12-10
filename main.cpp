#include "ContaBancaria.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "Imprimivel.h"
#include "Relatorio.h"
#include "Executavel.h"
#include "Banco.h"
#include <iostream>

int main(){
    Executavel exec;
    Banco morango;
    ContaCorrente conta(1234,0);
    morango.inserir(conta);
    //morango.deletar(conta);
    exec.executar();
    return 0; 
}