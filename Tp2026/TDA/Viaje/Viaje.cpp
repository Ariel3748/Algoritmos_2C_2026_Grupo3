#include "Viaje.h"
#include <iostream>

Viaje::Viaje(int viajeId, int biciId, long dniUsuario, std::string estacionOrigen,
             std::string estacionDestino, int fecha, int duracionMin) {
    this->viajeId = viajeId;
    this->biciId = biciId;
    this->dniUsuario = dniUsuario;
    this->estacionOrigen = estacionOrigen;
    this->estacionDestino = estacionDestino;
    this->fecha = fecha;
    this->duracionMin = duracionMin;
}

int Viaje::getViajeId() {
    return viajeId;
}

int Viaje::getBiciId() {
    return biciId;
}

long Viaje::getDniUsuario() {
    return dniUsuario;
}

std::string Viaje::getEstacionOrigen() {
    return estacionOrigen;
}

std::string Viaje::getEstacionDestino() {
    return estacionDestino;
}

int Viaje::getFecha() {
    return fecha;
}

int Viaje::getDuracionMin() {
    return duracionMin;
}

void Viaje::mostrar() {
    std::cout << "Viaje " << viajeId << " | bici " << biciId
              << " | DNI " << dniUsuario << " | " << estacionOrigen
              << " -> " << estacionDestino << " | " << fecha
              << " | " << duracionMin << " min" << std::endl;
}