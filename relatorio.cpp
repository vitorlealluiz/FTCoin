#include "relatorio.hpp"
#include "oraculo.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include "movimentacao.hpp"

using namespace std;

Random oraculo(1.0f, 100.0f); // usado apenas no status

Relatorio::Relatorio(CarteiraDAO& dao, Vetor& mdao)
    : carteiraDAO(dao), movimentacaoDAO(mdao) {
    idCarteira = 0;
    idMovimentacao = 0;
}

void Relatorio::listarCarteiraID() {
    const vector<Carteira>& todas = carteiraDAO.listarTodas();
    if (todas.empty()) {
        cout << "Nenhuma carteira cadastrada." << endl;
        return;
    }

    cout << "\n=== LISTA DE CARTEIRAS ===\n" << endl;
    for (const auto& c : todas) {
        cout << "ID: " << c.getidCarteira() << endl;
        cout << "TITULAR: " << c.getTitular() << endl;
        cout << "CORRETORA: " << c.getCorretora() << endl;
        cout << "------------------------\n" << endl;
    }
}

void Relatorio::listarCarteiraTitular() {
    const vector<Carteira>& todas = carteiraDAO.listarTodas();
    if (todas.empty()) {
        cout << "Nenhuma carteira cadastrada." << endl;
        return;
    }

    vector<Carteira> ordenadas = todas;
    sort(ordenadas.begin(), ordenadas.end(),
         [](const Carteira& a, const Carteira& b) {
             return a.getTitular() < b.getTitular();
         });

    cout << "\n=== CARTEIRAS POR ORDEM ALFABETICA ===\n" << endl;
    for (const auto& c : ordenadas) {
        cout << "TITULAR: " << c.getTitular() << endl;
        cout << "ID: " << c.getidCarteira() << endl;
        cout << "CORRETORA: " << c.getCorretora() << endl;
        cout << "------------------------\n" << endl;
    }
}

void Relatorio::exibirSaldo() {
    const vector<Carteira>& todas = carteiraDAO.listarTodas();
    if (todas.empty()) {
        cout << "Nenhuma carteira cadastrada." << endl;
        return;
    }

    int id = carteiraDAO.recuperarCarteira();
    if (id <= 0) {
        cout << "Carteira nao encontrada. Tente novamente." << endl;
        return;
    }

    vector<Movimentacao> listaMovs = movimentacaoDAO.listaMovimentacoes(id);
    if (listaMovs.empty()) {
        cout << "Carteira vazia." << endl;
        return;
    }

    double totalCompras = 0.0;
    double totalVendas = 0.0;

    cout << "\n=== SALDO DA CARTEIRA " << id << " ===\n" << endl;

    for (const auto& mov : listaMovs) {
        double preco = mov.getPrecoTransacao(); // preco salvo no momento
        double valorOperacao = mov.getQuant() * preco;

        if (tolower(mov.getChar()) == 'c') {
            totalCompras += valorOperacao;
            cout << "COMPRA | Quant: " << mov.getQuant()
                 << " | Preco: " << preco
                 << " | Total: " << valorOperacao << endl;
        } else if (tolower(mov.getChar()) == 'v') {
            totalVendas += valorOperacao;
            cout << "VENDA  | Quant: " << mov.getQuant()
                 << " | Preco: " << preco
                 << " | Total: " << valorOperacao << endl;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nTOTAL COMPRAS: " << totalCompras << endl;
    cout << "TOTAL VENDAS: " << totalVendas << endl;
    cout << "SALDO (Compras - Vendas): " << (totalCompras - totalVendas) << endl;
    cout << "------------------------\n" << endl;
}

void Relatorio::exibirMovimentacao() {
    const vector<Carteira>& todas = carteiraDAO.listarTodas();
    if (todas.empty()) {
        cout << "Nenhuma carteira cadastrada." << endl;
        return;
    }

    int id = carteiraDAO.recuperarCarteira();
    if (id <= 0) {
        cout << "Carteira nao encontrada. Tente novamente." << endl;
        return;
    }

    vector<Movimentacao> listaMovs = movimentacaoDAO.listaMovimentacoes(id);
    if (listaMovs.empty()) {
        cout << "Nenhuma movimentacao registrada." << endl;
        return;
    }

    cout << "\n=== MOVIMENTACOES DA CARTEIRA " << id << " ===\n" << endl;
    for (const auto& mov : listaMovs) {
        double preco = mov.getPrecoTransacao();
        cout << "ID Movimentacao: " << mov.getId() << endl;
        cout << "Data: " << mov.getData() << endl;
        cout << "Quantidade: " << mov.getQuant() << endl;
        cout << "Preco unitario: " << preco << endl;
        cout << "Tipo: " << (tolower(mov.getChar()) == 'c' ? "Compra" : "Venda") << endl;
        cout << "Valor total: " << (mov.getQuant() * preco) << endl;
        cout << "------------------------\n" << endl;
    }
}

void Relatorio::statusGanhaPerda() {
    const vector<Carteira>& todas = carteiraDAO.listarTodas();
    if (todas.empty()) {
        cout << "Nenhuma carteira cadastrada." << endl;
        return;
    }

    int id = carteiraDAO.recuperarCarteira();
    if (id <= 0) {
        cout << "Carteira nao encontrada." << endl;
        return;
    }

    vector<Movimentacao> listaMovs = movimentacaoDAO.listaMovimentacoes(id);
    if (listaMovs.empty()) {
        cout << "Nenhuma movimentacao registrada." << endl;
        return;
    }

    double valorAtualMoeda = oraculo.gerarNumero();
    double saldoMoedas = 0.0;
    double investimentoTotal = 0.0;
    double retornoVendas = 0.0;

    cout << "\n=== STATUS FINANCEIRO DA CARTEIRA " << id << " ===" << endl;
    cout << "Valor atual simulado da moeda: " << valorAtualMoeda << endl;
    cout << "------------------------------------------------\n";

    for (const auto& mov : listaMovs) {
        double preco = mov.getPrecoTransacao();
        double quantidade = mov.getQuant();

        if (tolower(mov.getChar()) == 'c') {
            saldoMoedas += quantidade;
            investimentoTotal += quantidade * preco;
            cout << "COMPRA | Quant: " << quantidade
                 << " | Preco historico: " << preco
                 << " | Total: " << (quantidade * preco) << endl;
        } else if (tolower(mov.getChar()) == 'v') {
            saldoMoedas -= quantidade;
            retornoVendas += quantidade * preco;
            cout << "VENDA  | Quant: " << quantidade
                 << " | Preco historico: " << preco
                 << " | Total: " << (quantidade * preco) << endl;
        }
    }

    double valorAtualCarteira = saldoMoedas * valorAtualMoeda;
    double resultadoLiquido = valorAtualCarteira + retornoVendas - investimentoTotal;

    cout << "\n=== RESULTADO ===" << endl;
    cout << fixed << setprecision(2);
    cout << "Saldo de moedas: " << saldoMoedas << endl;
    cout << "Total investido: " << investimentoTotal << endl;
    cout << "Total recebido: " << retornoVendas << endl;
    cout << "Valor atual das moedas: " << valorAtualCarteira << endl;

    if (resultadoLiquido >= 0) {
        cout << "LUCRO: " << resultadoLiquido << endl;
    } else {
        cout << "PREJUIZO: " << -resultadoLiquido << endl;
    }
    cout << "------------------------------------------------\n" << endl;
}
