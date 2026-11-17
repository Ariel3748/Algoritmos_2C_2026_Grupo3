#include "Menu.h"
#include "TDA/Bicicleta/Bicicleta.h"
#include "TDA/Estacion/Estacion.h"
#include "TDA/RegistroViajes/RegistroViajes.h"
#include "TDA/Viaje/Viaje.h"

#include <iostream>
using namespace std;

Menu::Menu(RegistroBicicletas* registro, GestorEstaciones* gestorEstaciones, RegistroViajes* registroViajes,
           Taller* taller, Redistribucion* redistribucion)
{
    this->registro = registro;
    this->gestorEstaciones = gestorEstaciones;
    this->taller = taller;
    this->registroViajes = registroViajes;
    this->redistribucion = redistribucion;
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
        case 4:
            renderRedistribucion();
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
    case 1: {
        // Mostrar la información de una estación dado su código
        string codigo;
        cout << "Ingrese el codigo de la estacion: " << endl;
        cin >> codigo;
        gestorEstaciones->mostrarEstacion(codigo);
        break;
    }
    case 2: {
        // Agregar una estación nueva al sistema
        string codigo;
        string nombre;
        string barrio;
        int capacidadAnclajes;
        int bicisDisponibles;

        cout << "Ingrese el codigo de la estacion: " << endl;
        cin >> codigo;

        cout << "Ingrese el nombre de la estacion: " << endl;
        cin >> nombre;

        cout << "Ingrese el barrio de la estacion: " << endl;
        cin >> barrio;

        cout << "Ingrese la capacidad de la estacion: " << endl;
        cin >> capacidadAnclajes;

        cout << "Ingrese cantidad de bicis disponibles: " << endl;
        cin >> bicisDisponibles;

        gestorEstaciones->agregarEstacion(codigo, nombre, barrio, capacidadAnclajes, bicisDisponibles);
        cout << "Estacion Creada: " << endl;
        gestorEstaciones->mostrarEstacion(codigo);
        break;
    }
    case 3: {
        // Eliminar una estación existente
        string codigo;
        cout << "Ingrese el codigo de la estacion: " << endl;
        cin >> codigo;

        gestorEstaciones->eliminarEstacion(codigo);
        cout << "Estacion eliminada." << endl;
        break;
    }
    case 4: {
        // Listar todas las estaciones ordenadas por capacidad de anclajes o por bicicletas disponibles.
        int eleccion;
        cout << "Seleccione una opcion: Por capacidad -> 1 , Por cantidad bicicletas -> 0" << endl;
        cin >> eleccion;
        if (eleccion == 0 || eleccion == 1)
        {
            gestorEstaciones->listarOrdenadas(eleccion);
        }
        break;
    }
    case 5: {
        // Listar las estaciones con menos del 20% de ocupación.
        gestorEstaciones->listarPocaOcupacion();
        break;
    }
    case 6: {
        /* Dadas dos estaciones, calcular el recorrido por ciclovías con menor cantidad de tramos usando
           búsqueda en anchura (BFS) */
        string codigoPrimerEstacion;
        string codigoSegundaEstacion;

        cout << "Ingrese el codigo de la primer estacion: " << endl;
        cin >> codigoPrimerEstacion;

        cout << " Ingrese el codigo de la segunda estacion: " << endl;
        cin >> codigoSegundaEstacion;

        gestorEstaciones->recorridoMasCorto(codigoPrimerEstacion, codigoSegundaEstacion);
        break;
    }
    case 7: {
        break;
    }
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
    cout << "4 - Retirar bicicleta de una estacion" << endl;
    cout << "5 - Taller de Reparaciones" << endl;
    cout << "6 - Volver al menu principal" << endl;
    cout << "///////////////////////////////" << endl;
    cin >> opcionViajes;

    switch (opcionViajes)
    {
    case 1: {
        // Calcular la cantidad de viajes que salieron de una estación dentro de un rango de fechas
        string codigoEstacion;
        int primerFecha;
        int segundaFecha;

        cout << "Ingrese el codigo de la primer estacion: " << endl;
        cin >> codigoEstacion;

        // Formato Fecha / AAAAMMDD

        cout << "Ingrese la primer fecha (AAAAMMDD): " << endl;
        cin >> primerFecha;

        cout << "Ingrese la segunda fecha (AAAAMMDD): " << endl;
        cin >> segundaFecha;

        int resultado = registroViajes->contarViajesDesdeEstacion(codigoEstacion, primerFecha, segundaFecha);

        cout << "Cantidad de viajes: " << resultado << endl;
        break;
    }
    case 2: {
        long dni;
        // Buscar todos los viajes de un usuario dado su DNI y mostrar el total de minutos pedaleados
        cout << "Ingrese el DNI del usuario: " << endl;
        cin >> dni;
        int totalMinutos = registroViajes->buscarPorDni(dni);
        cout << "Total minutos peleados: " << totalMinutos << endl;
        break;
    }
    case 3: {
        // Listar las bicicletas con más de X kilómetros
        int kilometros;
        cout << "Ingrese cantidad de kilometros: : " << endl;
        cin >> kilometros;
        registro->listarBicicletasSegunKilometros(kilometros);
        break;
    }
    case 4: {
        int eleccion;
        string codigo;

        cout << "Retirar bicicleta -> 1, Devolver bicicleta -> 0" << endl;
        cin >> eleccion;

        cout << "Ingrese el codigo de la estacion: " << endl;
        cin >> codigo;

        Estacion* estacion = gestorEstaciones->buscarEstacion(codigo);

        if (eleccion)
        {
            int dni;
            cout << "Ingrese el DNI del usuario: " << endl;
            cin >> dni;

            if (estacion->retirarBici(dni))
            {
                cout << "Bicicleta retirada." << endl;
            }
            else
            {
                cout << "No hay bicicletas disponibles. " << "Quedaste en la cola de espera." << endl;
            }
        }
        else
        {
            estacion->devolverBici();
            cout << "Devolucion procesada." << endl;
        }

        break;
    }
    case 5: {
        int eleccion;
        cout << "1 - Insertar una bicicleta" << endl;
        cout << "2 - Extraer la mas urgente" << endl;
        cin >> eleccion;

        if (eleccion == 1)
        {
            int id;
            int prioridad;

            cout << "Ingrese el ID de la bicicleta: " << endl;
            cin >> id;

            cout << "Ingrese la prioridad (1 a 3): " << endl;
            cin >> prioridad;

            Bicicleta* bici = registro->buscarBicicleta(id);
            taller->insertar(bici, prioridad);

            cout << "Bicicleta ingresada al taller." << endl;
        }
        else if (eleccion == 2)
        {
            Bicicleta* bici = taller->extraerMasUrgente();

            if (bici != nullptr)
            {
                cout << "Bicicleta mas urgente: " << endl;
                bici->mostrar();
            }
        }

        break;
    }
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
    case 1: {
        // Insertar una bicicleta
        /* int biciId, std::string codigoEstacion, std::string tipo,
              std::string estado, int kilometros */
        int id;
        string codigoEstacion;
        string tipo;
        int kilometros;

        cout << "Ingrese el ID a asignar: " << endl;
        cin >> id;

        cout << "Ingrese el codigo de la estacion: " << endl;
        cin >> codigoEstacion;
        Estacion* estacion = gestorEstaciones->buscarEstacion(codigoEstacion);

        cout << "Ingrese el tipo de la bicicleta: " << endl;
        cin >> tipo;

        cout << "Ingrese la cantidad de kilometros que posee la bicicleta " << endl;
        cin >> kilometros;

        Bicicleta* bici = new Bicicleta(id, codigoEstacion, tipo, "sana", kilometros);

        registro->agregarBicicleta(*bici);
        estacion->devolverBici();
        break;
    }
    case 2: {
        int id;
        cout << "Ingresa el ID de la bicicleta a buscar: " << endl;
        cin >> id;

        Bicicleta* biciEncontrada = registro->buscarBicicleta(id);
        if (biciEncontrada == nullptr)
        {
            cout << "No existe una bicicleta con el ID proporcionado." << endl;
            break;
        };
        biciEncontrada->mostrar();
        break;
    }
    case 3: {
        // Listar todas las bicicletas ordenadas por ID.
        registro->listarBicicletasEnOrden();
        break;
    }
    case 4: {
        // Contar cuántas bicicletas averiadas hay, recorriendo el árbol.
        int cantidad = registro->contarBicicletasAveriadas();
        cout << "Cantidad de bicicletas averiadas: " << cantidad << endl;
        break;
    }
    case 5: {
        // Calcular la altura del árbol.
        int altura = registro->getAlturaArbol();
        cout << "Altura del arbol: " << altura << endl;
        break;
    }
    }
}

void Menu::renderRedistribucion()
{
    int opcionRedistribucion;
    cout << "/////////Redistribucion////////////" << endl;
    cout << "Seleccione una opcion: " << endl;
    cout << "1 - Proveer lista de estaciones" << endl;
    cout << "2 - Usar ejemplo" << endl;
    cout << "///////////////////////////////" << endl;
    cin >> opcionRedistribucion;

    switch (opcionRedistribucion)
    {
    case 1: {
        int capacidadCamion;
        int cantidadEstaciones;
        Lista<Estacion*> estaciones;

        cout << "Ingrese la capacidad del camion: " << endl;
        cin >> capacidadCamion;

        cout << "Ingrese cuantas estaciones quiere considerar: " << endl;
        cin >> cantidadEstaciones;

        for (int i = 0; i < cantidadEstaciones; i++)
        {
            string codigo;

            cout << "Ingrese el codigo de la estacion: " << endl;
            cin >> codigo;

            Estacion* estacion = gestorEstaciones->buscarEstacion(codigo);
            estaciones.agregar(estacion);
        }

        redistribucion->calcularEstacionesAVisitar(capacidadCamion, estaciones);

        break;
    }

    case 2: {
        Estacion plz("PLZ", "PLZ", "", 10, 7);
        Estacion cab("CAB", "CAB", "", 10, 3);
        Estacion ret("RET", "RET", "", 10, 5);
        Estacion con("CON", "CON", "", 10, 8);
        Estacion boe("BOE", "BOE", "", 10, 5);

        Lista<Estacion*> estaciones;
        estaciones.agregar(&plz);
        estaciones.agregar(&cab);
        estaciones.agregar(&ret);
        estaciones.agregar(&con);
        estaciones.agregar(&boe);

        cout << "Capacidad del camion: 10" << endl;
        cout << "Faltantes: PLZ=3, CAB=7, RET=5, CON=2, BOE=5" << endl;

        redistribucion->calcularEstacionesAVisitar(10, estaciones);

        break;
    }
    }
}
