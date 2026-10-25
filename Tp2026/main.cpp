#include <iostream>
#include "TDA/Estacion/Estacion.h"
#include "TDA/Bicicleta/Bicicleta.h"
#include "TDA/Viaje/Viaje.h"

int main() {
    Estacion* e = new Estacion("PLZ", "PlazaDeMayo", "Monserrat", 30, 12);
    Bicicleta* b = new Bicicleta(501, "PLZ", "Mecanica", "OK", 1240);
    Viaje* v = new Viaje(9001, 501, 30123456, "PLZ", "PAL", 20260310, 25);

    e->mostrar();
    b->mostrar();
    v->mostrar();

    delete e;
    delete b;
    delete v;
    return 0;
}