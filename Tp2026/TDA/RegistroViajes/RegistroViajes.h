#ifndef REGISTROVIAJES_H
#define REGISTROVIAJES_H

#include <string>
#include "ListaViajes.h"

class RegistroViajes {
private:
    ListaViajes lista;

public:
    void agregar(Viaje* viaje);
    int contarViajesDesdeEstacion(std::string codigo, int fechaDesde, int fechaHasta);
    int buscarPorDni(long dni);   // muestra los viajes y devuelve el total de minutos
    int getCantidad();
};

#endif