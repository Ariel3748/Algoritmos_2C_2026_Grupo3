#ifndef MENU_H
#define MENU_H
#include "TDA/RegistroBicicletas/RegistroBicicletas.h"

class Menu
{
  private:
    int opcion;
    RegistroBicicletas* registro;

  public:
    Menu(RegistroBicicletas* registro);
    void renderMenuPrincipal();
    void volverAMenuPrincipal();
    void renderEstaciones();
    void renderViajesYColaDeEspera();
    void renderRegistroDeBicicletas();
};

#endif
