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
      case 1: // Opção para criar conta
        menu_criarConta();
        break;
      case 2:
        menu_selecionarConta();
        break;
      case 3:
        removerConta();
        break;
      case 4:
        banco.mostrarDados();
        break;
      case 5:
        break;
      default:
        std::cout << "Opção inválida. Digite um número de 1 a 5." << std::endl;
    }
  }
}

ContaBancaria* Menu::criarConta(int tipo, int numero, double saldo){
  ContaBancaria* p_novaConta;

  if(banco.procurarConta(numero)){
    return nullptr;
  } else {
    if (tipo == 1){
      p_novaConta = new ContaCorrente(numero, saldo);
    } else if (tipo == 2){
      p_novaConta = new ContaPoupanca(numero, saldo);
    }
  }

  banco.inserir(p_novaConta);

  return p_novaConta;
}

void Menu::menu_criarConta(){
  int tipo;
  int numero;
  double saldo;
  ContaBancaria* p_novaConta;
  ContaBancaria* p_contaExistente;

  std::cout << std::endl;
  std::cout << "---------------" << std::endl;
  std::cout << "| Criar conta |" << std::endl;
  std::cout << "---------------" << std::endl;

  do{
    while(true){
      std::cout << "Escolha o tipo da conta: [1] Conta Corrente   [2] Conta Poupança   [3] Voltar:  ";
      std::cin >> tipo;

      if(tipo >= 1 || tipo <= 3){
        break;
      } else {
        std::cout << "Opção inválida. Tente novamente." << std::endl;
      }
    }

    if(tipo == 3) break;

    // Verifica se o número digitado já está sendo usado por outra conta
    do{
      std::cout << "Digite o número da conta: ";
      std::cin >> numero;

      p_contaExistente = banco.procurarConta(numero);
      if(p_contaExistente){
        std::cout << "Número de conta já usado. Tente novamente." << std::endl;
        std::cout << std::endl;
      }
    } while(p_contaExistente);

    do{
      std::cout << "Digite o saldo da conta: ";
      std::cin >> saldo;

      if(saldo >= 0) break;

      std::cout << "Saldo inválido. Tente novamente." << std::endl;
    }while(saldo < 0);

    p_novaConta = criarConta(tipo, numero, saldo);
    if(p_novaConta){
      std::cout << "---------------------------------------" << std::endl;
      std::cout << "| " << p_novaConta->getTipo() << ", nº " << p_novaConta->getNumero() << " criada com sucesso! |" << std::endl;
      std::cout << "---------------------------------------" << std::endl;
    } else {
      std::cout << "---------------------------------------" << std::endl;
      std::cout << "| " << "Não foi possível criar a conta. Tente novamente." << std::endl;
      std::cout << "---------------------------------------" << std::endl;
    }
  }while(!p_novaConta);
}

void Menu::menu_selecionarConta(){
  int numero;
  ContaBancaria* p_contaSelecionada;

  std::cout << std::endl;
  std::cout << "--------------------" << std::endl;
  std::cout << "| Selecionar conta |" << std::endl;
  std::cout << "--------------------" << std::endl;

  do{
    std::cout << "Digite o número da conta: " << std::endl;
    std::cin >> numero;

    p_contaSelecionada = banco.procurarConta(numero);
    if(!p_contaSelecionada){
      std::cout << "Conta não econtrada. Tente novamente." << std::endl;
      std::cout << std::endl;
    }
  }while(!p_contaSelecionada);

  menu_contaSelecionada(p_contaSelecionada);
}

void Menu::menu_contaSelecionada(ContaBancaria* p_contaSelecionada){
  double valor;
  int numero_destino;
  ContaBancaria* p_contaDestino;
  Relatorio relatorio;
  int opcao = 0;

  while(opcao != 5){

    std::cout << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "| " << p_contaSelecionada->getTipo() << ", nº " << p_contaSelecionada->getNumero() << " selecionada. |" << std::endl;
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
        std::cout << "---- Depósito na " << p_contaSelecionada->getTipo() << ", nº " << p_contaSelecionada->getNumero() << " ----" << std::endl;
        std::cout << "Digite o valor a ser depositado: ";

        do{
          std::cin >> valor;

          if(valor < 0){
            std::cout << std::endl;
            std::cout << "Valor inválido. Tente novamente." << std::endl;
            std::cout << std::endl;
          }
        }while(valor < 0);

        p_contaSelecionada->depositar(valor);
        std::cout << "R$ " << valor << " foram depositados em " << p_contaSelecionada->getTipo() <<  ", nº " << p_contaSelecionada->getNumero() << std::endl;
        break;
      case 2:
        std::cout << std::endl;
        std::cout << "----" << "Saque em " << p_contaSelecionada->getTipo() << ", nº " << p_contaSelecionada->getNumero() << " ----" << std::endl;
        std::cout << "Digite o valor do saque: ";

        do{
          std::cin >> valor;

          if(valor < 0){
            std::cout << std::endl;
            std::cout << "Valor inválido. Tente novamente." << std::endl;
          }
        }while(valor < 0);

        p_contaSelecionada->sacar(valor);
        break;
      case 3:
        std::cout << std::endl;
        std::cout << "--- Transferência da conta nº " << p_contaSelecionada->getNumero() << " ----" << std::endl;

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
          std:: cin >> numero_destino;
          p_contaDestino = banco.procurarConta(numero_destino);

          if(!p_contaDestino){
            std::cout << std::endl;
            std::cout << "Conta não encontrada. Tente novamente." << std::endl;
          }
        }while(!p_contaDestino);

        p_contaSelecionada->transferir(valor, *p_contaDestino);
        break;
      case 4:
        std::cout << std::endl;
        // std::cout << "---- Relatório da " << p_novaConta->getTipo() << ", nº " << p_novaConta->getNumero() << " ----" << std::endl;
        relatorio.gerarRelatorio(*p_contaSelecionada);
        break;
      case 5:
        break;
      default:
        opcao = 0;
        break;
    }
  }
}

bool Menu::removerConta(){
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

  banco.deletar(p_conta);
  return true;
}
