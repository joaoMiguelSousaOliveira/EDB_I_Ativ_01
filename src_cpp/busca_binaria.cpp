
bool isBadVersion(int version, int mal) {
    return version >= mal;
}

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
