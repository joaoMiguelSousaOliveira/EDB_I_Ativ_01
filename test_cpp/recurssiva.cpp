#include <iostream>
#include <string>
#include "../include_cpp/recursao.hpp"


using namespace std;

int main () {

    std::string word = "banana";
    char caracter = 'a';

    cout << "A letra '"<< caracter << "' foi repetida " << recursao(word, caracter, 0, 0) << " vezes";

  
    return 0;
}