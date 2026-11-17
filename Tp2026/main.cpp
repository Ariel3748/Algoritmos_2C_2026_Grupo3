#include "TDA/Bicicleta/Bicicleta.h"
#include "TDA/Estacion/Estacion.h"
#include "TDA/GestorEstaciones/GestorEstaciones.h"
#include "TDA/Menu/Menu.h"
#include "TDA/Redistribucion/Redistribucion.h"
#include "TDA/RegistroViajes/RegistroViajes.h"
#include "TDA/Viaje/Viaje.h"
#include "TDA/GestorArchivos/GestorArchivos.h"

#include <iostream>

int main()
{
    // Inicializar clases.
    RegistroBicicletas* registro = new RegistroBicicletas();
    GestorEstaciones* gestorEstaciones = new GestorEstaciones(50, 50);
    RegistroViajes* registroViajes = new RegistroViajes();
    Taller* taller = new Taller();
    Redistribucion* redistribucion = new Redistribucion();
    GestorArchivos* gestorArchivos = new GestorArchivos(registro, gestorEstaciones, registroViajes);

    // Crear desde los .txt.
    gestorArchivos->cargarEstaciones();
    gestorArchivos->cargarBicicletas();
    gestorArchivos->cargarViajes();
    gestorArchivos->cargarCiclovias();

    // Renderizar menu.
    Menu* menu = new Menu(registro, gestorEstaciones, registroViajes, taller, redistribucion);

    // Limpiar
    delete gestorEstaciones;
    delete registro;
    delete registroViajes;
    delete taller;
    delete redistribucion;
    delete gestorArchivos;
    delete menu;

    return 0;
}
