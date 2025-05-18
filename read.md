
# Questão 5.1: Primeira versão defeituosa

### Arquivo: `busca_binaria.cpp`

#### Função: `isBadVersion`

Esta função verifica se uma determinada `version` é defeituosa.

**Parâmetros:**

* `version`: Um inteiro representando o número da versão a ser verificada.
* `mal`: Um inteiro representando a primeira versão defeituosa conhecida.

**Retorno:**

* `bool`: Retorna `1` se `version` for maior ou igual a `mal` (indicando que é uma versão defeituosa - toda versão posterior à `mal` também é defeituosa), e `0` caso contrário.


#### Função: `busca_binaria`

Esta função implementa o algoritmo de busca binária para encontrar a primeira versão defeituosa.

**Parâmetros:**

* `n`: Um inteiro representando o número total de versões.
* `mal`: Um inteiro representando a primeira versão defeituosa.

**Lógica:**

* **1.**  Inicializa dois inteiros: `baixo` (representando a primeira versão, inicialmente 1) e `alto` (representando a última versão, inicialmente `n`).

* **2.**  Realiza uma verificação inicial: se `baixo` for maior que `alto`, retorna -1, indicando uma situação inesperada (tratamento de erro).

* **3.**  Entra em um loop `while` que continua enquanto `baixo` for menor que `alto`.
* **4.**  Dentro do loop, calcula o índice do meio (`meio`) como a média de `baixo` e `alto`.

* **5.**  Chama a função `isBadVersion` com `meio` e `mal`.
* * Se `isBadVersion` retornar `1`, significa que `meio` é uma versão defeituosa. Portanto, a primeira versão defeituosa deve ser `meio` ou algum antecessor, então `alto` é atualizado para `meio` -> Buscaremos `mal` na parte "*esquerda do array*".<br>
* * Se `isBadVersion` retornar `0`, significa que `meio` é uma versão boa. Portanto, a primeira versão defeituosa deve estar depois de `meio`, então `baixo` é atualizado para `meio + 1`. -> Buscaremos na parte "*direita do array*".

* **6.**  Quando o loop termina (`baixo` não é mais menor que `alto`), `baixo` conterá o índice da primeira versão defeituosa, que é então retornado.
```cpp
int busca_binaria(int n, int mal) {
 
    int baixo = 1;
    
    int alto = n; 
    
    if (baixo > alto) return -1;

    while (baixo < alto) { 
        
        int meio = (alto + baixo) / 2;
       
        if (isBadVersion(meio, mal) == 1) alto = meio;
       
        else baixo = meio + 1;
    }
    
    return baixo;
}
```
---

### Arquivo: `busca_binaria.hpp` 

Este arquivo de cabeçalho armazena a função `busca_binaria`.

**Observação:** Os parâmetros foram renomeados para `numero` e `alvo` no arquivo `.hpp`, correspondendo ao número total de versões e à primeira versão defeituosa, respectivamente.

---

### Arquivo: `isBadVersion.cpp`

Este arquivo demonstra o uso da função `busca_binaria`.

```cpp
#include "busca_binaria.hpp" // Inclui a declaração da função busca_binaria
#include <iostream>

int main() {
    int n = 5;       // Número total de versões
    int bad = 4;     // Primeira versão defeituosa
    
    cout << "A primeira versao defeituosa e " << busca_binaria(n, bad);
    
    return 0;
}
```
<br>

# Questão 5.2: Equipes iguais e diversas

### Arquivo: `busca_seq_ordenada.cpp`

**Função:** `busca_seq_ordenada`

**Descrição:** Esta função realiza uma busca sequencial em um vetor de inteiros.

**Parâmetros:**
* `vetor`: Um vetor de inteiros **não ordenado** representando as especialidades.
* `alvo`: Um inteiro representando a especialidade a ser buscada.

**Lógica:**
* **1.**  Obtém o tamanho do vetor `vetor` e armazena na variável `tamanho`.

* **2.**  Itera por cada elemento do `vetor` utilizando um loop `for`.

* **3.**  Para cada elemento, verifica se é igual ao valor de `alvo`.

* **4.**  Se uma correspondência for encontrada, a função retorna o **índice** desse elemento.

* **5.**  Se o loop completar sem encontrar o `alvo`, a função retorna **-1**.

```cpp
int busca_seq_ordenada(std::vector<int>& vetor, int alvo) {
    int tamanho = static_cast<int>(vetor.size());

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == alvo) return i;
    }
    
    return -1;
}
```

**Função:** `conta_especialidades_distintas`

**Descrição:** Esta função calcula o número de especialidades distintas em um vetor.

**Parâmetros:**
* `arr`: Um vetor de inteiros representando as especialidades **não ordenadas**.

**Lógica:**

* **1.**  Obtém o tamanho do vetor `arr` e armazena na variável `size`.

* **2.**  Ordena o vetor `arr` utilizando a função `sort` da biblioteca `<algorithm>`.

* **3.**  Inicializa uma variável `contador` com o valor 0. Esta variável irá rastrear as especialidades repetidas adjacentes após a ordenação.

* **4.**  Itera por todos os elementos do vetor `arr` utilizando um loop `for`.

* **5.**  Dentro do loop, verifica a seguinte condição para evitar estouro de índice: se o índice atual `i` for menor que o penúltimo índice do vetor (`size - 1`) e se o elemento em `arr[i]` for igual ao elemento em `arr[i + 1]`, incrementa o `contador`.

* **6.**  Após o loop, retorna a diferença entre o tamanho total do vetor (`size`) e o número de especialidades repetidas (`contador`). Isso resulta no número de especialidades distintas.

```cpp
int conta_especialidades_distintas(std::vector<int>& arr) {
    int size = static_cast<int>(arr.size());
    std::sort(arr.begin(), arr.end());

    int contador = 0;

    for (int j = 0; j < size; j++) {

        if (arr[busca_seq_ordenada(arr, arr[j])] == arr[busca_seq_ordenada(arr, arr[j+1])]) contador += 1;
        
    }
    return size - contador;
}
```
---
### Arquivo:  `busca_seq_ordenada.hpp`

**Descrição:** Este arquivo de cabeçalho armazena as funções `busca_seq_ordenada` e `conta_especialidades_distintas`.

**Observações:**
* O parâmetro `vetor` da função `busca_seq_ordenada` foi renomeado para `arr` no arquivo `.hpp`. O parâmetro `alvo` manteve o mesmo nome. `arr` representa o vetor de especialidades.
* A função `conta_especialidades_distintas` possui um parâmetro chamado `arr`, que indica o vetor de especialidades.

---

### Arquivo: `especialidades_distintas.cpp`

**Descrição:** Este arquivo demonstra a aplicação da função `conta_especialidades_distintas` em um array chamado `v`.

```cpp
#include <iostream>
#include <vector>
#include "../include_cpp/busca_seq_ordenada.hpp" // Inclui a declaração de conta_especialidades_distintas

using namespace std;

int main () {

    std::vector<int> v = {4,2,1,4,2,1}; // Vetor referente às especialidaddes

    cout << conta_especialidades_distintas(v) << " valor(es) unico(s)";
  
    return 0;
}
```
<br>

# Questão 5.3: Contagem Recursiva

### Arquivo: `recursao.cpp`

#### Função: `recursao`

**Descrição:** Esta função implementa uma abordagem recursiva para contar o número de ocorrências de um caractere específico em uma string.

**Parâmetros:**

* `palavra` (*string*): A string na qual a contagem será realizada.
* `letra` (*char*): O caractere cuja ocorrência será contada.
* `contador` (*int*): Um índice utilizado para percorrer os caracteres da string (`palavra`). Inicialmente deve ser 0.
* `repetidas` (*int*): Uma variável para armazenar o número de vezes que o caractere `letra` foi encontrado na string. Inicialmente deve ser 0.

**Lógica:**

**1.**  **Caso Base:** Se o valor de `contador` for igual ao tamanho da `palavra`, significa que todos os caracteres foram percorridos. Neste caso, a função retorna o valor acumulado em `repetidas`, encerrando a recursão.

**2.**  **Passo Recursivo:** Caso contrário (se `contador` for menor que o tamanho da `palavra`):

* Verifica se o caractere na posição `contador` da `palavra` (`palavra[contador]`) é igual ao caractere `letra`.

* Se houver uma correspondência, incrementa o valor de `repetidas` em 1.
* A função chama a si mesma (`recursao`), passando os seguintes argumentos:
    * A mesma `palavra`.
    * O mesmo caractere `letra`.
    * O valor de `contador` incrementado em 1 (`contador + 1`), para avançar para o próximo caractere.
    * O valor atual de `repetidas`.

```cpp
int recursao(const std::string &palavra, char letra, int contador = 0, int repetidas = 0) {

    if (palavra.size() == contador) return repetidas;

    else {
        if (palavra[contador] == letra) repetidas = repetidas + 1;
        return recursao(palavra, letra, contador + 1, repetidas);
    }

}
```
---
### Arquivo: `recursao.hpp`

**Descrição:** Este arquivo de cabeçalho declara a função `recursao`.

**Parâmetros Declarados:**

* `str` (*string*): A string a ser analisada.
* `alvo` (*char*): O caractere a ser buscado.
* `cont` (*int*): O contador para percorrer a string.
* `rep` (*int*): A variável para armazenar o número de ocorrências de `alvo`.

---
### Arquivo: `recursiva.cpp`

**Descrição:** Este arquivo demonstra a utilização da função `recursao`.

**Implementação:**

**1.**  Declara uma string chamada `word` e um caractere chamado `caracter`.

**2.**  Chama a função `recursao` passando `word`, `caracter`, 0 (valor inicial para o contador) e 0 (valor inicial para o número de repetições) como argumentos. O resultado da função (o número de ocorrências do caractere na string) será o valor retornado pela chamada.

```cpp
#include <iostream>             
#include <string>
#include "../include_cpp/recursao.hpp"  // Inclui a função recursao

using namespace std;

int main () {

    std::string word = "banana";  // Declara a palavra que iremos analisar
    char caracter = 'a';         // Caracter que buscaremos

    // Aplicamos a função
    cout << "A letra '"<< caracter << "' foi repetida " << recursao(word, caracter, 0, 0) << " vezes"; 

    return 0;
}
```