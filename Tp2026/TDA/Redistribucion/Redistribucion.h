#ifndef REDISTRIBUCION_H
#define REDISTRIBUCION_H

#include "TDA/Estacion/Estacion.h"
#include "Estructuras/Lista/Lista.h"

class Redistribucion
{
  public:
    void backtracking(NodoLista<Estacion*>* inicio, Lista<Estacion*>& seleccionadas, int capacidadCamion, int sumaActual, bool& haySolucion);
    void calcularEstacionesAVisitar(int capacidad, Lista<Estacion*>& estaciones);
};

#endif