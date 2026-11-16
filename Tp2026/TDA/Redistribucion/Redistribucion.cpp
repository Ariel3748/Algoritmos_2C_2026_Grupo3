#include <iostream>
using namespace std;
#include <Redistribucion.h>

void Redistribucion::backtracking(NodoLista<Estacion*>* inicio, Lista<Estacion*>& seleccionadas, int capacidadCamion,
                                  int sumaActual, bool& haySolucion)
{

    if (sumaActual == capacidadCamion)
    {
        haySolucion = true;

        cout << "{ ";
        NodoLista<Estacion*>* actual = seleccionadas.getPrimero();
        while (actual != nullptr)
        {
            cout << actual->getElemento()->getNombre();
            if (actual->getSiguiente() != nullptr)
            {
                cout << ", ";
            }
            actual = actual->getSiguiente();
        }
        cout << " }" << endl;
        return;
    }

    if (sumaActual > capacidadCamion)
    {
        return;
    }

    NodoLista<Estacion*>* actual = inicio;
    while (actual != nullptr)
    {
        Estacion* estacion = actual->getElemento();
        int faltantes = estacion->getCapacidadAnclajes() - estacion->getBicisDisponibles();
        seleccionadas.agregar(estacion);
        backtracking(actual->getSiguiente(), seleccionadas, capacidadCamion, sumaActual + faltantes, haySolucion);
        seleccionadas.eliminarPrimero();
        actual = actual->getSiguiente();
    }
};

void Redistribucion::calcularEstacionesAVisitar(int capacidad, Lista<Estacion*>& estaciones)
{
    bool haySolucion = false;
    Lista<Estacion*> seleccionadas;

    backtracking(estaciones.getPrimero(), seleccionadas, capacidad, 0, haySolucion);

    if (!haySolucion)
    {
        cout << "No hay solucion posible" << endl;
    }
};