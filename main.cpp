#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include "times.cpp"
#include "generateCases.cpp"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtWidgets/QApplication>
#include <QtCharts/QValueAxis>
#include <QtWidgets/QMainWindow>


QT_CHARTS_USE_NAMESPACE

void guardarResultados(const std::string& algoritmo, const std::string& caso, double tiempo, int N) {
    std::ofstream file("Resultados.txt", std::ios::app); 
    file << algoritmo << " " << caso << " N=" << N << " Tiempo=" << tiempo << "s\n";
    file.close();
}

void cargarDatosDesdeArchivo(QLineSeries* bestSeries, QLineSeries* averageSeries, QLineSeries* worstSeries, const std::string& algoritmo) {
    std::ifstream file("Resultados.txt");
    std::string line, tempAlgoritmo, caso, tempN, tempTiempo;
    int N;
    double tiempo;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        ss >> tempAlgoritmo >> caso >> tempN >> tempTiempo;
        N = std::stoi(tempN.substr(2));  
        tiempo = std::stod(tempTiempo.substr(7)); 

        if (tempAlgoritmo == algoritmo) {
            if (caso == "Mejor") {
                bestSeries->append(N, tiempo);  
            } else if (caso == "Promedio") {
                averageSeries->append(N, tiempo);  
            } else if (caso == "Peor") {
                worstSeries->append(N, tiempo);  
            }
        }
    }
}

void createChart(QLineSeries* bestSeries, QLineSeries* averageSeries, QLineSeries* worstSeries, const QString& title) {
    QChart* chart = new QChart();
    chart->legend()->show();
    chart->addSeries(bestSeries);
    chart->addSeries(averageSeries);
    chart->addSeries(worstSeries);

    QValueAxis* axisX = new QValueAxis;
    axisX->setTitleText("Tamaño de N");
    axisX->setLabelFormat("%d");
    axisX->setTickCount(5);  
    axisX->setRange(1000, 35000);  

    QValueAxis* axisY = new QValueAxis;
    axisY->setTitleText("Tiempo (segundos)");
    axisY->setLabelFormat("%.6f");
    axisY->setRange(0, 5); 

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    bestSeries->attachAxis(axisX);
    bestSeries->attachAxis(axisY);
    averageSeries->attachAxis(axisX);
    averageSeries->attachAxis(axisY);
    worstSeries->attachAxis(axisX);
    worstSeries->attachAxis(axisY);

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(800, 600);
    window.setWindowTitle(title);
    window.show();

    QApplication::exec();
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    std::ofstream("Resultados.txt", std::ios::trunc).close();

    const int sizes[] = {1000, 10000, 15000, 25000, 35000};
    const int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numSizes; ++i) {
        int N = sizes[i];
        
        std::vector<int> arr(N);
        generateBestCase(arr.data(), N);
        auto start = std::chrono::high_resolution_clock::now();  
        TiempoBubbleSort(arr.data(), N);  
        auto end = std::chrono::high_resolution_clock::now();  
        double tiempoBubbleBest = std::chrono::duration<double>(end - start).count(); 
        guardarResultados("BubbleSort", "Mejor", tiempoBubbleBest, N);

        generateAverageCase(arr.data(), N);
        start = std::chrono::high_resolution_clock::now();
        TiempoBubbleSort(arr.data(), N);
        end = std::chrono::high_resolution_clock::now();
        double tiempoBubbleAverage = std::chrono::duration<double>(end - start).count();
        guardarResultados("BubbleSort", "Promedio", tiempoBubbleAverage, N);

        generateWorstCase(arr.data(), N);
        start = std::chrono::high_resolution_clock::now();
        TiempoBubbleSort(arr.data(), N);
        end = std::chrono::high_resolution_clock::now();
        double tiempoBubbleWorst = std::chrono::duration<double>(end - start).count();
        guardarResultados("BubbleSort", "Peor", tiempoBubbleWorst, N);

        generateBestCase(arr.data(), N);
        start = std::chrono::high_resolution_clock::now();
        TiempoSelectionSort(arr.data(), N);
        end = std::chrono::high_resolution_clock::now();
        double tiempoSelectionBest = std::chrono::duration<double>(end - start).count();
        guardarResultados("SelectionSort", "Mejor", tiempoSelectionBest, N);

        generateAverageCase(arr.data(), N);
        start = std::chrono::high_resolution_clock::now();
        TiempoSelectionSort(arr.data(), N);
        end = std::chrono::high_resolution_clock::now();
        double tiempoSelectionAverage = std::chrono::duration<double>(end - start).count();
        guardarResultados("SelectionSort", "Promedio", tiempoSelectionAverage, N);

        generateWorstCase(arr.data(), N);
        start = std::chrono::high_resolution_clock::now();
        TiempoSelectionSort(arr.data(), N);
        end = std::chrono::high_resolution_clock::now();
        double tiempoSelectionWorst = std::chrono::duration<double>(end - start).count();
        guardarResultados("SelectionSort", "Peor", tiempoSelectionWorst, N);

        generateBestCase(arr.data(), N);
        start = std::chrono::high_resolution_clock::now();
        TiempoMergeSort(arr.data(), 0, N - 1);
        end = std::chrono::high_resolution_clock::now();
        double tiempoMergeBest = std::chrono::duration<double>(end - start).count();
        guardarResultados("MergeSort", "Mejor", tiempoMergeBest, N);

        generateAverageCase(arr.data(), N);
        start = std::chrono::high_resolution_clock::now();
        TiempoMergeSort(arr.data(), 0, N - 1);
        end = std::chrono::high_resolution_clock::now();
        double tiempoMergeAverage = std::chrono::duration<double>(end - start).count();
        guardarResultados("MergeSort", "Promedio", tiempoMergeAverage, N);

        generateWorstCase(arr.data(), N);
        start = std::chrono::high_resolution_clock::now();
        TiempoMergeSort(arr.data(), 0, N - 1);
        end = std::chrono::high_resolution_clock::now();
        double tiempoMergeWorst = std::chrono::duration<double>(end - start).count();
        guardarResultados("MergeSort", "Peor", tiempoMergeWorst, N);
    }

    QLineSeries* bubbleSortBest = new QLineSeries();
    bubbleSortBest->setName("Mejor Caso");
    QLineSeries* bubbleSortAverage = new QLineSeries();
    bubbleSortAverage->setName("Caso Promedio");
    QLineSeries* bubbleSortWorst = new QLineSeries();
    bubbleSortWorst->setName("Peor Caso");

    QLineSeries* selectionSortBest = new QLineSeries();
    selectionSortBest->setName("Mejor Caso");
    QLineSeries* selectionSortAverage = new QLineSeries();
    selectionSortAverage->setName("Caso Promedio");
    QLineSeries* selectionSortWorst = new QLineSeries();
    selectionSortWorst->setName("Peor Caso");

    QLineSeries* mergeSortBest = new QLineSeries();
    mergeSortBest->setName("Mejor Caso");
    QLineSeries* mergeSortAverage = new QLineSeries();
    mergeSortAverage->setName("Caso Promedio");
    QLineSeries* mergeSortWorst = new QLineSeries();
    mergeSortWorst->setName("Peor Caso");

    cargarDatosDesdeArchivo(bubbleSortBest, bubbleSortAverage, bubbleSortWorst, "BubbleSort");
    cargarDatosDesdeArchivo(selectionSortBest, selectionSortAverage, selectionSortWorst, "SelectionSort");
    cargarDatosDesdeArchivo(mergeSortBest, mergeSortAverage, mergeSortWorst, "MergeSort");

    createChart(bubbleSortBest, bubbleSortAverage, bubbleSortWorst, "BubbleSort - Todos los Casos");
    createChart(selectionSortBest, selectionSortAverage, selectionSortWorst, "SelectionSort - Todos los Casos");
    createChart(mergeSortBest, mergeSortAverage, mergeSortWorst, "MergeSort - Todos los Casos");

    return 0;
}
