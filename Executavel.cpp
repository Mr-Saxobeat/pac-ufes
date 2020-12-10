#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "Relatorio.h"
#include "Executavel.h"

Executavel::Executavel(){}

void Executavel::executar(){
    ContaCorrente cCorrente(123, 0);
    cCorrente.depositar(100);
    cCorrente.sacar(50);

    ContaPoupanca cPoupanca(456, 0);
    cPoupanca.depositar(100);
    cPoupanca.sacar(200);

    Relatorio relatorio;
    relatorio.gerarRelatorio(cCorrente);
    relatorio.gerarRelatorio(cPoupanca);
}
