#include <stdlib.h>
#include <time.h>

void generateBestCase(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = i; // Arreglo ya ordenado
    }
}

void generateAverageCase(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100; // Números aleatorios
    }
}

void generateWorstCase(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = n - i; // Arreglo inversamente ordenado
    }
}
