#ifndef ORDENADOR_H
#define ORDENADOR_H

#include "TDA/Estacion/Estacion.h"

class Ordenador {
private:
    int valor(Estacion* e, bool porCapacidad);

public:
    void ordenarEstaciones(Estacion** v, int n, bool porCapacidad);
};

#endif