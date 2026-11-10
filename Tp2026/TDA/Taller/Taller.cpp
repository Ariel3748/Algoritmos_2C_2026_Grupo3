#include "Taller.h"
#include <iostream>

Taller::Taller() {
    capacidad = 10;
    cantidad = 0;
    bicis = new Bicicleta*[capacidad];
}

Taller::~Taller() {
    // las bicicletas NO se borran acá: son del registro de bicicletas
    delete[] bicis;
}

void Taller::agrandar() {
    int nuevaCapacidad = capacidad * 2;
    Bicicleta** nuevo = new Bicicleta*[nuevaCapacidad];

    for (int i = 0; i < cantidad; i++) {
        nuevo[i] = bicis[i];
    }

    delete[] bicis;
    bicis = nuevo;
    capacidad = nuevaCapacidad;
}

void Taller::intercambiar(int i, int j) {
    Bicicleta* aux = bicis[i];
    bicis[i] = bicis[j];
    bicis[j] = aux;
}

void Taller::subir(int i) {
    while (i > 0) {
        int padre = (i - 1) / 2;
        if (bicis[i]->getPrioridadReparacion() < bicis[padre]->getPrioridadReparacion()) {
            intercambiar(i, padre);
            i = padre;
        } else {
            break;
        }
    }
}

void Taller::bajar(int i) {
    while (true) {
        int izquierdo = 2 * i + 1;
        int derecho = 2 * i + 2;
        int menor = i;

        if (izquierdo < cantidad &&
            bicis[izquierdo]->getPrioridadReparacion() < bicis[menor]->getPrioridadReparacion()) {
            menor = izquierdo;
        }
        if (derecho < cantidad &&
            bicis[derecho]->getPrioridadReparacion() < bicis[menor]->getPrioridadReparacion()) {
            menor = derecho;
        }

        if (menor == i) {
            break;
        }
        intercambiar(i, menor);
        i = menor;
    }
}

void Taller::insertar(Bicicleta* bici, int prioridad) {
    bici->setPrioridadReparacion(prioridad);   // el setter aplica la regla de las eléctricas

    if (cantidad == capacidad) {
        agrandar();
    }

    bicis[cantidad] = bici;
    subir(cantidad);
    cantidad++;
}

Bicicleta* Taller::extraerMasUrgente() {
    if (estaVacio()) {
        std::cout << "El taller esta vacio" << std::endl;
        return nullptr;
    }

    Bicicleta* masUrgente = bicis[0];

    cantidad--;
    bicis[0] = bicis[cantidad];
    bajar(0);

    return masUrgente;
}

bool Taller::estaVacio() {
    return cantidad == 0;
}

int Taller::getCantidad() {
    return cantidad;
}