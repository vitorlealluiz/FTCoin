#include <string>
#include <vector>
#include "movimentacaoDAO.hpp"
#include "Date.hpp"
#include "movimentacao.hpp" 
#include "oraculo.hpp"
using namespace std;

/*Analisar no vetor de movimentação se o ID já existe */
bool Vetor::conferirId(int id){
    for (int i = 0; i < mov.size(); i++) {
        if(mov[i].getId() == id){
            return false;
        }
    }
    return true;

}

/*Adiciona um valor na movimentação*/
void Vetor::novaCompra(Movimentacao m){

    mov.push_back(m);   
    
}

/*Adiciona um valor dentro do vetor da movimentação*/
void Vetor::novaVenda(Movimentacao m){

    mov.push_back(m);
    
}

/*Avalia se é uma compra ou venda, somando a criptomoeda caso seja compra 
subtraindo a quantidade de moeda se for venda*/
double Vetor::pesquisa(int i, int id, int num){

    if(mov[i].getIdCarteira() == id){
        if(mov[i].getChar() == 'C' || mov[i].getChar() == 'c'){
                    return num = num + mov[i].getQuant();
                }else if(mov[i].getChar() == 'V' || mov[i].getChar() == 'v'){
                    return num = num - mov[i].getQuant();
                }
    }
    // Se não for a carteira procurada, retorna o número original
    return num;
    

}

/*Armazena o tamanho do vetor movimentação para saber o total*/
int Vetor::getSize() const{

    return mov.size();

}

/*Destaca as movimentações ocorridas numa carteira com o ID informado*/
vector<Movimentacao> Vetor::listaMovimentacoes(int idCarteira) const{

    vector<Movimentacao> lista;
    //cout << "TAM: " << mov.size() << endl;
    for(int i = 0; i < mov.size(); i++){
        if(mov[i].getIdCarteira() == idCarteira){
            lista.push_back(mov[i]);
        }
    }

    return lista;

}