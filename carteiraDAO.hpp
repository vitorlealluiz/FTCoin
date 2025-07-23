#ifndef CARTEIRADAO_HPP
#define CARTEIRADAO_HPP

#include <vector>
#include "carteira.hpp"
using namespace std;

class CarteiraDAO{
    private:
        vector<Carteira> carteiras;
    
    public:
        int gerarID();
        int lerInteiros(const string& mensagem);
        string lerString(const string& mensagem);
        void exibirCarteira(Carteira c);
        bool incluirCarteira();
        int recuperarCarteira();
        bool editarCarteira();
        bool excluirCarteira();
        const vector<Carteira>& listarTodas() const; //para não alterar nada do vetor

};

#endif