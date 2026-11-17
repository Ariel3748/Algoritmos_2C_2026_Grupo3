#ifndef REGISTROBICICLETAS_H
#define REGISTROBICICLETAS_H

#include <Estructuras/ABB/ABB.h>
#include "TDA/Bicicleta/Bicicleta.h"

class RegistroBicicletas{
    private:
       ABB<Bicicleta> arbol;
    
    public:
        Bicicleta* buscarBicicleta(int biciId);
        void listarBicicletasEnOrden();
        int contarBicicletasAveriadas();
        void agregarBicicleta(Bicicleta bicicleta);
        void listarBicicletasSegunKilometros(int kilometros);
        int getAlturaArbol();

};

#endif