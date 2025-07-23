#include "oraculo.hpp"
#include <random>

/* Construtor: inicializa o motor de geração e a distribuição
'std::random_device{}()' fornece uma semente inicial imprevisível para o gerador
'dist' define o intervalo e a distribuição uniforme dos valores gerados*/
Random::Random(double min_val, double max_val)
    : gen(std::random_device{}()), dist(min_val, max_val) {}

/* Método para gerar um número aleatório dentro do intervalo definido
utiliza o gerador e a distribuição para retornar um valor double aleatório*/
double Random::gerarNumero() {
    return dist(gen);
}