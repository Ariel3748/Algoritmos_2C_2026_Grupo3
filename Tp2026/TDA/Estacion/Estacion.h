#ifndef ESTACION_H
#define ESTACION_H

#include "Estructuras/Cola/Cola.h"  
#include <string>

class Estacion {
private:
    std::string codigo;
    std::string nombre;
    std::string barrio;
    int capacidadAnclajes;
    int bicisDisponibles;
    Cola colaEspera;   // la cola vive DENTRO de la estación, sin puntero

public:
    Estacion(std::string codigo, std::string nombre, std::string barrio,
             int capacidadAnclajes, int bicisDisponibles);

    std::string getCodigo();
    std::string getNombre();
    std::string getBarrio();
    int getCapacidadAnclajes();
    int getBicisDisponibles();

    void setBicisDisponibles(int cantidad);

    double getOcupacion();
    void mostrar();

    bool retirarBici(int dni);
    void devolverBici();
};

#endif