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
    mt19937 generador(151); // Semilla fija
    uniform_int_distribution<int> distribucion(1, 10000);

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
        cout << "...";}

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
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

// Algoritmo Shell Sort
void shellSort(vector<int>& datos) {
    int n = datos.size();

    // Secuencia de incrementos: n/2, n/4, ..., 1
    for (int salto = n / 2; salto > 0; salto /= 2) {

        for (int i = salto; i < n; i++) {
            int temporal = datos[i];
            int j = i;

            while (j >= salto &&
                   datos[j - salto] > temporal) {
                datos[j] = datos[j - salto];
                j -= salto;
            }

            datos[j] = temporal;
        }
    }
}

// Mostrar los primeros elementos del vector
void mostrarDatos(const vector<int>& datos) {
    int limite = min(1000, (int)datos.size());

    for (int i = 0; i < limite; i++) {
        cout << datos[i] << " ";
    }
    cout << endl;
}

// Generar datos aleatorios con semilla fija
vector<int> generarAleatorios(int n) {
    vector<int> datos(n);

    mt19937 generador(12);
    uniform_int_distribution<int> distribucion(1, 1000);

    for (int i = 0; i < n; i++) {
        datos[i] = distribucion(generador);
    }

    return datos;
}

// Generar datos ordenados ascendentemente
vector<int> generarAscendentes(int n) {
    vector<int> datos(n);

    for (int i = 0; i < n; i++) {
        datos[i] = i + 1;
    }

    return datos;
}

// Generar datos ordenados descendentemente
vector<int> generarDescendentes(int n) {
    vector<int> datos(n);

    for (int i = 0; i < n; i++) {
        datos[i] = n - i;
    }

    return datos;
}

// Ejecutar y medir Shell Sort
void probarShellSort(vector<int> datos, string patron) {
    cout << "\nPatron: " << patron << endl;

    cout << "Primeros datos antes de ordenar: ";
    mostrarDatos(datos);

    auto inicio = high_resolution_clock::now();

    shellSort(datos);

    auto fin = high_resolution_clock::now();

    double tiempo =
        duration<double, milli>(fin - inicio).count();

    cout << "Primeros datos despues de ordenar: ";
    mostrarDatos(datos);

    cout << fixed << setprecision(6);
    cout << "Tiempo de ejecucion: "
         << tiempo << " milisegundos" << endl;
}

int main() {
    const int N = 1000;

    cout << "====================================\n";
    cout << "     ALGORITMO SHELL SORT\n";
    cout << "====================================\n";
    cout << "Cantidad de datos: " << N << endl;
    cout << "Rango aleatorio: 1 a 10000\n";
    cout << "Semilla fija: 1234\n";

    // Instancia 1: aleatoria
    vector<int> aleatorios = generarAleatorios(N);
    probarShellSort(aleatorios, "Aleatorio uniforme");

    // Instancia 2: ascendente
    vector<int> ascendentes = generarAscendentes(N);
    probarShellSort(ascendentes, "Orden ascendente");

    // Instancia 3: descendente
    vector<int> descendentes = generarDescendentes(N);
    probarShellSort(descendentes, "Orden descendente");

    cout << "\n====================================\n";
    cout << "Proceso terminado.\n";

    return 0;
}
