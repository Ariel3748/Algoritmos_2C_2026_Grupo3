#include <iostream>
using namespace std;

int main() {
  bool esDescendente = true;
  bool esAscendente = true;

  float numeroPrevio = 0;
  float actual;

  while (true) {
    cout << "Ingrese numero (0 para terminar la serie): " << endl;
    cin >> actual;

    if (actual == 0) {
      break;
    }

    if (numeroPrevio == 0) {
      numeroPrevio = actual;
      continue;
    }

    if (numeroPrevio > actual) {
      esAscendente = false;
    }

    if (numeroPrevio < actual) {
      esDescendente = false;
    }

    numeroPrevio = actual;
  }

  if (esAscendente) {
    cout << "La serie es ascendente" << endl;
  } else if (esDescendente) {
    cout << "La serie es descendente" << endl;
  } else {
    cout << "La serie no tiene orden" << endl;
  }

  return 0;
}
