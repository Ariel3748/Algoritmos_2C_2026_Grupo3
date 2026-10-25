#ifndef VIAJE_H
#define VIAJE_H

#include <string>

class Viaje {
private:
    int viajeId;
    int biciId;
    long dniUsuario;
    std::string estacionOrigen;
    std::string estacionDestino;
    int fecha;            // AAAAMMDD
    int duracionMin;

public:
    Viaje(int viajeId, int biciId, long dniUsuario, std::string estacionOrigen,
          std::string estacionDestino, int fecha, int duracionMin);

    int getViajeId();
    int getBiciId();
    long getDniUsuario();
    std::string getEstacionOrigen();
    std::string getEstacionDestino();
    int getFecha();
    int getDuracionMin();

    void mostrar();
};

#endif