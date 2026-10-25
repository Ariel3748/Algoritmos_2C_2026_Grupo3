#ifndef LISTAVIAJES_H
#define LISTAVIAJES_H

#include "NodoViaje.h"

class ListaViajes {
private:
    NodoViaje* primero;
    int cantidad;

public:
    ListaViajes();
    ~ListaViajes();

    void agregar(Viaje* viaje);
    NodoViaje* getPrimero();
    int getCantidad();
    bool estaVacia();
};

#endif