#include <string>
#include <vector>
#include "carteira.hpp"
#include "carteiraDAO.hpp"

Carteira::Carteira(int idCarteira, string titular, string corretora):
idCarteira(idCarteira), titular(titular), corretora(corretora){};

int Carteira::getidCarteira() const {return idCarteira; };
string Carteira::getTitular() const {return titular; };
string Carteira::getCorretora() const {return corretora; };

void Carteira::setidCarteira(int idCarteira){this->idCarteira = idCarteira; };
void Carteira::setTitular(string titular){this->titular = titular; };
void Carteira::setCorretora(string corretora){this->corretora = corretora; };




