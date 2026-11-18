#include <fstream>
#include <iostream>
#include <string>
#include "TDA/GestorEstaciones/GestorEstaciones.h"

int main() {
    GestorEstaciones gestor(13, 30);   // tamaño de la tabla, capacidad del grafo

    std::ifstream archivo("estaciones.txt");
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir estaciones.txt" << std::endl;
        return 1;
    }

    std::string codigo, nombre, barrio;
    int capacidad, disponibles;
    while (archivo >> codigo >> nombre >> barrio >> capacidad >> disponibles) {
        gestor.agregarEstacion(codigo, nombre, barrio, capacidad, disponibles);
    }

    std::cout << "Estaciones: " << gestor.getCantidad() << std::endl;
    std::cout << "Tamanio: " << gestor.getTamanio() << std::endl;
    std::cout << "Colisiones: " << gestor.getColisiones() << std::endl;
    std::cout << "Factor de carga: " << gestor.getFactorCarga() << std::endl;

    gestor.mostrarEstacion("PLZ");
    return 0;
}

/*
g++ -std=c++17 -Wall -Wextra -I. -IEstructuras/Cola \
    pruebaHash.cpp \
    TDA/GestorEstaciones/GestorEstaciones.cpp \
    TDA/Ordenador/Ordenador.cpp \
    TDA/Estacion/Estacion.cpp \
    Estructuras/TablaHash/TablaHash.cpp \
    Estructuras/TablaHash/NodoHash.cpp \
    Estructuras/Grafo/Grafo.cpp \
    Estructuras/Cola/Cola.cpp \
    Estructuras/Cola/NodoCola.cpp \
    -o pruebaHash
*/