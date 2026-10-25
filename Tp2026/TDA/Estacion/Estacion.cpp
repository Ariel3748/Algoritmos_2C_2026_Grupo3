#include "Estacion.h"
#include <iostream>

Estacion::Estacion(std::string codigo, std::string nombre, std::string barrio,
                   int capacidadAnclajes, int bicisDisponibles) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->barrio = barrio;
    this->capacidadAnclajes = capacidadAnclajes;
    this->bicisDisponibles = bicisDisponibles;
}

std::string Estacion::getCodigo() {
    return codigo;
}

std::string Estacion::getNombre() {
    return nombre;
}

std::string Estacion::getBarrio() {
    return barrio;
}

int Estacion::getCapacidadAnclajes() {
    return capacidadAnclajes;
}

int Estacion::getBicisDisponibles() {
    return bicisDisponibles;
}

void Estacion::setBicisDisponibles(int cantidad) {
    bicisDisponibles = cantidad;
}

double Estacion::getOcupacion() {
    if (capacidadAnclajes == 0) {
        return 0.0;
    }
    return (double) bicisDisponibles / capacidadAnclajes;
}

void Estacion::mostrar() {
    std::cout << codigo << " | " << nombre << " | " << barrio
              << " | capacidad: " << capacidadAnclajes
              << " | disponibles: " << bicisDisponibles << std::endl;
}