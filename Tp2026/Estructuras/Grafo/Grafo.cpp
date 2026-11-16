#include "Grafo.h"
#include "Cola.h"
#include <iostream>

Grafo::Grafo(int capacidad) {
    this->capacidad = capacidad;
    this->cantidad = 0;
    codigos = new std::string[capacidad];
    matriz = new int*[capacidad];
    for (int i = 0; i < capacidad; i++) {
        matriz[i] = new int[capacidad];
        for (int j = 0; j < capacidad; j++) {
            matriz[i][j] = 0;
        }
    }
}

Grafo::~Grafo() {
    for (int i = 0; i < capacidad; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    delete[] codigos;
}

int Grafo::indiceDe(std::string codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (codigos[i] == codigo) {
            return i;
        }
    }
    return -1;
}

int Grafo::obtenerOCrearIndice(std::string codigo) {
    int i = indiceDe(codigo);
    if (i != -1) {
        return i;
    }
    if (cantidad == capacidad) {
        std::cout << "El grafo esta lleno, no se puede agregar " << codigo << std::endl;
        return -1;
    }
    codigos[cantidad] = codigo;
    cantidad++;
    return cantidad - 1;
}

void Grafo::agregarCiclovia(std::string estacionA, std::string estacionB) {
    int a = obtenerOCrearIndice(estacionA);
    int b = obtenerOCrearIndice(estacionB);
    if (a == -1 || b == -1) {
        return;
    }
    matriz[a][b] = 1;
    matriz[b][a] = 1;   // bidireccional
}

void Grafo::eliminarEstacion(std::string codigo) {
    int i = indiceDe(codigo);
    if (i == -1) {
        return;   // nunca tuvo ciclovías, no está en el grafo
    }
    for (int j = 0; j < cantidad; j++) {
        matriz[i][j] = 0;   // fila
        matriz[j][i] = 0;   // columna
    }
}

void Grafo::caminoMasCorto(std::string origen, std::string destino) {
    int o = indiceDe(origen);
    int d = indiceDe(destino);
    if (o == -1 || d == -1) {
        std::cout << "No existe recorrido entre " << origen << " y " << destino << std::endl;
        return;
    }

    bool* visitado = new bool[cantidad];
    int* padre = new int[cantidad];
    for (int i = 0; i < cantidad; i++) {
        visitado[i] = false;
        padre[i] = -1;
    }

    Cola cola;
    cola.encolar(o);
    visitado[o] = true;

    while (!cola.estaVacia()) {
        int u = cola.desencolar();
        if (u == d) {
            break;
        }
        for (int v = 0; v < cantidad; v++) {
            if (matriz[u][v] == 1 && !visitado[v]) {
                visitado[v] = true;
                padre[v] = u;
                cola.encolar(v);
            }
        }
    }

    if (!visitado[d]) {
        std::cout << "No existe recorrido entre " << origen << " y " << destino << std::endl;
    } else {
        int largo = 0;
        for (int x = d; x != -1; x = padre[x]) {
            largo++;
        }

        int* camino = new int[largo];
        int k = largo - 1;
        for (int x = d; x != -1; x = padre[x]) {
            camino[k] = x;
            k--;
        }

        std::cout << "Recorrido (" << largo - 1 << " tramos): ";
        for (int i = 0; i < largo; i++) {
            std::cout << codigos[camino[i]];
            if (i < largo - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;

        delete[] camino;
    }

    delete[] visitado;
    delete[] padre;
}