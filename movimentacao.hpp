#ifndef MOVIMENTACAO_HPP
#define MOVIMENTACAO_HPP

#include <iostream>
#include <string>
#include "Date.hpp"
#include "carteiraDAO.hpp"

using namespace std;

class Vetor; // declaração antecipada

class Movimentacao {
private:
    int idCarteira;
    int idMovimento;
    Date dataOperacao;
    char tipoOperacao;     // 'C' ou 'V'
    double quantMovimentada;
    double precoTransacao; // preço da moeda no momento da operação
    CarteiraDAO& carteiraDAO;
    Vetor& movimentacaoDAO;

public:
    Movimentacao(CarteiraDAO& dao, Vetor& mdao);

    int gerarID();
    void registrar();

    // Getters
    int getId() const;
    int getIdCarteira() const;
    char getChar() const;
    double getQuant() const;
    Date getData() const;
    double getPrecoTransacao() const;

    // Setters
    void setPrecoTransacao(double p);

    // Operações
    void conferirOperacao();
    void registrarCompra();
    void registrarVenda();
};

#endif
