#ifndef NODOHASH_H
#define NODOHASH_H

#include "TDA/Estacion/Estacion.h"

class NodoHash {
private:
    Estacion* estacion;
    NodoHash* siguiente;

public:
    NodoHash(Estacion* estacion);

    Estacion* getEstacion();
    NodoHash* getSiguiente();
    void setSiguiente(NodoHash* siguiente);
};

#endif