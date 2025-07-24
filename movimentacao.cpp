#include "movimentacao.hpp"
#include "movimentacaoDAO.hpp"
#include "oraculo.hpp"
#include <iostream>
using namespace std;

static Random oraculo(1.0f, 100.0f);

Movimentacao::Movimentacao(CarteiraDAO& dao, Vetor& mdao)
    : carteiraDAO(dao), movimentacaoDAO(mdao), idCarteira(0), idMovimento(0),
      tipoOperacao(' '), quantMovimentada(0.0f), precoTransacao(0.0) {}

int Movimentacao::gerarID() {
    static int id = 0;
    return ++id;
}

void Movimentacao::registrar() {
    int id = carteiraDAO.recuperarCarteira();
    if (id == 0) {
        cout << "Carteira nao encontrada. Tente novamente." << endl;
        return;
    }

    idCarteira = id;
    idMovimento = gerarID();

    if (movimentacaoDAO.conferirId(idMovimento)) {
        cout << "Data da Operacao (dd/mm/aaaa): ";
        cin >> dataOperacao;

        cout << "Quantidade Movimentada: ";
        cin >> quantMovimentada;

        cout << "Tipo da Operacao (C para compra, V para venda): ";
        cin >> tipoOperacao;

        conferirOperacao();
    } else {
        cout << "ERRO: Identificador ja cadastrado." << endl;
    }
}

void Movimentacao::conferirOperacao() {
    if (tipoOperacao == 'C' || tipoOperacao == 'c') {
        registrarCompra();
    } else if (tipoOperacao == 'V' || tipoOperacao == 'v') {
        registrarVenda();
    } else {
        cout << "ERRO: Tipo de operacao invalido." << endl;
    }
}

void Movimentacao::registrarCompra() {
    precoTransacao = oraculo.gerarNumero(); // define preço ANTES de armazenar
    movimentacaoDAO.novaCompra(*this); // envia já com o preço correto
}

void Movimentacao::registrarVenda() {
    precoTransacao = oraculo.gerarNumero(); // define preço ANTES de armazenar
    movimentacaoDAO.novaVenda(*this);
}

// Getters e Setters
int Movimentacao::getId() const { return idMovimento; }
int Movimentacao::getIdCarteira() const { return idCarteira; }
char Movimentacao::getChar() const { return tipoOperacao; }
double Movimentacao::getQuant() const { return quantMovimentada; }
Date Movimentacao::getData() const { return dataOperacao; }
double Movimentacao::getPrecoTransacao() const { return precoTransacao; }
void Movimentacao::setPrecoTransacao(double p) { precoTransacao = p; }
