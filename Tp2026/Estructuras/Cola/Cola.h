#ifndef COLA_H
#define COLA_H

#include "NodoCola.h"

class Cola {
private:
    NodoCola* frente;
    NodoCola* final;
    int cantidad;

public:
    Cola();
    ~Cola();

    void encolar(int dato);
    int desencolar();
    int verFrente();
    bool estaVacia();
    int getCantidad();
};

#endif