using namespace std;

/*
32) Se carga un vector X de N elementos enteros. Escribir un algoritmo que
devuelva un vector que tenga todos los elementos de X, pero sin elementos
repetidos.
*/

bool vectorPoseeNumero(int vec[], int tam, int numero) {
  for (int i = 0; i < tam; i++) {
    if (vec[i] == numero) {
      return true;
    }
  }
  return false;
}

int sinRepetidos(int inicial[], int n, int resultado[]) {
  int tamResultado = 0;
  for (int i = 0; i < n; i++) {
    if (vectorPoseeNumero(resultado, tamResultado, inicial[i])) {
      continue;
    } else {
      resultado[tamResultado] = inicial[i];
      tamResultado++;
    }
  }
  return tamResultado;
}
