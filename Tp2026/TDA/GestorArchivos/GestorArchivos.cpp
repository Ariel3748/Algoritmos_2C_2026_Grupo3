#include <GestorArchivos.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

GestorArchivos::GestorArchivos(RegistroBicicletas* registro, GestorEstaciones* gestorEstaciones,
                               RegistroViajes* registroViajes)
{
    this->registro = registro;
    this->gestorEstaciones = gestorEstaciones;
    this->registroViajes = registroViajes;
}

void GestorArchivos::cargarBicicletas()
{
    ifstream archivo("bicicletas.txt");

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir bicicletas.txt" << endl;
        return;
    }

    string codigo_estacion, tipo, estado;
    int kilometros, bici_id;

    while (archivo >> bici_id >> codigo_estacion >> tipo >> estado >> kilometros)
    {
        Bicicleta bici(bici_id, codigo_estacion, tipo, estado, kilometros);
        registro->agregarBicicleta(bici);
    }
}

void GestorArchivos::cargarEstaciones()
{
    ifstream archivo("estaciones.txt");

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir estaciones.txt" << endl;
        return;
    }

    string codigo, nombre, barrio;
    int capacidad_anclajes, bicis_disponibles;

    while (archivo >> codigo >> nombre >> barrio >> capacidad_anclajes >> bicis_disponibles)
    {
        this->gestorEstaciones->agregarEstacion(codigo, nombre, barrio, capacidad_anclajes, bicis_disponibles);
    }
}

void GestorArchivos::cargarCiclovias()
{
    ifstream archivo("ciclovias.txt");

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir ciclovias.txt" << endl;
        return;
    }

    string estacion_a, estacion_b;

    while (archivo >> estacion_a >> estacion_b)
    {
        this->gestorEstaciones->agregarCiclovia(estacion_a, estacion_b);
    }
}

void GestorArchivos::cargarViajes()
{
    ifstream archivo("viajes.txt");

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir viajes.txt" << endl;
        return;
    }

    string estacion_origen, estacion_destino;
    int viaje_id, bici_id, fecha, duracion_min;
    long dni_usuario;

    while (archivo >> viaje_id >> bici_id >> dni_usuario >> estacion_origen >> estacion_destino >> fecha >>
           duracion_min)
    {
        Viaje* viaje =
            new Viaje(viaje_id, bici_id, dni_usuario, estacion_origen, estacion_destino, fecha, duracion_min);
        this->registroViajes->agregar(viaje);
    }
}