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
    data[tamanho] = x;
    tamanho += 1;

    int posicaoAtual = tamanho;
    int posicaoAncestral = GetAncestral(posicaoAtual);

    while(data[posicaoAncestral] > data[posicaoAtual]){
        int aux = data[posicaoAtual];
        data[posicaoAtual] = data[posicaoAncestral];
        data[posicaoAncestral] = aux;

        posicaoAtual = posicaoAncestral;
        posicaoAncestral = GetAncestral(posicaoAtual);
    }

   
}
/*
int Heap::Remover(int x){
    return data[x];
}
*/

int Heap::Remover(){
    int raiz = data[0];
    data[0] = data[tamanho - 1];
    tamanho--;
    int i = 0;

    while(i < tamanho - 1){
        int menor = i;
        int iEsquerdo = GetSucessorEsq(i);
        int iDireita = GetSucessorDir(i);

        if (iEsquerdo < tamanho && data[iEsquerdo] < data[menor]){
            menor = iEsquerdo;
        }
        if (iDireita < tamanho && data[iDireita] < data[menor]){
            menor = iDireita;
        }

        if (menor != i){
            int aux = data[i];
            data[i] = data[menor];
            data[menor] = aux;
            i = menor;
        }
        else {
            break;
        }

    }
    return raiz;
}

