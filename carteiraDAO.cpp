#include "carteiraDAO.hpp"
#include <vector>
#include <string>
#include <limits> //Para numeric_limits
#include <iostream>
using namespace std;

/*Gera o IDs incrementais para cada carteira
o uso do 'static' mantém o valor das chamadas*/
int CarteiraDAO::gerarID(){
    static int id = 0; 
    return ++id;     
}

/*Lê o input do usuário até receber um valor válido
limpa o buffer após leitura para evitar valores residuais*/
int CarteiraDAO::lerInteiros(const string& mensagem){
    int valor;
    while (true) {
        cout << mensagem;
        cin >> valor;

        //Limpa o buffer de entrada (como \n)
        if (cin.good()) { 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;

        } else{
        cout << "Entrada invalida! Digite apenas numeros.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Descarta entrada inválida
        }
    }
}

/*Lê o input do usuário até receber um valor válido
limpa o buffer após leitura para evitar valores residuais*/
string CarteiraDAO::lerString(const string& mensagem){
    string valor;

    //Lê o input até ter valor válido
    while (true){
        cout << mensagem;
        getline(cin, valor);

        //Verifica se o valor não é vazio
        if (valor.empty()){
            cout << "Este campo nao pode ser vazio! Por favor, digite um valor" << endl;
        
        } else{
            return valor;
        }
    }
}

/*Exibe valores de uma carteira existente 
utiliza o 'const' para ser somente leitura e alterar a carteira*/
void CarteiraDAO::exibirCarteira(const Carteira c){
    cout << "\n\nCARTEIRA ENCONTRADA COM SUCESSO! "<< endl;
    cout << "ID: " << c.getidCarteira() << endl;
    cout << "TITULAR: " << c.getTitular() << endl;
    cout << "CORRETORA: " << c.getCorretora() << endl;
    cout <<"\n\n";
}

bool CarteiraDAO::incluirCarteira(){
    cout << "CADASTRO DE UMA NOVA CARTEIRA" << endl;
    int id = gerarID(); 

    //Analisa se já existe uma carteira dentro do vetor com o mesmo ID
    for(int i = 0; i < carteiras.size(); i++){

        if(carteiras[i].getidCarteira() == id){
            cout << "Erro! Carteira com ID fornecido (ID: " << id << ") ja existente no sistema" << endl;
            return false;
        }

    }
    
    //Avalia se as entradas do usuário são válidas
    string titular = lerString("Digite o nome do titular: ");
    string corretora = lerString("Digite o nome da corretora: ");
  
    //Cria e armazena as informações da nova carteira
    Carteira novaCarteira(id, titular, corretora);
    carteiras.push_back(novaCarteira);

    //Confirma os dados para o usuário
    exibirCarteira(novaCarteira);
    cout << "Inclusao realizada com sucesso!\n" << endl;
    
    return true; // Inclusão realizada
}

/*Retorna um ponteiro para o objeto, devolve o endereço da carteira encontrada
ou nullprt caso não encontre*/
int CarteiraDAO::recuperarCarteira(){
    int id = lerInteiros("Digite o ID da carteira que deseja consultar: ");

    for(int i = 0; i < carteiras.size(); i++){

        if(carteiras[i].getidCarteira() == id){
            exibirCarteira(carteiras[i]);
            return id;
        }

    }

    return 0;
}

bool CarteiraDAO::editarCarteira(){
    int id = lerInteiros("Digite o ID da carteira que deseja editar: ");

    //Percorre o vetor de carteiras para encontrar a carteira com o ID fornecido
    //Altera os dados da carteira se encontrada
    for(int i = 0; i < carteiras.size(); i++){

        if(carteiras[i].getidCarteira() == id){
            exibirCarteira(carteiras[i]);

            string novoTitular = lerString("Digite o novo titular (atual: " + carteiras[i].getTitular() + "): ");
            string novaCorretora = lerString("Digite a nova corretora (atual: " + carteiras[i].getCorretora() + "): ");
            carteiras[i].setTitular(novoTitular);
            carteiras[i].setCorretora(novaCorretora);

            cout << "\nCarteira atualizada com sucesso!\n" << endl;

            exibirCarteira(carteiras[i]);

            return true;

        }
        

    }
        cout << "\nErro! Carteira com ID fornecido (ID: " << id << ") nao foi encontrada.\n" << endl;
        return false;

}

bool CarteiraDAO::excluirCarteira(){
    int id = lerInteiros("Digite o ID da carteira que deseja excluir: ");

     for(int i = 0; i < carteiras.size(); i++){

        if(carteiras[i].getidCarteira() == id){

            int resposta;
            exibirCarteira(carteiras[i]);

            cout << "Voce tem certeza que deseja excluir a carteira acima? "<< endl;
            cout << "1- SIM" << endl;
            cout << "2- NAO" << endl;
            cin >> resposta;

            if (resposta == 1) {
                carteiras.erase(carteiras.begin() + i);
                cout << "\nExclusao realizada com sucesso!\n" << endl;
                return true; // Exclusão feito

            } else if (resposta == 2){
                cout << "\nA carteira nao sera excluida!\n"<< endl;
                return false; // Usuário optou não excluir 

            } else{
                cout << "\nErro! Opcao invalida\n" << endl;
                return false;
            }
        }     
    }
        cout << "\nErro ao encontrar o ID digitado\n" << endl;
        return false;
}

const vector<Carteira>& CarteiraDAO::listarTodas() const {
    return carteiras; //para facilitar na hora de listar 
}

