#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H
#include "TDA/GestorEstaciones/GestorEstaciones.h"
#include "TDA/Redistribucion/Redistribucion.h"
#include "TDA/RegistroBicicletas/RegistroBicicletas.h"
#include "TDA/RegistroViajes/RegistroViajes.h"
#include "TDA/Taller/Taller.h"

class GestorArchivos
{
  private:
    RegistroBicicletas* registro;
    GestorEstaciones* gestorEstaciones;
    RegistroViajes* registroViajes;
    Taller* taller;
    Redistribucion* redistribucion;

  public:
    GestorArchivos(RegistroBicicletas* registro, GestorEstaciones* gestorEstaciones, RegistroViajes* registroViajes);
    void cargarEstaciones();
    void cargarBicicletas();
    void cargarViajes();
    void cargarCiclovias();
};

#endif
