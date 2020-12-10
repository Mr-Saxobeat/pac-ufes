#ifndef BANCO_H
#define BANCO_H
#include "ContaBancaria.h"
#include "Imprimivel.h"
#include <vector>

class Banco{
public:
    Banco();
    void inserir(ContaBancaria&);
    void deletar(ContaBancaria&);
    ContaBancaria procurarConta(int);
};

#endif