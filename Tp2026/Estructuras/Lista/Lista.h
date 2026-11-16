#ifndef LISTA_H
#define LISTA_H
#include <NodoLista.h>

template <typename T>
class Lista {
private:
    NodoLista<T>* primero;
    int cantidad;

public:
    Lista();
    ~Lista();

    void agregar(T elemento);
    NodoLista<T>* getPrimero();
    int getCantidad();
    bool estaVacia();
    void eliminarPrimero();
};

#include "Lista.cpp"
#endif