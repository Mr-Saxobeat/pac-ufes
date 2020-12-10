#include <iostream>
#include <memory>
#include "Menu.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "Banco.h"
#include "Relatorio.h"

Menu::Menu(){
  Banco banco();
}

void Menu::mostrarMenu(){
  int opcao = 0;

  while(opcao != 5){
    std::cout << std::endl;
    std::cout << "Selecione a opção desejada: " << std::endl;
    std::cout << "[1] Criar conta" << std::endl;
    std::cout << "[2] Selecionar conta" << std::endl;
    std::cout << "[3] Remover conta" << std::endl;
    std::cout << "[4] Gerar relatório" << std::endl;
    std::cout << "[5] Finalizar" << std::endl;

    std::cin >> opcao;

    switch (opcao) {
      case 1:
        criarConta();
        break;
      case 2:
        selecionarConta();
        break;
      case 3:
        removerConta();
      case 4:
        banco.mostrarDados();
        break;
      case 5:
        break;
    }
  }
}

void Menu::criarConta(){
  int tipo;
  int numero;
  double saldo;
  ContaBancaria *p_conta_aux;
  std::unique_ptr <ContaBancaria> p_conta;

  std::cout << std::endl;
  std::cout << "---------------" << std::endl;
  std::cout << "| Criar conta |" << std::endl;
  std::cout << "---------------" << std::endl;

  std::cout << "Escolha o tipo da conta: [1] Conta Corrente   [2] Conta Poupança:  ";
  std::cin >> tipo;

  // Verifica se o número já está sendo usado por outra conta
  do{
    std::cout << "Digite o número da conta: ";
    std::cin >> numero;

    p_conta_aux = banco.procurarConta(numero);
    if(p_conta_aux){
      std::cout << "Número de conta já usado. Tente novamente." << std::endl;
      std::cout << std::endl;
    }
  } while(p_conta_aux);

  std::cout << "Digite o saldo da conta: ";
  std::cin >> saldo;

  if (tipo == 1){
    p_conta = std::make_unique <ContaCorrente>(numero, saldo);
  } else if (tipo == 2){
    p_conta = std::make_unique <ContaPoupanca>(numero, saldo);
  }

  banco.inserir(*p_conta);

  std::cout << "---------------------------------------" << std::endl;
  std::cout << "| " << p_conta->getTipo() << ", nº " << p_conta->getNumero() << " criada com sucesso! |" << std::endl;
  std::cout << "---------------------------------------" << std::endl;
}

void Menu::selecionarConta(){
  ContaBancaria* p_conta;
  ContaBancaria* p_contaDestino;
  int numero;
  int opcao = 0;
  int valor = 0;
  Relatorio relatorio;

  std::cout << std::endl;
  std::cout << "--------------------" << std::endl;
  std::cout << "| Selecionar conta |" << std::endl;
  std::cout << "--------------------" << std::endl;


  do{
    std::cout << "Digite o número da conta: " << std::endl;
    std::cin >> numero;

    p_conta = banco.procurarConta(numero);
    if(!p_conta){
      std::cout << "Conta não econtrada. Tente novamente." << std::endl;
      std::cout << std::endl;
    }
  }while(!p_conta);

  while(opcao != 5){
    std::cout << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "| " << p_conta->getTipo() << ", nº " << p_conta->getNumero() << " selecionada. |" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Escolha a opção desejada: " << std::endl;
    std::cout << "[1] Depositar" << std::endl;
    std::cout << "[2] Sacar" << std::endl;
    std::cout << "[3] Transferir" << std::endl;
    std::cout << "[4] Gerar relatório" << std::endl;
    std::cout << "[5] Retornar ao menu anterior" << std::endl;

    std::cin >> opcao;

    switch (opcao) {
      case 1:
        std::cout << std::endl;
        std::cout << "---- Depósito na " << p_conta->getTipo() << ", nº " << p_conta->getNumero() << " ----" << std::endl;
        std::cout << "Digite o valor a ser depositado: ";

        do{
          std::cin >> valor;

          if(valor < 0){
            std::cout << std::endl;
            std::cout << "Valor inválido. Tente novamente." << std::endl;
            std::cout << std::endl;
          }
        }while(valor < 0);

        p_conta->depositar(valor);
        std::cout << "R$ " << valor << " foram depositados em " << p_conta->getTipo() <<  ", nº " << p_conta->getNumero() << std::endl;
        break;
      case 2:
        std::cout << std::endl;
        std::cout << "----" << "Saque em " << p_conta->getTipo() << ", nº " << p_conta->getNumero() << " ----" << std::endl;
        std::cout << "Digite o valor do saque: ";

        do{
          std::cin >> valor;

          if(valor < 0){
            std::cout << std::endl;
            std::cout << "Valor inválido. Tente novamente." << std::endl;
          }
        }while(valor < 0);

        p_conta->sacar(valor);
        break;
      case 3:
        std::cout << std::endl;
        std::cout << "--- Transferência da conta nº " << p_conta->getNumero() << " ----" << std::endl;

        do{
          if(valor < 0){
            std::cout << "Digite o valor a ser transferido: ";
            std::cin >> valor;

            std::cout << std::endl;
            std::cout << "Valor inválido. Tente novamente." << std::endl;
          }
        }while(valor < 0);

        do{
          std::cout << "Digite o número da conta destino: ";
          std:: cin >> numero;
          p_contaDestino = banco.procurarConta(numero);

          if(!p_contaDestino){
            std::cout << std::endl;
            std::cout << "Conta não encontrada. Tente novamente." << std::endl;
          }
        }while(!p_contaDestino);

        p_conta->transferir(valor, *p_contaDestino);
        break;
      case 4:
        std::cout << std::endl;
        // std::cout << "---- Relatório da " << p_conta->getTipo() << ", nº " << p_conta->getNumero() << " ----" << std::endl;
        relatorio.gerarRelatorio(*p_conta);
        break;
      case 5:
        break;
      default:
        opcao = 0;
        break;
    }
  }
}

void Menu::removerConta(){
  int numero;
  ContaBancaria *p_conta;

  std::cout << std::endl;
  std::cout << "-----------------" << std::endl;
  std::cout << "| Remover conta |" << std::endl;
  std::cout << "-----------------" << std::endl;

  do{
    std::cout << "Digite o número da conta: " << std::endl;
    std::cin >> numero;

    p_conta = banco.procurarConta(numero);
    if(!p_conta){
      std::cout << std::endl;
      std::cout << "Conta não encontrada. Tente novamente.";
    }
  }while(!p_conta);

  banco.deletar(*p_conta);
}
