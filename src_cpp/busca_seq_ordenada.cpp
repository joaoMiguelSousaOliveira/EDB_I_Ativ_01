#include <vector>
#include <algorithm>


int busca_seq_ordenada(std::vector<int>& vetor, int alvo) {
    int tamanho = static_cast<int>(vetor.size());

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == alvo) return i;
    }
    
    return -1;
}

int conta_especialidades_distintas(std::vector<int>& arr) {
    int size = static_cast<int>(arr.size());
    std::sort(arr.begin(), arr.end());

    int contador = 0;

    for (int j = 0; j < size; j++) {

        if (arr[busca_seq_ordenada(arr, arr[j])] == arr[busca_seq_ordenada(arr, arr[j+1])]) contador += 1;
        
    }
    return size - contador;
}
