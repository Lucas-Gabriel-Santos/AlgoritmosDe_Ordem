#include "Quick_sort.h"
#include <algorithm>

int partition(int* vetor, int low, int high, Metrics& m) {
    int pivo = vetor[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        m.comparacoes++;
        if (vetor[j] <= pivo) {
            i++;
            std::swap(vetor[i], vetor[j]);
            m.trocas++;
        }
    }
    std::swap(vetor[i + 1], vetor[high]);
    m.trocas++;
    return i + 1;
}

void quickSortAux(int* vetor, int low, int high, Metrics& m) {
    if (low < high) {
        int pi = partition(vetor, low, high, m);
        quickSortAux(vetor, low, pi - 1, m);
        quickSortAux(vetor, pi + 1, high, m);
    }
}

void QuickSort(int* vetor, int n, Metrics& m) {
    quickSortAux(vetor, 0, n - 1, m);
}