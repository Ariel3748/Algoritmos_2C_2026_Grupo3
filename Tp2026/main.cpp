#include <iostream>
#include "TDA/Estacion/Estacion.h"
#include "TDA/Bicicleta/Bicicleta.h"
#include "TDA/Viaje/Viaje.h"
#include "Menu/Menu.h"

int main() {
    Estacion* e = new Estacion("PLZ", "PlazaDeMayo", "Monserrat", 30, 12);
    Bicicleta* b = new Bicicleta(501, "PLZ", "Mecanica", "OK", 1240);
    Viaje* v = new Viaje(9001, 501, 30123456, "PLZ", "PAL", 20260310, 25);
    RegistroBicicletas* registro = new RegistroBicicletas();
    registro->agregarBicicleta(*b);
    e->mostrar();
    b->mostrar();
    v->mostrar();

    Menu* menu = new Menu(registro);
    delete menu;
    delete e;
    delete b;
    delete v;
    return 0;
}
