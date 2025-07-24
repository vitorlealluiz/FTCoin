#ifndef CARTEIRA_HPP
#define CARTEIRA_HPP

#include <string>
#include "menu.hpp"
using namespace std;


class Carteira{
    private:
        int idCarteira; 
        string titular;
        string corretora;

    public:
        Carteira(int idCarteira, string titular, string corretora);
        int getidCarteira() const;
        string getTitular() const;
        string getCorretora() const;
        void setidCarteira(int idCarteira);
        void setTitular(string titular);
        void setCorretora(string corretora);

        
};

#endif