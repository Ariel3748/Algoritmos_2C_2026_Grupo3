#include "Ordenador.h"

int Ordenador::valor(Estacion* e, bool porCapacidad) {
    if (porCapacidad) {
        return e->getCapacidadAnclajes();
    }
    return e->getBicisDisponibles();
}

void Ordenador::ordenarEstaciones(Estacion** v, int n, bool porCapacidad) {
    for (int i = 1; i < n; i++) {
        Estacion* actual = v[i];
        int j = i - 1;
        while (j >= 0 && valor(v[j], porCapacidad) > valor(actual, porCapacidad)) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = actual;
    }
}