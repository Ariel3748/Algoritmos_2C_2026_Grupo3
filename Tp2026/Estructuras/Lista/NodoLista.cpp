#include "NodoLista.h"

template <typename T> NodoLista<T>::NodoLista(T elemento)
{
    this->elemento = elemento;
    this->siguiente = nullptr;
}

template <typename T> T NodoLista<T>::getElemento()
{
    return elemento;
}

template <typename T> NodoLista<T>* NodoLista<T>::getSiguiente()
{
    return siguiente;
}

template <typename T> void NodoLista<T>::setSiguiente(NodoLista* siguiente)
{
    this->siguiente = siguiente;
}