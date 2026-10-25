#ifndef NODOVIAJE_H
#define NODOVIAJE_H

#include "TDA/Viaje/Viaje.h"

class NodoViaje {
private:
    Viaje* viaje;
    NodoViaje* siguiente;

public:
    NodoViaje(Viaje* viaje);

    Viaje* getViaje();
    NodoViaje* getSiguiente();
    void setSiguiente(NodoViaje* siguiente);
};

#endif