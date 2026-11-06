#ifndef TALLER_H
#define TALLER_H

#include "Bicicleta.h"   

class Taller {
private:
    Bicicleta** bicis;   // arreglo dinámico de punteros a Bicicleta
    int cantidad;
    int capacidad;

    void agrandar();
    void intercambiar(int i, int j);
    void subir(int i);
    void bajar(int i);

public:
    Taller();
    ~Taller();

    void insertar(Bicicleta* bici, int prioridad);
    Bicicleta* extraerMasUrgente();
    bool estaVacio();
    int getCantidad();
};

#endif