#include "controller.hpp"
#include <string>
using namespace std;


/*Recebe as opções do menu e seu título,
útil pois vamos trabalhar com vários menus diferentes*/
int Controller::exibirMenu(vector<string> opcoes, string titulo){
    Menu menu(opcoes, titulo);
    return menu.getChoice();
}

/*Esse método (lógica seguida pelos outros menus) insere as opções do menu, seu título
e estabelece um laço para o usuário poder escolher a opção */
void Controller::menuCarteira(){
vector<string> opcoes;

/*Insere os valores dentro do vetor "opcoes"*/
    opcoes.push_back("Incluir um novo registro de carteira"); 
    opcoes.push_back("Recuperar um registro de carteira por identidade");  
    opcoes.push_back("Editar um registro de carteira existente"); 
    opcoes.push_back("Excluir um registro de carteira"); 
    opcoes.push_back("Voltar para o Menu Principal"); 

    int escolha = 0;

/*Estabelece o laço que vai chamar os métodos de acordo com a opção do usuário*/
    do{  
        escolha = exibirMenu(opcoes, "Menu Carteira");  
        switch (escolha){
        case 1: carteiraDAO.incluirCarteira(); break;
        case 2: carteiraDAO.recuperarCarteira(); break;
        case 3: carteiraDAO.editarCarteira(); break;
        case 4: carteiraDAO.excluirCarteira(); break;
        case 5: return;
        default: cout << "Opcao invalida" << endl; break;
        }
    } while(escolha != 0);
}

void Controller::menuMovimentacao(){
    vector<string> opcoes;
    opcoes.push_back("Registrar movimentacao de moeda virtual em uma carteira");
    opcoes.push_back("Voltar para o Menu Principal");

    int escolha = 0;
    do{  
        escolha = exibirMenu(opcoes, "Menu Movimentacao");                        
        switch (escolha){
        case 1: movimentacao.registrar(); break;
        case 2: return;
        default: cout << "Opcao invalida" << endl; break;
        }
    } while(escolha != 0);
}

void Controller::menuRelatorio(){
    vector<string> opcoes;
    opcoes.push_back("Listar carteiras ordenadas por Identificador");
    opcoes.push_back("Listar carteiras ordenadas por Nome do Titular");
    opcoes.push_back("Exibir saldo de uma carteira especifica");
    opcoes.push_back("Exibir historico de movimentacao de uma carteira especifica");
    opcoes.push_back("Apresentar ganho ou perda total de cada carteira");
    opcoes.push_back("Voltar para o Menu Principal");
    
    int escolha = 0;
    do{  
        escolha = exibirMenu(opcoes, "Menu Relatorio");
        switch (escolha){
        case 1: relatorio.listarCarteiraID(); break;
        case 2: relatorio.listarCarteiraTitular(); break;
        case 3: relatorio.exibirSaldo(); break;
        case 4: relatorio.exibirMovimentacao(); break;
        case 5: relatorio.statusGanhaPerda(); break;
        case 0: cout << "Saindo do sistema..." << endl; break;
        default: cout << "Opcao invalida" << endl; break;
        }
    } while(escolha != 0);

}

void Controller::menuAjuda(){
    vector<string> opcoes;
    opcoes.push_back("Instrucoes de uso do sistema");
    opcoes.push_back("Tela de creditos");
    opcoes.push_back("Voltar para o Menu Principal");
    
    int escolha = 0;
    do{  
        escolha = exibirMenu(opcoes, "Menu Ajuda");      
        switch (escolha){
        case 1: ajuda.ajudaPrograma(); break;
        case 2: ajuda.creditos(); break;
        case 0: cout << "Saindo do sistema..." << endl; break;
        default: cout << "Opcao invalida" << endl; break;
        }
    
    } while(escolha != 0);
}

/*Apresenta o menu principal e chama os outros menus de acordo 
com a escolha do usuário*/
void Controller::executar(){
    vector<string> opcoes;
    opcoes.push_back("Carteira");
    opcoes.push_back("Movimentacao");
    opcoes.push_back("Relatorios");
    opcoes.push_back("Ajuda");
    opcoes.push_back("Sair");

    int escolha = 0;
    do{  
        escolha = exibirMenu(opcoes, "Menu Principal");  
        switch (escolha){
        case 1: menuCarteira(); break;
        case 2: menuMovimentacao(); break;
        case 3: menuRelatorio(); break;
        case 4: menuAjuda(); break;
        case 0: cout << "Saindo do sistema..." << endl; break;
        default: cout << "Opcao invalida"; break;
        } 
    } while(escolha != 0); 

}