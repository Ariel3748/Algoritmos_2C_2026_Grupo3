#include <string>
#include "TablaHash.h"


TablaHash::TablaHash(int tamanio) {
    this->tamanio = tamanio;
    this->cantidad = 0;
    this->colisiones = 0;
    tabla = new NodoHash*[tamanio];
    for (int i = 0; i < tamanio; i++) {
        tabla[i] = nullptr;
    }
}

TablaHash::~TablaHash() {
    // la tabla es dueña de las estaciones: las borra junto con los nodos
    for (int i = 0; i < tamanio; i++) {
        NodoHash* actual = tabla[i];
        while (actual != nullptr) {
            NodoHash* aBorrar = actual;
            actual = actual->getSiguiente();
            delete aBorrar->getEstacion();
            delete aBorrar;
        }
    }
    delete[] tabla;
}

int TablaHash::hash(std::string codigo) {
    unsigned long long clave = 0;
    for (int i = 0; i < (int) codigo.length(); i++) {
        clave = clave * 256 + (unsigned char) codigo[i];
    }

    unsigned long long cuadrado = clave * clave;

    // me quedo con los dígitos del medio
    unsigned long long medio = (cuadrado / 100000) % 100000;

    return (int) (medio % tamanio);
}

void TablaHash::agregar(Estacion* estacion) {
    int pos = hash(estacion->getCodigo());

    if (tabla[pos] != nullptr) {
        colisiones++;   // el casillero ya tenía algo
    }

    NodoHash* nuevo = new NodoHash(estacion);
    nuevo->setSiguiente(tabla[pos]);   // al principio de la lista: O(1)
    tabla[pos] = nuevo;
    cantidad++;
}

Estacion* TablaHash::buscar(std::string codigo) {
    int pos = hash(codigo);
    NodoHash* actual = tabla[pos];

    while (actual != nullptr) {
        if (actual->getEstacion()->getCodigo() == codigo) {
            return actual->getEstacion();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

bool TablaHash::eliminar(std::string codigo) {
    int pos = hash(codigo);
    NodoHash* actual = tabla[pos];
    NodoHash* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->getEstacion()->getCodigo() == codigo) {
            if (anterior == nullptr) {
                tabla[pos] = actual->getSiguiente();        // era el primero
            } else {
                anterior->setSiguiente(actual->getSiguiente());
            }
            delete actual->getEstacion();
            delete actual;
            cantidad--;
            return true;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    }
    return false;   // no existía
}

Estacion** TablaHash::obtenerTodas(int& cantidadSalida) {
    Estacion** arreglo = new Estacion*[cantidad];
    int k = 0;
    for (int i = 0; i < tamanio; i++) {
        NodoHash* actual = tabla[i];
        while (actual != nullptr) {
            arreglo[k] = actual->getEstacion();
            k++;
            actual = actual->getSiguiente();
        }
    }
    cantidadSalida = k;
    return arreglo;
}

int TablaHash::getTamanio() {
    return tamanio;
}

int TablaHash::getCantidad() {
    return cantidad;
}

int TablaHash::getColisiones() {
    return colisiones;
}

double TablaHash::getFactorCarga() {
    return (double) cantidad / tamanio;
}