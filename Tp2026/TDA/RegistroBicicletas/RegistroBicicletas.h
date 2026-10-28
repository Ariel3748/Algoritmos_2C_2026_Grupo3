#include <Estructuras/ABB/ABB.h>
#include <Bicicleta.h>

class RegistroBicicletas{
    private:
       ABB<Bicicleta> arbol;
    
    public:
        NodoABB<Bicicleta>* buscarBicicleta(int biciId);
        void listarBicicletasEnOrden();
        int contarBicicletasAveriadas();
};