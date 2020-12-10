#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "Relatorio.h"
#include "Executavel.h"

Executavel::Executavel(){}

void Executavel::executar(){
    ContaCorrente conta1(123,0);
    conta1.depositar(100);
    conta1.sacar(100);

    ContaPoupanca conta2(456,0);
    conta2.depositar(100);
    conta2.sacar(101);

    Relatorio dados;
    dados.gerarRelatorio(conta1);
    dados.gerarRelatorio(conta2);
}