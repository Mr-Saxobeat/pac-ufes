#ifndef MENU_H
#define MENU_H
#include "Banco.h"

class Menu{
public:
  Menu();
  void mostrarMenu();
  void menu_criarConta();
  void menu_selecionarConta();
  void menu_contaSelecionada(ContaBancaria* p_contaSelecionada);
  ContaBancaria* criarConta(int tipo, int numero, double saldo);
  bool removerConta();

private:
  Banco banco;
};

#endif
