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

bool Estacion::retirarBici(int dni) {
    if (bicisDisponibles > 0) {
        bicisDisponibles--;
        return true;
    }
    colaEspera.encolar(dni);  
    return false;
}

void Estacion::devolverBici() {
    if (!colaEspera.estaVacia()) {
        int dni = colaEspera.desencolar();
        std::cout << "Bici asignada al usuario " << dni << std::endl;
        // la bici pasa directo al usuario: bicisDisponibles no cambia
    } else {
        bicisDisponibles++;
    }
}