#ifndef MENU_H
#define MENU_H
#include "Banco.h"

class Menu{
public:
  Menu();
  void mostrarMenu();
  void criarConta();
  void selecionarConta();
  void removerConta();
private:
  Banco banco;
};

#endif
