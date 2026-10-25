#include "Bicicleta.h"
#include <iostream>

Bicicleta::Bicicleta(int biciId, std::string codigoEstacion, std::string tipo,
                     std::string estado, int kilometros) {
    this->biciId = biciId;
    this->codigoEstacion = codigoEstacion;
    this->tipo = tipo;
    this->estado = estado;
    this->kilometros = kilometros;
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

void Bicicleta::setCodigoEstacion(std::string codigoEstacion) {
    this->codigoEstacion = codigoEstacion;
}

void Bicicleta::setEstado(std::string estado) {
    this->estado = estado;
}

void Bicicleta::setKilometros(int kilometros) {
    this->kilometros = kilometros;
}

bool Bicicleta::estaAveriada() {
    return estado == "Averiada";
}

bool Bicicleta::esElectrica() {
    return tipo == "Electrica";
}

void Bicicleta::mostrar() {
    std::cout << "Bici " << biciId << " | " << codigoEstacion << " | "
              << tipo << " | " << estado << " | " << kilometros << " km"
              << std::endl;
}

