#include <string>

int recursao(const std::string &palavra, char letra, int contador = 0, int repetidas = 0) {
   
    if (palavra.size() == contador) return repetidas;

    else {
        if (palavra[contador] == letra) repetidas = repetidas + 1;
        return recursao(palavra, letra, contador + 1, repetidas);
    }

}
