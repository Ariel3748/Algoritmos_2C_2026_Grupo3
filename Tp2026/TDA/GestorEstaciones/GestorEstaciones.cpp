#include "GestorEstaciones.h"
#include <iostream>

GestorEstaciones::GestorEstaciones(int tamanioTabla, int capacidadGrafo)
    : tabla(tamanioTabla), grafo(capacidadGrafo) {
}

bool GestorEstaciones::agregarEstacion(std::string codigo, std::string nombre,
                                       std::string barrio, int capacidadAnclajes,
                                       int bicisDisponibles) {
    if (tabla.buscar(codigo) != nullptr) {
        std::cout << "Ya existe una estacion con el codigo " << codigo << std::endl;
        return false;
    }
    tabla.agregar(new Estacion(codigo, nombre, barrio, capacidadAnclajes, bicisDisponibles));
    return true;
}

void GestorEstaciones::mostrarEstacion(std::string codigo) {
    Estacion* e = tabla.buscar(codigo);
    if (e == nullptr) {
        std::cout << "No existe la estacion " << codigo << std::endl;
        return;
    }
    e->mostrar();
}

bool GestorEstaciones::eliminarEstacion(std::string codigo) {
    if (!tabla.eliminar(codigo)) {
        std::cout << "No existe la estacion " << codigo << std::endl;
        return false;
    }

    grafo.eliminarEstacion(codigo);
    return true;
}

void GestorEstaciones::listarOrdenadas(bool porCapacidad) {
    int n;
    Estacion** v = tabla.obtenerTodas(n);
    ordenador.ordenarEstaciones(v, n, porCapacidad);
    for (int i = 0; i < n; i++) {
        v[i]->mostrar();
    }
    delete[] v;   // solo el arreglo de punteros: las estaciones son de la tabla
}

void GestorEstaciones::listarPocaOcupacion() {
    int n;
    Estacion** v = tabla.obtenerTodas(n);
    bool hubo = false;
    for (int i = 0; i < n; i++) {
        if (v[i]->getOcupacion() < 0.20) {
            v[i]->mostrar();
            hubo = true;
        }
    }
    if (!hubo) {
        std::cout << "No hay estaciones con menos del 20% de ocupacion" << std::endl;
    }
    delete[] v;
}

int GestorEstaciones::getColisiones() {
    return tabla.getColisiones();
}

double GestorEstaciones::getFactorCarga() {
    return tabla.getFactorCarga();
}

void GestorEstaciones::agregarCiclovia(std::string estacionA, std::string estacionB) {
    if (tabla.buscar(estacionA) == nullptr || tabla.buscar(estacionB) == nullptr) {
        std::cout << "Las dos estaciones tienen que existir" << std::endl;
        return;
    }
    grafo.agregarCiclovia(estacionA, estacionB);
}

void GestorEstaciones::recorridoMasCorto(std::string origen, std::string destino) {
    if (tabla.buscar(origen) == nullptr || tabla.buscar(destino) == nullptr) {
        std::cout << "Las dos estaciones tienen que existir" << std::endl;
        return;
    }
    grafo.caminoMasCorto(origen, destino);
}

Estacion* GestorEstaciones::buscarEstacion(std::string codigo)
{
    return tabla.buscar(codigo);
}


int GestorEstaciones::getTamanio() {
    return tabla.getTamanio();
}

int GestorEstaciones::getCantidad() {
    return tabla.getCantidad();
}