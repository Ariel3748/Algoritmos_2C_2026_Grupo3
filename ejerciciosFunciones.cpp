#include <iostream>
#include <string>
#include <cmath>
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

// int main() {
//   int coefUno;
//   int coefDos;
//   int coefTres;

//   cout << "Ingrese primer coeficiente: " << endl;
//   cin >> coefUno;

//   cout << "Ingrese segundo coeficiente: " << endl;
//   cin >> coefDos;

//   cout << "Ingrese tercer coeficiente: " << endl;
//   cin >> coefTres;

//   if (tieneRaices(coefUno, coefDos, coefTres)) {
//     cout << "Tiene raices y son: " << endl;
//     float raices[2];
//     calculoRaicesReales(coefUno, coefDos, coefTres, raices);
//     cout << "Raiz 1: " << raices[0] << endl;
//     cout << "Raiz 2: " << raices[1] << endl;
//   } else {
//     cout << "No tiene raices" << endl;
//   }

//   return 0;
// }


//Ejercicio27 !PROBAR
bool esPrimo(int n){
    if (n <= 1) return false; 

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; 
        }
    }

    return true; 
} 

//Ejrcicio 28

int mcd(int n, int n2){
    while (n != 0) {
        int resto = n % n2;
        n = n2;
        n2 = resto;
    }
    return n;

}

int mcm(int n, int n2){
    if (n == 0 || n2 == 0) return 0;
    return (n / mcd(n, n2)) * n2;
}


//Ejercicio29
void primos(int array[]){
    
    int aux = 0;
    for (int i = 0; i <= 200; i++)
    {
        if(esPrimo(i)){
            array[aux] = i;
            aux ++;
        }

    }  
}


//Ejercicio 30

void vectorSuma(int array1[],int array2[],int arrayResultado[],int longitud){
    for (int i = 0; i < longitud -1; i++)
    {
        arrayResultado[i] = array1[i] + array2[i];
    }
    
}

int productoEscalar(int array1[],int array2[],int longitud){
    int res = 0;
    for (int i = 0; i < longitud; i++)
    {
        res += array1[i] * array2[i];
    }
    return res;
}


//Ejercicio 31 

int main(){
    int padron, nota;
    int cantidadDeAlumnos = 0;
    int notas[11] = {0};

    cout << "Ingrese el padron y la nota (padron 0 para finalizar): "<< "\n";
    cin >> padron;

    while (padron != 0){
        cout << "Ingresa la nota: " << "\n";
        cin >> nota;

        cantidadDeAlumnos++;
        notas[nota]++;

        cout << "Ingrese el proximo padron:" << "\n";
        cin >> padron;
    }

    cout << "Cantidad de alumnos: " << cantidadDeAlumnos << endl;

    for (int i = 0; i <= 10; i++){
        if (notas[i] > 0){
            cout << "Nota " << i << ": " << (notas[i] * 100.0 / cantidadDeAlumnos) << "%" << endl;
        }
    }
    return 0;
}


//Ejercicio 32 

bool estaRepetido(int arrayNuevo[], int n, int cantidadCargada) {
    for (int i = 0; i < cantidadCargada; i++) {
        if (arrayNuevo[i] == n) {
            return true;
        }
    }
    return false;
}


void eliminarRepetidos(int arrayOriginal[], int nuevoArray[], int longArray) {
    int pos = 0;

    for (int i = 0; i < longArray; i++) {
        if (!estaRepetido(nuevoArray, arrayOriginal[i], pos)) {
            nuevoArray[pos] = arrayOriginal[i];
            pos++;
        }
    }

}

//Ejercicio 33

void ordenarArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

void calcularInterseccion(int A[], int longA, int B[], int longB, int resultado[]) {
    // i -> A
    // j -> B
    // k -> Resultado
    int i = 0, j = 0, k = 0;
    while (i < longA && j < longB) {
        if (A[i] == B[j]) {

            if (k == 0 || resultado[k - 1] != A[i]) { //El segundo valor verifica que el elemento anterior del array sea igual a la igualdad de a y b (toma A porque si, ya que A[i] y B[j] son iguales) 
                resultado[k] = A[i];
                k++;
            }
            i++;
            j++;
        } else if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }
}



void calcularUnion(int A[], int n, int B[], int m, int resultado[]) {
    int i = 0, j = 0, k = 0;

    // 1. Recorrer en paralelo eligiendo siempre el menor
    while (i < n && j < m) {
        int valor;
        if (A[i] < B[j]) {
            valor = A[i];
            i++;
        } else if (B[j] < A[i]) {
            valor = B[j];
            j++;
        } else {
            valor = A[i];
            i++;
            j++;
        }

        if (k == 0 || resultado[k - 1] != valor) { //Verifica que valor sea distinto del anterior elemento del array
            resultado[k] = valor;
            k++;
        }
    }

    // 2. Si sobraron elementos en A, agregarlos
    while (i < n) {
        if (k == 0 || resultado[k - 1] != A[i]) {
            resultado[k] = A[i];
            k++;
        }
        i++;
    }

    // 3. Si sobraron elementos en B, agregarlos
    while (j < m) {
        if (k == 0 || resultado[k - 1] != B[j]) {
            resultado[k] = B[j];
            k++;
        }
        j++;
    }
}

//Ejercicio 34
const int MAX_FIL = 50;
const int MAX_COL = 50;

// La dimensión de columnas es obligatoria en la declaración de parámetros de matrices nativas
void sumarMatrices(int A[][MAX_COL], int B[][MAX_COL], int C[][MAX_COL], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void cargarMatriz(int matriz[][MAX_COL], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

//En el Main
/* int A[MAX_FIL][MAX_COL];
    int B[MAX_FIL][MAX_COL];
    int C[MAX_FIL][MAX_COL];
    int m, n;

    cout << "Ingrese cantidad de filas (M <= " << MAX_FIL << "): ";
    cin >> m;
    cout << "Ingrese cantidad de columnas (N <= " << MAX_COL << "): ";
    cin >> n;


    cargarMatriz(A, m, n);
    cargarMatriz(B, m, n);

    sumarMatrices(A, B, C, m, n) */


    //Ejercicio 35
    /*
    int main() {
    const int MAX = 10;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int M, N;

    cout << "Ingrese la cantidad de filas: ";
    cin >> M;

    cout << "Ingrese la cantidad de columnas: ";
    cin >> N;

    cout << "Ingrese los elementos de la matriz A:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Ingrese los elementos de la matriz B:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "La matriz C es:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/

//Ejercicio36
int sumarFilaIndividual(int fila[], int cantidadColumnas) {
    int sumador = 0;
    for (int j = 0; j < cantidadColumnas; j++) {
        sumador += fila[j];
    }
    return sumador;
}

// m: filas reales, n: columnas reales
void sumarFilas(int A[][MAX_COL], int C[], int m, int n) {
    for (int i = 0; i < m; i++) {
        C[i] = sumarFilaIndividual(A[i], n);
    }
}



//Ejrcicio 37
int sumarElementoDiagonal(int A[][MAX_COL], int m){
    int traza = 0;
    for (int i = 0; i < m; i++)
    {
        traza += A[i][i];

    }
    return traza;
}


//Ejercicio 38
bool esIdentidad(int A[][MAX_COL], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //Diagonal principal 
            if (i == j && A[i][j] != 1) {
                return false;
            }
            //Fuera de la diagonal
            if (i != j && A[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

//Ejercicio39

int minimoEnFila(int fila[], int largoFila){
    int aux;
    for (int i = 0; i < largoFila; i++)
    {
        if(i==0 || fila[i] < aux){
            aux = fila[i];
        }
    }
    return aux;
}

// m: filas reales, n: columnas reales
void vectorDeMenores(int matriz[][MAX_COL],int vector[], int largoVector, int m, int n){
    for (int i = 0; i < m; i++)
    {
        vector[i] = minimoEnFila(matriz[i],n);
    }

}




int main(int argc, char const *argv[])
{
    
    return 0;
}
