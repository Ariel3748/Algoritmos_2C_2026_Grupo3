#include <cmath>
#include <iostream>
using namespace std;

/*
 *
 24) Hacer una función que, dado los coeficientes de un polinomio de segundo
grado (3 números reales), indique si tiene o no raíces reales, devolviendo un
valor booleano.

25) Hacer una función que devuelva las raíces reales de un polinomio de segundo
grado y además indique si tiene o no raíces reales. Nota: utilizar la función
realizada en el ejercicio 39. Si no tuviera raíces reales, devolverá 0 en ambas.

26) Hacer un programa principal en donde se pida al usuario ingresar los
coeficientes de la cuadrática, e indicar si tiene o no raíces, y cuáles son en
caso de tener, utilizando la función definida.

*/

bool tieneRaices(float coefUno, float coefDos, float coefTres) {
  return ((coefDos * coefDos) - (4 * coefUno * coefTres)) >= 0;
}

void calculoRaicesReales(float a, float b, float c, float raices[2]) {
  raices[0] = 0;
  raices[1] = 0;

  if (!tieneRaices(a, b, c)) {
    return;
  }

  float calc = sqrt((b * b) - (4 * a * c));
  raices[0] = ((b * -1) + calc) / (2 * a);
  raices[1] = ((b * -1) - calc) / (2 * a);
}

int main() {
  int coefUno;
  int coefDos;
  int coefTres;

  cout << "Ingrese primer coeficiente: " << endl;
  cin >> coefUno;

  cout << "Ingrese segundo coeficiente: " << endl;
  cin >> coefDos;

  cout << "Ingrese tercer coeficiente: " << endl;
  cin >> coefTres;

  if (tieneRaices(coefUno, coefDos, coefTres)) {
    cout << "Tiene raices y son: " << endl;
    float raices[2];
    calculoRaicesReales(coefUno, coefDos, coefTres, raices);
    cout << "Raiz 1: " << raices[0] << endl;
    cout << "Raiz 2: " << raices[1] << endl;
  } else {
    cout << "No tiene raices" << endl;
  }

  return 0;
}
