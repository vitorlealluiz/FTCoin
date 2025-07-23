#ifndef ORACULO_HPP
#define ORACULO_HPP

#include <random>

class Random {
private:
    std::mt19937 gen; //Gerador de números aleatórios
    std::uniform_real_distribution<double> dist; //Distribuição uniforme para números reais

public:
    // Construtor com valores padrão 
    Random(double min_val = 10.0f, double max_val = 150.0f);
    
    // Método para gerar número aleatório
    double gerarNumero();
};

#endif // RANDOM_HPP