#include "Merge_sort.h"
#include <algorithm>

void merge(int* v, int l, int m, int r, Metrics& mts) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++){
        L[i] = v[l + i];
    }
    for (int i = 0; i < n2; i++){ 
        R[i] = v[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        mts.comparacoes++;
        if (L[i] <= R[j]) {
            v[k++] = L[i++];
        } else {
            v[k++] = R[j++];
            mts.trocas++;
        }
    }

    while (i < n1){
        v[k++] = L[i++];
    }
    while (j < n2){
        v[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void MergeSortAux(int* v, int l, int r, Metrics& m) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        MergeSortAux(v, l, mid, m);
        MergeSortAux(v, mid + 1, r, m);
        merge(v, l, mid, r, m);
    }
}

void MergeSort(int* v, int n, Metrics& m) {
    MergeSortAux(v, 0, n - 1, m);
}