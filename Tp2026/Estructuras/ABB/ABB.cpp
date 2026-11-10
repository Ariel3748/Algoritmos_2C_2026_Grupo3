#ifndef ABB_CPP
#define ABB_CPP

#include "ABB.h"

template <typename T>
NodoABB<T>::NodoABB(T valor) : valor(valor)
{
    hijoIzquierdo = nullptr;
    hijoDerecho = nullptr;
}

template <typename T>
void NodoABB<T>::setHijoIzquierdo(NodoABB<T>* hijoIzquierdo)
{
    this->hijoIzquierdo = hijoIzquierdo;
}

template <typename T>
void NodoABB<T>::setHijoDerecho(NodoABB<T>* hijoDerecho)
{
    this->hijoDerecho = hijoDerecho;
}

template <typename T>
NodoABB<T>*& NodoABB<T>::getHijoIzquierdo()
{
    return hijoIzquierdo;
}

template <typename T>
NodoABB<T>*& NodoABB<T>::getHijoDerecho()
{
    return hijoDerecho;
}

template <typename T>
T& NodoABB<T>::getValor()
{
    return valor;
}

template <typename T>
void ABB<T>::liberarMemoria(NodoABB<T>*& nodo)
{
    if (nodo == nullptr)
    {
        return;
    }

    liberarMemoria(nodo->getHijoIzquierdo());
    liberarMemoria(nodo->getHijoDerecho());

    delete nodo;
    nodo = nullptr;
}

template <typename T>
ABB<T>::ABB()
{
    raiz = nullptr;
}

template <typename T>
ABB<T>::~ABB()
{
    liberarMemoria(raiz);
}

template <typename T>
NodoABB<T>*& ABB<T>::getRaiz()
{
    return raiz;
}

template <typename T>
int ABB<T>::getAlturaArbol(NodoABB<T>* nodo)
{

    if (nodo == nullptr)
    {
        return -1;
    };

    int izq = getAlturaArbol(nodo->getHijoIzquierdo());
    int der = getAlturaArbol(nodo->getHijoDerecho());
    int max = (izq > der) ? izq : der;

    return 1 + max;
}

template <typename T>
void ABB<T>::insertarNodo(T valor, NodoABB<T>*& raiz)
{

    if (raiz == nullptr)
    {
        raiz = new NodoABB<T>(valor);
        return;
    }

    if (valor < raiz->getValor())
    {
        insertarNodo(valor, raiz->getHijoIzquierdo());
    }
    else
    {
        insertarNodo(valor, raiz->getHijoDerecho());
    };
}

template <typename T>
NodoABB<T>* ABB<T>::buscarABB(T valor, NodoABB<T>* raiz)
{
    if (raiz == nullptr || raiz->getValor() == valor)
    {
        return raiz;
    }

    if (valor < raiz->getValor())
    {
        return buscarABB(valor, raiz->getHijoIzquierdo());
    }
    else
    {
        return buscarABB(valor, raiz->getHijoDerecho());
    }
}

template <typename T>
template <typename FuncionAplicada>
void ABB<T>::recorrer(NodoABB<T>* raiz, FuncionAplicada callback)
{
    if (raiz != nullptr)
    {
        recorrer(raiz->getHijoIzquierdo(), callback);
        callback(raiz);
        recorrer(raiz->getHijoDerecho(), callback);
    }
};

#endif
