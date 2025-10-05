#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>

using namespace std;

//Ligando os algoritmos de ordenação
#include "Metrics.h"
#include "Bubble_sort.h"
#include "Insertion_sort.h"
#include "Selection_sort.h"
#include "Merge_sort.h"
#include "Quick_sort.h"

void GerarAleatorio(int* vetor, int n){
    for(int i = 0; i< n; i++){
        vetor[i] = rand() % 10000;
    }
}

void GerarQuaseOrdenado(int* vetor, int n){
    for(int i = 0; i < n; i++){
        vetor[i] = i;
    }
    for (int i = 0; i < n / 10; i++) {
        int idx = rand() % (n - 1);
        swap(vetor[idx], vetor[idx + 1]);
    }

}

void GerarInversamenteOrdenado(int* vetor, int n){
    for(int i = 0; i < n; i++){
        vetor[i] = n - 1 - i;  
    }
}

double MedirTempo(void (*sortFunc)(int*, int, Metrics&), int* vetor, int n, Metrics& m) {
    clock_t inicio = clock();
    sortFunc(vetor, n, m);
    clock_t fim = clock();
    return double(fim - inicio) / CLOCKS_PER_SEC;
}

void TestarAlgoritmo(void (*sortFunc)(int*, int, Metrics&), string nome, int* original, int n) {
    int* copia = new int[n];
    copy(original, original + n, copia);

    Metrics m;
    double Tempo = MedirTempo(sortFunc, copia, n, m);

    cout << nome << " | Tamanho: " << n 
         << " | Tempo: " << std::scientific << std::setprecision(1) << Tempo << "s"
         << " | Comparacoes: " << m.comparacoes
         << " | Trocas: " << m.trocas << endl;

    delete[] copia;
}

int main(){
    srand(time(NULL));
    const int Tamanhos[] = {500, 5000, 10000};
    const int NumeroTamanhos = 3;

 for (int t = 0; t < NumeroTamanhos; t++) {
        int n = Tamanhos[t];
        int* vetor = new int[n];

        cout << "\n===== TAMANHO: " << n << " =====\n";

        cout << "\nTipo: Aleatorio\n";
        GerarAleatorio(vetor, n);
        TestarAlgoritmo(BubbleSort, "Bubble Sort", vetor, n);
        TestarAlgoritmo(InsertionSort, "Insertion Sort", vetor, n);
        TestarAlgoritmo(SelectionSort, "Selection Sort", vetor, n);
        TestarAlgoritmo(MergeSort, "Merge Sort", vetor, n);
        TestarAlgoritmo(QuickSort, "Quick Sort", vetor, n);

        cout << "\nTipo: Quase Ordenado\n";
        GerarQuaseOrdenado(vetor, n);
        TestarAlgoritmo(BubbleSort, "Bubble Sort", vetor, n);
        TestarAlgoritmo(InsertionSort, "Insertion Sort", vetor, n);
        TestarAlgoritmo(SelectionSort, "Selection Sort", vetor, n);
        TestarAlgoritmo(MergeSort, "Merge Sort", vetor, n);
        TestarAlgoritmo(QuickSort, "Quick Sort", vetor, n);

        cout << "\nTipo: Inversamente Ordenado\n";
        GerarInversamenteOrdenado(vetor, n);
        TestarAlgoritmo(BubbleSort, "Bubble Sort", vetor, n);
        TestarAlgoritmo(InsertionSort, "Insertion Sort", vetor, n);
        TestarAlgoritmo(SelectionSort, "Selection Sort", vetor, n);
        TestarAlgoritmo(MergeSort, "Merge Sort", vetor, n);
        TestarAlgoritmo(QuickSort, "Quick Sort", vetor, n);


        delete[] vetor;
    }
    
    return 0;
}