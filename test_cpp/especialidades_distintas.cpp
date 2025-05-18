#include <iostream>
#include <vector>
#include "../include_cpp/busca_seq_ordenada.hpp"


using namespace std;


int main () {

    std::vector<int> v = {4,2,1,4,2,1};

    cout << conta_especialidades_distintas(v) << " valor(es) unico(s)";

  
    return 0;
}