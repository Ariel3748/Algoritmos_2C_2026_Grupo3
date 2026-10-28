#include <RegistroBicicletas.h>

Bicicleta* RegistroBicicletas::buscarBicicleta(int biciId)
{

    Bicicleta auxiliar = Bicicleta(biciId, "PLZ", "Mecanica", "OK", 1240);
    NodoABB<Bicicleta>* nodo = arbol.buscarABB(auxiliar, arbol.getRaiz());
    return &nodo->getValor();
}

void RegistroBicicletas::listarBicicletasEnOrden()
{
    auto listar = [](NodoABB<Bicicleta>* NodoBicicleta) {
        Bicicleta aux = NodoBicicleta->getValor();
        aux.mostrar();
    };

    arbol.recorrer(arbol.getRaiz(), listar);
}

int RegistroBicicletas::contarBicicletasAveriadas()
{
    int contador = 0;

    auto sumador = [&contador](NodoABB<Bicicleta>* NodoBicicleta) {
        Bicicleta aux = NodoBicicleta->getValor();
        if (aux.estaAveriada())
        {
            contador = contador + 1;
        }
    };

    arbol.recorrer(arbol.getRaiz(), sumador);

    return contador;
}

void RegistroBicicletas::agregarBicicleta(Bicicleta bicicleta)
{
    arbol.insertarNodo(bicicleta, arbol.getRaiz());
}
