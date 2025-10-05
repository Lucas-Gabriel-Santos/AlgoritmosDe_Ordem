#include "Selection_sort.h"
#include <algorithm>

void SelectionSort(int* vetor, int n, Metrics& m){
    for(int i = 0; i < n; i++){
        int min_i = i;
        for(int j = i + 1; j < n; j++){
            m.comparacoes++;
            if(vetor[j] < vetor[min_i]){
                min_i = j;
            }
        }
        if(min_i != i){
            std::swap(vetor[i], vetor[min_i]);
            m.trocas++;
        }
    }
}