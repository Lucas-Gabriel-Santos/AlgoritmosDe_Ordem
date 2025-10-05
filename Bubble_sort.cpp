#include "Bubble_sort.h"
#include <algorithm>

void BubbleSort(int* vetor, int n, Metrics& m){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            m.comparacoes++;
            if(vetor[j] > vetor[j + 1]){
                std::swap(vetor[j], vetor[j + 1]);
                m.trocas++;
            }
        }
    }
}