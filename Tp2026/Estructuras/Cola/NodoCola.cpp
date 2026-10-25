#include "NodoCola.h"

NodoCola::NodoCola(int dato) {
    this->dato = dato;
    this->siguiente = nullptr;
}

int NodoCola::getDato() {
    return dato;
}

NodoCola* NodoCola::getSiguiente() {
    return siguiente;
}

void NodoCola::setSiguiente(NodoCola* siguiente) {
    this->siguiente = siguiente;
}