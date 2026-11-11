#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <string>
#include "NodoHash.h"

class TablaHash {
private:
    NodoHash** tabla;     // arreglo dinámico de punteros al primer nodo de cada lista
    int tamanio;
    int cantidad;
    int colisiones;

    int hash(std::string codigo);

public:
    TablaHash(int tamanio);
    ~TablaHash();

    void agregar(Estacion* estacion);
    Estacion* buscar(std::string codigo);
    bool eliminar(std::string codigo);
    Estacion** obtenerTodas(int& cantidadSalida);

    int getTamanio();
    int getCantidad();
    int getColisiones();
    double getFactorCarga();
};

#endif