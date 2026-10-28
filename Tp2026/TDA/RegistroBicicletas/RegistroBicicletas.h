#include <Estructuras/ABB/ABB.h>
#include <Bicicleta.h>

class RegistroBicicletas{
    private:
       ABB<Bicicleta> arbol;
    
    public:
        Bicicleta* buscarBicicleta(int biciId);
        void listarBicicletasEnOrden();
        int contarBicicletasAveriadas();
        void agregarBicicleta(Bicicleta bicicleta);

};