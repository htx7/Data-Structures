#include "../include/heap.hpp"

Heap::Heap(int maxsize){
    tamanho = 0;
    data = new int[maxsize];
}

Heap::~Heap(){
    delete[] data;
}

int Heap::GetAncestral(int i){
    return ((i - 1) / 2);
}

int Heap::GetSucessorDir(int i){
    return (2 * i + 1);
}

int Heap::GetSucessorEsq(int i){
    return (2 * i + 2);
}

void Heap::Inserir(int x){
    int posicaoAtual, posicaoAncestral;
    data[tamanho] = x;
    posicaoAtual = tamanho;
    posicaoAncestral = (posicaoAtual - 1) / 2;

    while(data[posicaoAtual] > data[posicaoAncestral]){
        int aux = data[posicaoAtual];
        data[posicaoAtual] = data[posicaoAncestral];
        data[posicaoAncestral] = aux;

        posicaoAtual = posicaoAncestral;
        posicaoAncestral = (posicaoAtual - 1) / 2;
    }

    tamanho += 1;
}

int Heap::Remover(){
    int valorRemovido = data[0];

    return valorRemovido;
}