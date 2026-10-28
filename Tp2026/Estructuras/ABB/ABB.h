#ifndef ABB_H
#define ABB_H


// • Insertar una bicicleta en el árbol. -> Hecho (No Testeado)
// • Buscar una bicicleta por ID y mostrar sus datos.
// • Listar todas las bicicletas ordenadas por ID (recorrido inorder).
// • Contar cuántas bicicletas averiadas hay, recorriendo el árbol.
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

    NodoABB* getHijoIzquierdo(){
        return this->hijoIzquierdo;
    }

    NodoABB* getHijoDerecho(){
        return this->hijoDerecho;
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

    void insertarNodo(T dato, NodoABB<T>*& raiz){

        if(raiz == nullptr){
            raiz = new NodoABB(dato);
            return;
        }

        if(dato < raiz->dato){
            insertarNodo(T dato, raiz->getHijoIzquierdo());
        } else {
            insertarNodo(T dato, raiz->getHijoDerecha());
        };


    }
};

#endif