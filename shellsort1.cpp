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

