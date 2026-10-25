#include "ListaViajes.h"

ListaViajes::ListaViajes() {
    primero = nullptr;
    cantidad = 0;
}

ListaViajes::~ListaViajes() {
    NodoViaje* actual = primero;
    while (actual != nullptr) {
        NodoViaje* aBorrar = actual;
        actual = actual->getSiguiente();
        delete aBorrar->getViaje();   // la lista es dueña de los viajes
        delete aBorrar;
    }
}

void ListaViajes::agregar(Viaje* viaje) {
    NodoViaje* nuevo = new NodoViaje(viaje);
    nuevo->setSiguiente(primero);   // al principio: O(1)
    primero = nuevo;
    cantidad++;
}

NodoViaje* ListaViajes::getPrimero() {
    return primero;
}

int ListaViajes::getCantidad() {
    return cantidad;
}

bool ListaViajes::estaVacia() {
    return primero == nullptr;
}