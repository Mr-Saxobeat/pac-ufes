#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "Relatorio.h"
#include "Executavel.h"

Executavel::Executavel(){}

void Executavel::executar(){
    ContaCorrente cCorrente(123, 0);
    cCorrente.depositar(10);
    cCorrente.sacar(5);

    ContaPoupanca cPoupanca(456, 0);
    cPoupanca.depositar(100);
    cPoupanca.sacar(150);

    Relatorio relatorio;
    relatorio.gerarRelatorio(cCorrente);
    relatorio.gerarRelatorio(cPoupanca);
}
