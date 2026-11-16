#ifndef GRAFO_H
#define GRAFO_H

#include <string>

class Grafo {
private:
    std::string* codigos;   // codigos[i] = código de la estación del vértice i
    int** matriz;           // matriz[i][j] == 1 si hay ciclovía entre i y j
    int cantidad;           // vértices registrados hasta ahora
    int capacidad;          // máximo de vértices (tamaño de la matriz)

    int indiceDe(std::string codigo);               // -1 si no está
    int obtenerOCrearIndice(std::string codigo);    // lo registra si es nuevo

public:
    Grafo(int capacidad);
    ~Grafo();

    void agregarCiclovia(std::string estacionA, std::string estacionB);
    void eliminarEstacion(std::string codigo);
    void caminoMasCorto(std::string origen, std::string destino);
};

#endif