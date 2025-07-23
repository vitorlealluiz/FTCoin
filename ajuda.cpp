#include <iostream>
#include "ajuda.hpp"
using namespace std;

void Ajuda::ajudaPrograma(){
    cout << "============================================================" << endl;
    cout << "               AJUDA - SISTEMA DE CRIPTOMOEDAS              " << endl;
    cout << "============================================================" << endl;
    cout << "Este programa simula um sistema de compra e venda de criptomoedas." << endl;
    cout << "Voce deve interagir com o sistema por meio do teclado, escolhendo" << endl;
    cout << "as opcoes exibidas no menu principal." << endl << endl;

    cout << "Funcionalidades disponiveis:" << endl;
    cout << "1. Carteira       - Gerencie suas carteiras de moedas virtuais." << endl;
    cout << "2. Movimentacao   - Registre operacoes de compra e venda." << endl;
    cout << "3. Relatorios     - Consulte saldos, historico e desempenho das carteiras." << endl;
    cout << "4. Ajuda          - Exibe este texto de ajuda e informacoes sobre o sistema." << endl;
    cout << "5. Sair           - Encerra o programa com seguranca." << endl << endl;

    cout << "Para utilizar o sistema, basta inserir o numero correspondente" << endl;
    cout << "a opcao desejada quando o menu principal for exibido." << endl;
    cout << "Certifique-se de seguir as instrucoes apresentadas em cada etapa." << endl;
    cout << "De acordo com a escolha do usuario, novos menus serao exibidos para apresentar" << endl;
    cout << "novas funcionalidade e na tela serao apresentadas as orientacoes sobre qual deve ser" << endl;
    cout << "o input correto" << endl;
    cout << "============================================================" << endl << endl;
}

void Ajuda::creditos(){
    cout << "============================================================" << endl;
    cout << "                      TELA DE CREDITOS                      " << endl;
    cout << "============================================================" << endl;
    cout << "Este trabalho foi desenvolvido no contexto da disciplina de " << endl;
    cout << "Banco de Dados I (SI300 - Turma A), ministrada pelo Prof. Dr." << endl;
    cout << "Andre F. de Angelis no curso de Sistemas de Informação." << endl << endl;

    cout << "Durante o desenvolvimento do projeto, foram reutilizadas as classes" << endl;
    cout << "DATE e MENU fornecidas no Projeto Agregador apresentado pelo" << endl;
    cout << "professor em sala de aula, adaptadas conforme as necessidades" << endl;
    cout << "especificas do sistema." << endl << endl;

    cout << "Autores do projeto:" << endl;
    cout << "- Alex Freire (RA: 199725)" << endl;
    cout << "- Vitor Luiz Leal da Silva (RA: 281459)" << endl;
    cout << "- Giovana Ruiz de Souza (RA: 281417)" << endl;
    cout << "- Igor Romano Filleti (RA: 281424)" << endl << endl;
}