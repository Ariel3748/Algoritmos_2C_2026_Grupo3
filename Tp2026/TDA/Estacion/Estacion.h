#ifndef ESTACION_H
#define ESTACION_H

#include <string>

class Estacion {
private:
    std::string codigo;
    std::string nombre;
    std::string barrio;
    int capacidadAnclajes;
    int bicisDisponibles;

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
};

#endif