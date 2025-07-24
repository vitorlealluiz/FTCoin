#ifndef MOVIMENTACAODAO_HPP
#define MOVIMENTACAODAO_HPP
#include <string>
#include <vector>
#include "Date.hpp"
//#include "movimentacao.hpp"
using namespace std;
   
class Movimentacao; //ja declara a movimentacao p/ nao ter problema
    
class Vetor{
        private:
            vector<Movimentacao> mov;
        
        public:
            bool conferirId(int id);
            void novaCompra(Movimentacao m);
            void novaVenda(Movimentacao m);
            double pesquisa(int i, int id, int num);
            int getSize() const;
            vector<Movimentacao> listaMovimentacoes(int idCarteira) const;
            //vector<Movimentacao> listar(int idC);

    };

#endif