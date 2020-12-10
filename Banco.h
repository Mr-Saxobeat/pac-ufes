#ifndef BANCO_H
#define BANCO_H
#include "ContaBancaria.h"
#include "Imprimivel.h"
#include <vector>

class Banco: public Imprimivel{
public:
    Banco();
    void inserir(ContaBancaria &conta);
    void deletar(ContaBancaria &conta);
    ContaBancaria* procurarConta(int numeroDaConta);
    void mostrarDados() const;
private:
  std::vector <ContaBancaria> contas;
};

#endif
