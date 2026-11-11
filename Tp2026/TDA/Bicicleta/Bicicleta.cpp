#include "Bicicleta.h"
#include <iostream>

Bicicleta::Bicicleta(int biciId, std::string codigoEstacion, std::string tipo,
                     std::string estado, int kilometros) {
    this->biciId = biciId;
    this->codigoEstacion = codigoEstacion;
    this->tipo = tipo;
    this->estado = estado;
    this->kilometros = kilometros;
    this->prioridadReparacion = 0;
}

int Bicicleta::getBiciId() {
    return biciId;
}

std::string Bicicleta::getCodigoEstacion() {
    return codigoEstacion;
}

std::string Bicicleta::getTipo() {
    return tipo;
}

std::string Bicicleta::getEstado() {
    return estado;
}

int Bicicleta::getKilometros() {
    return kilometros;
}

int Bicicleta::getPrioridadReparacion() {
    return prioridadReparacion;
}

void Bicicleta::setCodigoEstacion(std::string codigoEstacion) {
    this->codigoEstacion = codigoEstacion;
}

void Bicicleta::setEstado(std::string estado) {
    this->estado = estado;
}

void Bicicleta::setKilometros(int kilometros) {
    this->kilometros = kilometros;
}

void Bicicleta::setPrioridadReparacion(int prioridad) {
    if (esElectrica()) {
        this->prioridadReparacion = 1;  
    } else {
        this->prioridadReparacion = prioridad;
    }
}

bool Bicicleta::estaAveriada() {
    return estado == "Averiada";
}

bool Bicicleta::esElectrica() {
    return tipo == "Electrica";
}

// Overloading de operators para poder hacer comparaciones entre Bicicletas, sin tener que repetir llamados al getter.
bool Bicicleta::operator<(Bicicleta& b){
    return this->getBiciId() < b.getBiciId();
}

bool Bicicleta::operator==(Bicicleta& b){
    return this->getBiciId() == b.getBiciId();
}

void Bicicleta::mostrar() {
    std::cout << "Bici " << biciId << " | " << codigoEstacion << " | "
              << tipo << " | " << estado << " | " << kilometros << " km"
              << std::endl;
}

