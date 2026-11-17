#ifndef MENU_H
#define MENU_H
#include "TDA/GestorEstaciones/GestorEstaciones.h"
#include "TDA/Redistribucion/Redistribucion.h"
#include "TDA/RegistroBicicletas/RegistroBicicletas.h"
#include "TDA/RegistroViajes/RegistroViajes.h"
#include "TDA/Taller/Taller.h"

class Menu
{
  private:
    int opcion;
    RegistroBicicletas* registro;
    GestorEstaciones* gestorEstaciones;
    RegistroViajes* registroViajes;
    Taller* taller;
    Redistribucion* redistribucion;

  public:
    Menu(RegistroBicicletas* registro, GestorEstaciones* gestorEstaciones, RegistroViajes* registroViajes,
         Taller* taller, Redistribucion* redistribucion);
    void renderMenuPrincipal();
    void volverAMenuPrincipal();
    void renderEstaciones();
    void renderViajesYColaDeEspera();
    void renderRegistroDeBicicletas();
    void renderRedistribucion();
};

#endif
