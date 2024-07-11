#include <iostream>

#include "heap.hpp"



int main(){
    int tamanhoDesejado;
    std::cin >> tamanhoDesejado;

    Heap heap(tamanhoDesejado);

    int valoresDesejados[tamanhoDesejado];

    for (int i = 0; i < tamanhoDesejado; i++){
        std::cin >> valoresDesejados[i];
    }

    for(int i = 0; i < tamanhoDesejado; i++){
        heap.Inserir(valoresDesejados[i]);
    }

    for(int i = 0; i < tamanhoDesejado; i++){
        std::cout << heap.Remover() << " ";
    }

    return 0;
}