#ifndef ABB_H
#define ABB_H


// • Calcular la altura del árbol.
// • Liberar toda la memoria del árbol al finalizar el programa (recorrido postorder).

template <typename T> class NodoABB
{
  private:
    T dato;
    NodoABB<T>* hijoIzquierdo;
    NodoABB<T>* hijoDerecho;

  public:
    NodoABB(T dato)
    {
        this->dato = dato;
        hijoIzquierdo = nullptr;
        hijoDerecho = nullptr;
    }

    void setHijoIzquierdo(NodoABB<T>* hijoIzquierdo)
    {
        this->hijoIzquierdo = hijoIzquierdo;
    }

    void setHijoDerecho(NodoABB<T>* hijoDerecho)
    {
        this->hijoDerecho = hijoDerecho;
    }

    NodoABB*& getHijoIzquierdo()
    {
        return this->hijoIzquierdo;
    }

    NodoABB*& getHijoDerecho()
    {
        return this->hijoDerecho;
    }

    T& getDato(){
        return this->dato;
    }
};

template <typename T> class ABB
{
  private:
    NodoABB<T>* raiz;

  public:
    ABB(T dato)
    {
        raiz = new NodoABB<T>(dato);
    }

    NodoABB*& getRaiz(){
        return this->raiz;
    }
    
    void insertarNodo(T dato, NodoABB<T>*& raiz)
    {

        if (raiz == nullptr)
        {
            raiz = new NodoABB(dato);
            return;
        }

        if (dato < raiz->getDato())
        {
            insertarNodo(dato, raiz->getHijoIzquierdo());
        }
        else
        {
            insertarNodo(dato, raiz->getHijoDerecha());
        };
    }

    NodoABB<T>* buscarABB(T dato, NodoABB<T>* raiz)
    {
        // Encontramos el valor o llegamos al final sin valor.
        if (raiz == nullptr || raiz->getDato() == dato)
        {
            return raiz;
        }

        // Seguimos recorrido arbol.
        if (dato < raiz->getDato())
        {
            return buscarABB(dato, raiz->getHijoIzquierdo());
        }
        else
        {
            return buscarABB(dato, raiz->getHijoDerecho());
        }
    }

    template <typename FuncionAplicada>
    void recorrer(NodoABB<T>* raiz, FuncionAplicada callback){
        if(raiz != nullptr){
            recorrer(raiz->getHijoIzquierdo(), callback);
            callback(raiz);
            recorrer(raiz->getHijoDerecho(), callback);
        }
    };
};

#endif