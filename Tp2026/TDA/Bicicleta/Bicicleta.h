#ifndef BICICLETA_H
#define BICICLETA_H

#include <string>

class Bicicleta {
private:
    int biciId;
    std::string codigoEstacion;
    std::string tipo;     // "Mecanica" o "Electrica"
    std::string estado;   // "OK" o "Averiada"
    int kilometros;

public:
    Bicicleta(int biciId, std::string codigoEstacion, std::string tipo,
              std::string estado, int kilometros);

    int getBiciId();
    std::string getCodigoEstacion();
    std::string getTipo();
    std::string getEstado();
    int getKilometros();

    void setCodigoEstacion(std::string codigoEstacion);
    void setEstado(std::string estado);
    void setKilometros(int kilometros);

    bool estaAveriada();
    bool esElectrica();
    void mostrar();

    bool operator<(Bicicleta& b);
    bool operator==(Bicicleta& b);
    
};

#endif