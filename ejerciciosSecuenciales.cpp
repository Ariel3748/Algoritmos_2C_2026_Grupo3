#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{

    //Ejercicio1
    /* int numeroIngresado;
    cout << "Ingrese un numero: ";
    cin >> numeroIngresado;
    cout << "El numero ingresado fue: " << numeroIngresado;  
    return 0; */

    //Ejercicio2
/*     int n1;
    int n2;
    cout << "Ingrese un numero: ";
    cin >> n1;
    cout << "ingrese otro numero: ";
    cin >> n2;
    cout << "Suma:" << n1 + n2 <<"\n" ;
    cout << "Resta:  " << n1 - n2<<"\n";
    cout << "Multiplicacion:  " << n1 * n2<<"\n";
    cout << "Division : " << n1 / n2<<"\n"; */

    //Ejercicio 3
/*     string name;

    cout <<"Ingrese el nombre";
    cin >> name;
    cout << "Hola,"<< name; */

    //Ejercicio 4
/*     const float PI = 3.14;
    float n;

    cout <<"Ingrese un nro";
    cin >> n;
    cout << "La superficie es: " << 4 * PI * n*n <<"\n";
    cout << "El volumen es:  " << 4.0/3.0 * PI * n*n*n <<"\n";    
    return 0; */

    //Ejercicio 5 
/*     int b;
    int h;
    cout << "Ingrese base" <<"\n";
    cin >> b;
    cout << "Ingrese altura: " << "\n";
    cin >> h;
    cout << "Perimetro:  " << 2 * (b+ h)<<"\n";
    cout << "Superficie:  " << b*h <<"\n"; */

    //Ejercicio 6 
/*     float n;
    cout << "Ingrese un nro:  ";
    cin >> n;
    if(n > 0){
        cout << "Tu nro es mayor a 0";
    }
    else if (n<0)
    {
        cout << "Tu nro es menor a 0";
    }
    else{
        cout << "Tu nro es 0";
    } */


    //Ejercicio 7 

/*     int n1;
    int n2;
    cout << "Ingrese un numero:  " <<"\n";
    cin >> n1;
    cout << "Ingrese otro numero:  " <<"\n";
    cin >> n2;
    if(n1>n2){
        cout << "El primero es mas grande";
    }
    else if (n2>n1)
    {
        cout << "El segundo es mas grande";
    }
    else{
        cout << "Son iguales chistoso";
    } */
    
    //Ejercicio 8
/*    int n;
    cout << "Ingrese un numero:  " <<"\n";
    cin >> n;
    if (n % 2 == 0) {
        cout << n << " es un numero par.\n";
    } else {
        cout << n << " es un numero impar.\n";
    } */

    //Ejercicio 9
/*     int n;
    int m;
    cout << "Ingrese un numero:  " <<"\n";
    cin >> n;
    cout << "Ingrese otro numero:  " <<"\n";
    cin >> m;
    if (n % m == 0) {
        cout << n << " es un numero divisible por " << m << "\n";
    } else {
        cout << n << " no es un numero divisible por " << m << "\n";
    }  */

    //Ejercicio 10
/* 
    char s;
    int n;
    int m;

    cout << "Ingrese un numero:  " <<"\n";
    cin >> n;
    cout << "Ingrese otro numero:  " <<"\n";
    cin >> m;
    cout << "Ingrese una opcion: \n   + : suma, – : resta, * : multiplicación o  / : división.  ";
    cin >> s;

    switch (s)
    {
    case '+':
        cout << "La suma dio: " << n + m;
        break;
    
    case '-':
        cout << "La resta dio: " << n - m;
        break;
    case '*':
        cout << "La multiplicacion dio: " << n * m;
        break;
    case '/':
        cout << "La division dio: " << n / m;
        break;        
    default:
        break;
    } */

    //Ejercicio 11
/*     int n;
    cout << "Ingrese un numero(1-4):  " <<"\n";
    cin >> n;

    switch (n)
    {
    case 1:
        cout << "Opcion 1";
        break;
    
    case 2:
        cout << "Opcion 2";
        break;
    case 3:
        cout << "Opcion 3";
        break;
    case 4:
        cout << "Opcion 4";
        break;       
    default:
       cout << "Opcion Incorrecta";
        break;
    }  */


    //Ejercicio 12

/*     int n;
    const float MINUTO = 60;
    const float HORA = 3600;
    const float DIA = 86400;

    float dias;
    float horas;
    float minutos;
    float segundos;
    int resto;
    cout << "Ingrese un numero expresado en segundos:  " <<"\n";
    cin >> n;

    dias = n / 86400;
    resto = n % 86400;

    horas = resto / 3600;
    resto = resto % 3600;

    minutos = resto / 60;
    segundos = resto % 60;
    cout << "En dias: " << dias <<"\n";
    cout << "En horas: " << horas <<"\n";
    cout << "En minutos: " << minutos <<"\n"; */

    //Creo que el ejercicio se refiere a que le pase nose 200.000 seg y me diga 2 dias, 3 horas, 5 minutos y 20 segundos
    //Tipo dividir por dias y el resto por horas y el resto por minutos y asi



    //Ejercicio 13
/*     int n;
    cout << "Ingrese un numero:  " <<"\n";
    cin >> n;

    for (int i = n; i < n + 20; i++)
    {
        cout << i <<"\n";
    } */
    

    //Ejercicio14
/*     int n;
    int aux = 1;
    cout << "Ingrese un numero:  " <<"\n";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        aux *= i;
    } 
    cout << "El factorial de " << n << " es: " << aux << "\n"; */
    
    //Ejercicio 15
/*     int n;
    
    int aux = 0;

    do
    {
        cout << "Ingrese un numero:  " <<"\n";
        cin >> n;
        cout << "Numero ingresado: " << n <<"\n";
        aux += n;
        cout << "Suma acumulada:  " <<aux <<"\n";
    } while (n!=0); */
    
    

    //Ejercicio 16
/*     int n;
    
    int max = 0;
    int min = 0;
    int i = 0;
    do
    {
        cout << "Ingrese un numero:  (Si ingresa 0 se corta)" <<"\n";
        cin >> n;
        
        i+=1;
        if(n>max){
            max = n;
        }
        if(min==0){
            min=n;
        }
        if(n<min){
            min = n;
        }


        cout << "Numero ingresado: " << n <<"\n";
        cout << "Posicion: " << i <<"\n";
        cout << "Numero max ingresado: " << max <<"\n";
        cout << "Numero min ingresado: " << min <<"\n";

        
    } while (n!=0); */


    //Ejercicio17
/*     int n;
    cout << "Ingrese la cantidad de n a cargar" << "\n";
    int mayor;
    int menor;
    int nMayor;
    int nMenor;
    for (int i = 0; i < n; i++)
    {
        int m;
        cout << "Ingrese el valor del numero" << "\n";
        cin >> m;
        if(i==0){
            mayor = m;
            menor = m;
            nMayor  ++;
            nMenor ++;
        }
        else if (m>mayor)
        {
            mayor = m;
            nMayor = 1;
        }
        else if (m<menor)
        {
            menor = m;
            nMenor = 1;
        }
        else if (m==mayor)
        {
            nMayor ++;
        }
        else if (m==menor)
        {
            nMenor ++;
        }
        
        
        
    }
     */

    //Ejercicio 18
/*     int n;
    int m;
    int aux = 0;
    cout << "Ingrese un numero:  " <<"\n";
    cin >> n;
    cout << "Ingrese otro numero:  " <<"\n";
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        aux += n;
    }
    cout << aux; */



    //Ejercicio19
/*     int n;
    int m1 = 0;
    int m2 = 0;
    int m3 = 0;
    do
    {
        cout << "Ingrese un numero:  (Si ingresa 0 se corta)" <<"\n";
        cin >> n;
        
        if (n > m1) {
            m3 = m2;
            m2 = m1;
            m1 = n;
        } else if (n > m2) {
            m3 = m2;
            m2 = n;
        } else if (n > m3) {
            m3 = n;
        }
        
    } while (n!=0);  
        cout << "Numero max ingresado: " << m1 <<"\n";
        cout << "Numero max2 ingresado: " << m2 <<"\n";
        cout << "Numero max3 ingresado: " << m3 <<"\n"; */

    //Ejercicio20

/*     string nombreMax, nombreMin, nombreAux;
    int sueldoMax= 0, sueldoMin = 0, sueldoAux = 0;

    do
    {
        cout << "Ingrese el nombre:  (Si ingresa N se corta)" <<"\n";
        cin >> nombreAux;
        cout << "Ingrese el sueldo:  " <<"\n";
        cin >> sueldoAux;
        
        if(sueldoMin == 0){
            nombreMin = nombreAux;
            sueldoMin = sueldoAux;
        }
        if(sueldoAux > sueldoMax){
            nombreMax = nombreAux;
            sueldoMax = sueldoAux;
        }
        if(sueldoAux < sueldoMin){
            nombreMin = nombreAux;
            sueldoMin = sueldoAux;
        }
        
    } while (nombreAux != "N") ; */

    //Ejercicio 21
    
//  int main() {
//   bool esDescendente = true;
//   bool esAscendente = true;

//   float numeroPrevio = 0;
//   float actual;

//   while (true) {
//     cout << "Ingrese numero (0 para terminar la serie): " << endl;
//     cin >> actual;

//     if (actual == 0) {
//       break;
//     }

//     if (numeroPrevio == 0) {
//       numeroPrevio = actual;
//       continue;
//     }

//     if (numeroPrevio > actual) {
//       esAscendente = false;
//     }

//     if (numeroPrevio < actual) {
//       esDescendente = false;
//     }

//     numeroPrevio = actual;
//   }

//   if (esAscendente) {
//     cout << "La serie es ascendente" << endl;
//   } else if (esDescendente) {
//     cout << "La serie es descendente" << endl;
//   } else {
//     cout << "La serie no tiene orden" << endl;
//   }

//   return 0;
// }



    //Ejercicio 22
/*     cout << "Fahrenheit\tCelsius\n";
    cout << "-----------------------\n";

    for (int f = 0; f <= 200; f += 10) {
        float c = (f - 32) * 5.0 / 9.0;
        cout << f << " F\t\t" << c << " C\n";
    } */

    //Ejercicio 23
/*     int n;
    cout << "Ingrese la cantidad de lotes (N): ";
    cin >> n;

    float sumaTotal = 0;
    int cantTotal = 0;

    for (int i = 1; i <= n; i++) {
        float num, sumaLote = 0;
        int cantLote = 0;

        cout << "\n--- Lote " << i << " (0 para terminar lote) ---\n";
        cin >> num;

        while (num != 0) {
            sumaLote += num;
            cantLote++;
            sumaTotal += num;
            cantTotal++;

            cin >> num;
        }

        if (cantLote > 0) {
            cout << "Media del lote " << i << ": " << sumaLote / cantLote << "\n";
        } else {
            cout << "Lote " << i << " vacio.\n";
        }
    }

    if (cantTotal > 0) {
        cout << "\nMedia total de todos los numeros: " << sumaTotal / cantTotal << "\n";
    } else {
        cout << "\nNo se ingresaron numeros validos en ningun lote.\n";
    } */

    return 0;
}

