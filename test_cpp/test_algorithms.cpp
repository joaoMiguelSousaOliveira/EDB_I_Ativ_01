#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "busca_seq_ordenada.hpp"
#include "busca_binaria.hpp"
#include "recursao.hpp"
#include "especialidades_distintas.cpp"
#include "isBadVersion.cpp"
#include "recurssiva.cpp"

#define RUN_TEST(name, expr, expected)                                 \
    do {                                                               \
        int result = (expr);                                           \
        std::cout << std::left << std::setw(25) << name                \
                  << ": " << ((result == (expected)) ? "OK" : "FAIL")  \
                  << std::endl;                                        \
    } while(0)

int main() {
    //Vetor desordenado <POPULAR>
    std::vector<int> arr1 = {4,2,1,4,2,1};
    //Tamanho do vetor <ALTERAR>
    int n1 = 5;
    //Vetor ordenado <POPULAR>
    std::vector<int> arr2 = {};
    //Tamanho do vetor <ALTERAR>
    int n2 = 6;
    //String
    std::string palavra = "banana";
    //Caracter
    char letra = 'a';

    //Eexemplo de chamada da macro RUN_TEST
    //RUN_TEST("Titulo do teste", nome_da_funcao(entradas das funcao), resposta_esperada);
    RUN_TEST("Busca ordenada", conta_especialidades_distintas(arr1), 3);
    RUN_TEST("Busca binaria", busca_binaria(n1, 4), 4);
    RUN_TEST("Recursao", recursao(palavra, letra, 0, 0), 3);

    return 0;
}

