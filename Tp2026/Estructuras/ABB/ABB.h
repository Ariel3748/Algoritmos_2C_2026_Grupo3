#ifndef ABB_H
#define ABB_H

// • Calcular la altura del árbol.
// • Liberar toda la memoria del árbol al finalizar el programa (recorrido postorder).

template <typename T> class NodoABB
{
  private:
    T valor;
    NodoABB<T>* hijoIzquierdo;
    NodoABB<T>* hijoDerecho;

  public:
    NodoABB(T valor) : valor(valor)
    {
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

    NodoABB<T>*& getHijoIzquierdo()
    {
        return hijoIzquierdo;
    }

    NodoABB<T>*& getHijoDerecho()
    {
        return hijoDerecho;
    }

    T& getValor()
    {
        return valor;
    }
};

template <typename T> class ABB
{
  private:
    NodoABB<T>* raiz;

  public:
    ABB()
    {
        raiz = nullptr;
    }

    NodoABB<T>*& getRaiz()
    {
        return raiz;
    }

    void insertarNodo(T valor, NodoABB<T>*& raiz)
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

    NodoABB<T>* buscarABB(T valor, NodoABB<T>* raiz)
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

    template <typename FuncionAplicada> void recorrer(NodoABB<T>* raiz, FuncionAplicada callback)
    {
        if (raiz != nullptr)
        {
            recorrer(raiz->getHijoIzquierdo(), callback);
            callback(raiz);
            recorrer(raiz->getHijoDerecho(), callback);
        }
    };
};

#endif