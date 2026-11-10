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
    NodoABB(T valor);

    void setHijoIzquierdo(NodoABB<T>* hijoIzquierdo);

    void setHijoDerecho(NodoABB<T>* hijoDerecho);

    NodoABB<T>*& getHijoIzquierdo();

    NodoABB<T>*& getHijoDerecho();

    T& getValor();
};

template <typename T> class ABB
{
  private:
    NodoABB<T>* raiz;

    void liberarMemoria(NodoABB<T>*& nodo);

  public:
    ABB();

    ~ABB();

    NodoABB<T>*& getRaiz();

    int getAlturaArbol(NodoABB<T>* nodo);

    void insertarNodo(T valor, NodoABB<T>*& raiz);

    NodoABB<T>* buscarABB(T valor, NodoABB<T>* raiz);

    template <typename FuncionAplicada> void recorrer(NodoABB<T>* raiz, FuncionAplicada callback);
};

#endif
