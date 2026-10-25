#ifndef NODOCOLA_H
#define NODOCOLA_H

class NodoCola {
private:
    int dato;
    NodoCola* siguiente;

public:
    NodoCola(int dato);

    int getDato();
    NodoCola* getSiguiente();
    void setSiguiente(NodoCola* siguiente);
};

#endif