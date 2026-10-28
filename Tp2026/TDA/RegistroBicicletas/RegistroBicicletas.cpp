#include <RegistroBicicletas.h>

class RegistroBicicletas
{
  private:
    ABB<Bicicleta> arbol;

  public:
    NodoABB<Bicicleta>* buscarBicicleta(int biciId)
    {

        Bicicleta auxiliar = Bicicleta(biciId, "PLZ", "Mecanica", "OK", 1240);
        return arbol.buscarABB(auxiliar, arbol.getRaiz());
    }

    void listarBicicletasEnOrden()
    {
        auto listar = [](NodoABB<Bicicleta>* NodoBicicleta) {
            Bicicleta aux = NodoBicicleta->getDato();
            aux.mostrar();
        };

        arbol.recorrer(arbol.getRaiz(), listar);
    }

    int contarBicicletasAveriadas()
    {
        int contador = 0;

        auto sumador = [&contador](NodoABB<Bicicleta>* NodoBicicleta) {
            Bicicleta aux = NodoBicicleta->getDato();
            if (aux.estaAveriada())
            {
                contador = contador + 1;
            }
        };

        arbol.recorrer(arbol.getRaiz(), sumador);
    }
};