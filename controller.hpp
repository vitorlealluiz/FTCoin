#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "menu.hpp"
#include "carteira.hpp"
#include "carteiraDAO.hpp"
#include "movimentacao.hpp"
#include "movimentacaoDAO.hpp"
#include "ajuda.hpp"
#include "relatorio.hpp"
#include <string>
using namespace std; 

class Controller{
    private:
        CarteiraDAO carteiraDAO;
        Vetor movimentacaoDAO;
        Movimentacao movimentacao{carteiraDAO, movimentacaoDAO};
        Relatorio relatorio{carteiraDAO, movimentacaoDAO};
        Ajuda ajuda;

    public:
        int exibirMenu(vector<string> opcoes, string titulo);
        void menuCarteira();
        void menuMovimentacao();
        void menuRelatorio();
        void menuAjuda();
        void executar();


};

#endif