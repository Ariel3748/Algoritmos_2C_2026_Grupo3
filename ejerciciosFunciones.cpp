#include <iostream>
#include <string>
using namespace std;

//Ejercicio 24
bool tieneRaicesReales(double a, double b, double c) {
    double discriminante = (b * b) - (4 * a * c);
    return discriminante >= 0;
}
//Ejercicio25
//Ejercicio26

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

//Ejrcicio 18

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



int main(int argc, char const *argv[])
{
    
    return 0;
}
