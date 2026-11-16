#include <Lista.h>

template <typename T> Lista<T>::Lista()
{
    primero = nullptr;
    cantidad = 0;
};

template <typename T> Lista<T>::~Lista()
{
    NodoLista<T>* actual = primero;
    while (actual != nullptr)
    {
        NodoLista<T>* aBorrar = actual;
        actual = actual->getSiguiente();
        delete aBorrar;
    }
}

template <typename T> void Lista<T>::agregar(T elemento)
{
    NodoLista<T>* nuevo = new NodoLista<T>(elemento);
    nuevo->setSiguiente(primero);
    primero = nuevo;
    cantidad++;
}

template <typename T> NodoLista<T>* Lista<T>::getPrimero()
{
    return primero;
}

template <typename T> int Lista<T>::getCantidad()
{
    return cantidad;
}

template <typename T> bool Lista<T>::estaVacia()
{
    return primero == nullptr;
}

template <typename T> void Lista<T>::eliminarPrimero()
{
    if (primero == nullptr)
    {
        return;
    }

    NodoLista<T>* aBorrar = primero;
    primero = primero->getSiguiente();

    delete aBorrar;
    this->cantidad = cantidad - 1;
};
