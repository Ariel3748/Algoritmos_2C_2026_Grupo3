#include "Cola.h"
#include <iostream>

Cola::Cola() {
    frente = nullptr;
    final = nullptr;
    cantidad = 0;
}

Cola::~Cola() {
    while (!estaVacia()) {
        desencolar();
    }
}

void Cola::encolar(int dato) {
    NodoCola* nuevo = new NodoCola(dato);

    if (estaVacia()) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->setSiguiente(nuevo);
        final = nuevo;
    }
    cantidad++;
}

int Cola::desencolar() {
    if (estaVacia()) {
        std::cout << "Error: la cola esta vacia" << std::endl;
        return 0;
    }

    NodoCola* aBorrar = frente;
    int dato = aBorrar->getDato();

    frente = frente->getSiguiente();
    if (frente == nullptr) {
        final = nullptr;   // la cola quedó vacía
    }

    delete aBorrar;
    cantidad--;
    return dato;
}

int Cola::verFrente() {
    if (estaVacia()) {
        std::cout << "Error: la cola esta vacia" << std::endl;
        return 0;
    }
    return frente->getDato();
}

bool Cola::estaVacia() {
    return frente == nullptr;
}

int Cola::getCantidad() {
    return cantidad;
}