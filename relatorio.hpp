#ifndef RELATORIO_HPP
#define RELATORIO_HPP
#include <string>
#include "movimentacaoDAO.hpp"
#include "carteiraDAO.hpp"

class Relatorio{
    private:
        int idCarteira;
        int idMovimentacao;
        CarteiraDAO& carteiraDAO;
        Vetor& movimentacaoDAO;


    public:
        Relatorio(CarteiraDAO& dao, Vetor& mdao);
        void listarCarteiraID();
        void listarCarteiraTitular();
        void exibirSaldo();
        void exibirMovimentacao();
        void statusGanhaPerda();

};

#endif