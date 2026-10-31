#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

// Algoritmo QuickSort
void quickSort(vector<int>& A, int inicio, int fin) {
    if (inicio >= fin) {
        return;
    }

    int pivote = A[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        if (A[j] <= pivote) {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[fin]);

    int posicionPivote = i + 1;

    quickSort(A, inicio, posicionPivote - 1);
    quickSort(A, posicionPivote + 1, fin);
}

// Generar datos aleatorios uniformes
void generarAleatorios(vector<int>& A) {
    mt19937 generador(4321); // Semilla fija
    uniform_int_distribution<int> distribucion(1, 1000);

    for (int& x : A) {
        x = distribucion(generador);
    }
}

// Mostrar los primeros elementos
void mostrarDatos(const vector<int>& A) {
    int limite = min(20, (int)A.size());

    for (int i = 0; i < limite; i++) {
        cout << A[i] << " ";
    }

    if (A.size() > 20) {
        cout << "...";
    }

    cout << endl;
}

// Medir el tiempo de ejecucion
void probarQuickSort(vector<int> A, string patron) {
    cout << "\nPatron: " << patron << endl;

    cout << "Antes de ordenar: ";
    mostrarDatos(A);

    auto inicio = high_resolution_clock::now();

    quickSort(A, 0, (int)A.size() - 1);

    auto fin = high_resolution_clock::now();

    auto tiempo = duration_cast<nanoseconds>(
        fin - inicio
    ).count();

    cout << "Despues de ordenar: ";
    mostrarDatos(A);

    cout << "Tiempo de ejecucion: "
         << tiempo << " nanosegundos" << endl;

    cout << "Orden correcto: "
         << (is_sorted(A.begin(), A.end()) ? "Si" : "No")
         << endl;
}

int main() {
    const int N = 1000;

    vector<int> aleatorio(N);
    vector<int> ascendente(N);
    vector<int> descendente(N);

    // 1. Generar instancia aleatoria
    generarAleatorios(aleatorio);

    // 2. Generar instancia ascendente
    for (int i = 0; i < N; i++) {
        ascendente[i] = i + 1;
    }

    // 3. Generar instancia descendente
    for (int i = 0; i < N; i++) {
        descendente[i] = N - i;
    }

    cout << "====================================\n";
    cout << "   PRUEBAS DEL ALGORITMO QUICKSORT\n";
    cout << "====================================\n";
    cout << "Cantidad de datos: " << N << endl;
    cout << "Rango aleatorio: 1 a 1000" << endl;
    cout << "Semilla fija: 1234" << endl;

    probarQuickSort(aleatorio, "Aleatorio uniforme");
    probarQuickSort(ascendente, "Ordenado ascendente");
    probarQuickSort(descendente, "Ordenado descendente");

    return 0;
}

