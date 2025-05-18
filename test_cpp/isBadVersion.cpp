#include <iostream>
#include "../include_cpp/busca_binaria.hpp"


using namespace std;

int main () {
    int n = 5;
    int bad = 4;
    
    cout << "A primeira versao defeituosa e " << busca_binaria(n, bad);
    
    return 0;
}