#include "RegistroViajes.h"

void RegistroViajes::agregar(Viaje* viaje) {
    lista.agregar(viaje);
}

int RegistroViajes::contarViajesDesdeEstacion(std::string codigo, int fechaDesde, int fechaHasta) {
    int contador = 0;
    NodoViaje* actual = lista.getPrimero();

    while (actual != nullptr) {
        Viaje* v = actual->getViaje();
        if (v->getEstacionOrigen() == codigo &&
            v->getFecha() >= fechaDesde && v->getFecha() <= fechaHasta) {
            contador++;
        }
        actual = actual->getSiguiente();
    }
    return contador;
}

int RegistroViajes::buscarPorDni(long dni) {
    int totalMinutos = 0;
    NodoViaje* actual = lista.getPrimero();

    while (actual != nullptr) {
        Viaje* v = actual->getViaje();
        if (v->getDniUsuario() == dni) {
            v->mostrar();
            totalMinutos += v->getDuracionMin();
        }
        actual = actual->getSiguiente();
    }
    return totalMinutos;
}

int RegistroViajes::getCantidad() {
    return lista.getCantidad();
}