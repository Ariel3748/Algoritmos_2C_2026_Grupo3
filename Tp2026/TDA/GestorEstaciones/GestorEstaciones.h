#ifndef GESTORESTACIONES_H
#define GESTORESTACIONES_H

#include <string>
#include "Estructuras/TablaHash/TablaHash.h"
#include "TDA/Ordenador/Ordenador.h"

class GestorEstaciones {
private:
    TablaHash tabla;
    Ordenador ordenador;

public:
    GestorEstaciones(int tamanioTabla);

    bool agregarEstacion(std::string codigo, std::string nombre, std::string barrio,
                         int capacidadAnclajes, int bicisDisponibles);
    void mostrarEstacion(std::string codigo);
    bool eliminarEstacion(std::string codigo);
    void listarOrdenadas(bool porCapacidad);
    void listarPocaOcupacion();

    int getColisiones();
    double getFactorCarga();
};

#endif