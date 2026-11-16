#ifndef NODOLISTA_H
#define NODOLISTA_H

template <typename T> class NodoLista
{
  private:
    T elemento;
    NodoLista* siguiente;

  public:
    NodoLista(T elemento);

    T getElemento();
    NodoLista* getSiguiente();
    void setSiguiente(NodoLista* siguiente);
};

#include "NodoLista.cpp"
#endif