#ifndef GESTORESTACIONES_H
#define GESTORESTACIONES_H

#include <string>
#include "Estructuras/TablaHash/TablaHash.h"
#include "TDA/Ordenador/Ordenador.h"
#include "Estructuras/Grafo/Grafo.h"

class GestorEstaciones {
private:
    TablaHash tabla;
    Ordenador ordenador;
    Grafo grafo;

public:
    GestorEstaciones(int tamanioTabla,  int capacidadGrafo);

    bool agregarEstacion(std::string codigo, std::string nombre, std::string barrio,
                         int capacidadAnclajes, int bicisDisponibles);
    void mostrarEstacion(std::string codigo);
    bool eliminarEstacion(std::string codigo);
    void listarOrdenadas(bool porCapacidad);
    void listarPocaOcupacion();
    Estacion* buscarEstacion(std::string codigo);
    void agregarCiclovia(std::string estacionA, std::string estacionB);
    void recorridoMasCorto(std::string origen, std::string destino);

    int getColisiones();
    double getFactorCarga();
};

#endif