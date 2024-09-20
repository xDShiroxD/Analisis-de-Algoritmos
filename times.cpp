#include <chrono>
#include <iostream>
#include "ordenamiento.cpp"

float TiempoBubbleSort(int arr[], int n) {
    auto tiempo1 = std::chrono::high_resolution_clock::now();
    bubbleSort1(arr, n);
    auto tiempo2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = tiempo2 - tiempo1;
    return elapsed.count();
}

float TiempoSelectionSort(int arr[], int n) {
    auto tiempo1 = std::chrono::high_resolution_clock::now();
    selectionSort1(arr, n);
    auto tiempo2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = tiempo2 - tiempo1;
    return elapsed.count();
}

float TiempoMergeSort(int arr[], int left, int right) {
    auto tiempo1 = std::chrono::high_resolution_clock::now();
    mergeSort1(arr, left, right);
    auto tiempo2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = tiempo2 - tiempo1;
    return elapsed.count();
}
