#include "Menu.h"
#include "TDA/Bicicleta/Bicicleta.h"
#include "TDA/Estacion/Estacion.h"
#include "TDA/Viaje/Viaje.h"
#include <iostream>
using namespace std;

Menu::Menu(RegistroBicicletas* registro)
{
    this->registro = registro;
    renderMenuPrincipal();
}

void Menu::renderMenuPrincipal()
{
    do
    {
        cout << "//////////////////////////////////////" << endl;
        cout << "Seleccione una opcion: " << endl;
        cout << "1 - Estaciones (A)" << endl;
        cout << "2 - Viajes y cola de espera (B)" << endl;
        cout << "3 - Registro Bicicletas (C)" << endl;
        cout << "4 - Redistribucion (D)" << endl;
        cout << "/////////////////////////////////////" << endl;

        cin >> this->opcion;

        switch (this->opcion)
        {
        case 1:
            renderEstaciones();
            break;
        case 2:
            renderViajesYColaDeEspera();
            break;
        case 3:
            renderRegistroDeBicicletas();
            break;
        }

    } while (opcion != 0);
}

void Menu::volverAMenuPrincipal()
{
    this->opcion = 0;
    renderMenuPrincipal();
}

void Menu::renderEstaciones()
{
    int opcionEstaciones;
    cout << "/////////ESTACIONES////////////" << endl;
    cout << "Seleccione una opcion: " << endl;
    cout << "1 - Mostrar la información de una estación dado su código" << endl;
    cout << "2 - Agregar una estación nueva al sistema" << endl;
    cout << "3 - Eliminar una estación existente" << endl;
    cout << "4 - Listar todas las estaciones ordenadas por capacidad de anclajes o por bicicletas disponibles" << endl;
    cout << "5 - Listar las estaciones con menos del 20% de ocupación" << endl;
    cout << "6 - calcular el recorrido por ciclovías con menor cantidad de tramos" << endl;
    cout << "7 - Volver al menu principal" << endl;
    cout << "///////////////////////////////" << endl;
    cin >> opcionEstaciones;

    switch (opcionEstaciones)
    {
    case 7:
        return;
    }
}

void Menu::renderViajesYColaDeEspera()
{
    int opcionViajes;
    cout << "/////////Viajes y cola de espera////////////" << endl;
    cout << "Seleccione una opcion: " << endl;
    cout << "1 - Calcular la cantidad de viajes que salieron de una estación dentro de un rango de fechas" << endl;
    cout << "2 - Buscar todos los viajes de un usuario dado su DNI y mostrar el total de minutos pedaleados" << endl;
    cout << "3 - Listar las bicicletas con más de X kilómetros" << endl;
    cout << "4 - 4" << endl;
    cout << "5 - 5" << endl;
    cout << "6 - Volver al menu principal" << endl;
    cout << "///////////////////////////////" << endl;
    cin >> opcionViajes;

    switch (opcionViajes)
    {
    case 6:
        return;
    }
}

void Menu::renderRegistroDeBicicletas()
{
    int opcionRegistro;
    cout << "/////////Viajes y cola de espera////////////" << endl;
    cout << "Seleccione una opcion: " << endl;
    cout << "1 - Insertar una bicicleta" << endl;
    cout << "2 - Buscar una bicicleta por ID y mostrar sus datos" << endl;
    cout << "3 - Listar todas las bicicletas ordenadas por ID (recorrido inorder)" << endl;
    cout << "4 - Contar cuántas bicicletas averiadas hay, recorriendo el árbol" << endl;
    cout << "5 - Calcular la altura del árbol" << endl;
    cout << "6 - Volver al menu principal" << endl;
    cout << "///////////////////////////////" << endl;
    cin >> opcionRegistro;

    switch (opcionRegistro)
    {
    case 2: {
        int id;
        cout << "Ingresa el ID de la bicicleta a buscar: " << endl;
        cin >> id;
        Bicicleta* biciEncontrada = registro->buscarBicicleta(id);
        if(biciEncontrada == nullptr){
            cout << "No existe una bicicleta con el ID proporcionado." << endl;
            break;
        };
        biciEncontrada->mostrar();
        break;
    }

    case 6: {
        return;
    }
    }
}
