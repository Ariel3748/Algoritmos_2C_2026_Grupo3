#include "NodoViaje.h"

NodoViaje::NodoViaje(Viaje* viaje) {
    this->viaje = viaje;
    this->siguiente = nullptr;
}

Viaje* NodoViaje::getViaje() {
    return viaje;
}

NodoViaje* NodoViaje::getSiguiente() {
    return siguiente;
}

void NodoViaje::setSiguiente(NodoViaje* siguiente) {
    this->siguiente = siguiente;
}