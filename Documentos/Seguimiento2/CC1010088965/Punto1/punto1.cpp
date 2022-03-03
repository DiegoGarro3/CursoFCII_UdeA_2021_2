#include <iostream>

float calc_prom(int [], int);
float varianza(int [], int);

// using namespace std;

int main() {
    const int numVals = 14;
    int valores_prueba[numVals] = {89, 95, 72, 83, 99, 54, 86, 75, 92, 73, 79, 75, 82, 73};
    // std::cout << "Se tienen estos valores: " << valores_prueba << std::endl;
    std::cout << "Se calcula el promedio: " << calc_prom(valores_prueba, numVals) << std::endl;
    std::cout << "Se calcula la varianza: " << varianza(valores_prueba, numVals) << std::endl;
}

float calc_prom(int vals[], int numVals) {
    float prom = 0;
    for (size_t i = 0; i < numVals; i++) {
        prom += vals[i];
    }
    prom /= numVals;

    return prom;
}

float varianza(int vals[], int numVals) {
    float varian = 0;
    float promedio = calc_prom(vals, numVals);
    for (size_t i = 0; i < numVals; i++) {
        varian += (vals[i] - promedio)*(vals[i] - promedio);
    }
    varian /= numVals;

    return varian;
}